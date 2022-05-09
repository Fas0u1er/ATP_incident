#include <iostream>
#include "GameMaster.h"
#include "src/settings/GlobalSettings.h"
#include "src/player/Player.h"
#include "src/player/PlayerFactory.h"
#include "src/menu_displayer/MenuDisplayer.h"
#include "src/GUI/GUI.h"
#include "src/player/bot/Bot.h"
#include "src/player/HumanPlayer.h"

GameMaster::GameMaster(GUI& gui) : gui(gui), players(GlobalSettings::getInstance().playerNumber), roundsPlayed(0) {}

void GameMaster::initializePlayers() {
    auto& globalSettings = GlobalSettings::getInstance();
    auto playerFactory = PlayerFactory();
    for (int i = 0; i < globalSettings.playerNumber; ++i)
        players[i] = playerFactory.constructPlayer(globalSettings.playerSettings[i].type, &gui);
    //TODO: Maybe tell the user when bot fills his board, so you can decide if he is stuck?
}

void GameMaster::openMenu() {
    MenuDisplayer(gui).startingMenu();
    initializePlayers();
    runBattle();
    showResults();
}

void GameMaster::runBattle() {
    while (true) {
        int aliveCount = 0;
        for (auto player: players) {
            if (player->isAlive())
                ++aliveCount;
        }
        if (aliveCount <= 1)
            break;

        for (int attacker = 0; attacker < players.size(); ++attacker) {
            if (!players[attacker]->isAlive())
                continue;

            int humanCount = 0;
            for (auto& player: players) {
                if (dynamic_cast <HumanPlayer*> (player)) {
                    ++humanCount;
                }
            }

            if (dynamic_cast <HumanPlayer*> (players[attacker]) && humanCount > 1) {
                gui.waitForNextPlayer(*players[attacker]);
            }

            bool canAttackAgain = true;
            while (canAttackAgain) {
                int toAttack = nextAlivePlayer(attacker);
                if (toAttack == -1)
                    return;
                canAttackAgain = players[attacker]->attack(players[toAttack]);
            }
        }

        ++roundsPlayed;
    }
}

void GameMaster::showResults() {
    for (auto playerPtr: players) {
        if (playerPtr->isAlive()) {
            gui.showResults(*playerPtr, roundsPlayed);
            gui.finishWork();
            return;
        }
    }

}
int GameMaster::nextAlivePlayer(int current) {
    for (int alive = (current + 1) % players.size(); alive != current; alive = (alive + 1) % players.size()) {
        if (players[alive]->isAlive())
            return alive;
    }
    return -1;
}
