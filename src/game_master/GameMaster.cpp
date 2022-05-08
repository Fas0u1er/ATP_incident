#include <iostream>
#include "GameMaster.h"
#include "src/settings/GlobalSettings.h"
#include "src/player/Player.h"
#include "src/player/PlayerFactory.h"
#include "src/menu_displayer/MenuDisplayer.h"
#include "src/GUI/GUI.h"

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
        int isAliveCnt = 0;
        for (auto player : players) {
            if (player->isAlive())
                ++isAliveCnt;
        }
        if (isAliveCnt <= 1)
            break;

        for (int attacker = 0; attacker < players.size(); ++attacker) {
            if (!players[attacker]->isAlive())
                continue;
            bool canAttackAgain = true;
            while (canAttackAgain) {
                canAttackAgain = false;
                for (int toAttack = (attacker + 1) % players.size(); toAttack != attacker;
                     toAttack = (toAttack + 1) % players.size()) {
                    if (!players[toAttack]->isAlive()) continue;

                    canAttackAgain = players[attacker]->attack(players[toAttack]);
                    break;
                }
            }
        }

        ++roundsPlayed;
    }
}

void GameMaster::showResults() {
    for (auto playerPtr : players) {
        if (playerPtr->isAlive()) {
            gui.showResults(*playerPtr, roundsPlayed);
            gui.finishWork();
            return;
        }
    }

}
