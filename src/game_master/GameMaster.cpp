#include <iostream>
#include "GameMaster.h"
#include "src/settings/GlobalSettings.h"
#include "src/player/Player.h"
#include "src/player/PlayerFactory.h"
#include "src/menu_displayer/MenuDisplayer.h"
#include "src/GUI/GUIInterface.h"

GameMaster::GameMaster(GUIInterface& gui) : gui(gui), players(GlobalSettings::getInstance().playerNumber) {}

void GameMaster::initializePlayers() {
    auto globalSettings = GlobalSettings::getInstance();
    auto playerFactory = PlayerFactory();
    for (int i = 0; i < globalSettings.playerNumber; ++i)
        players[i] = playerFactory.constructPlayer(globalSettings.playerSettings[i].type, &gui);
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
        for (auto player: players) {
            if (player->isAlive())
                ++isAliveCnt;
        }
        if (isAliveCnt <= 1)
            break;
        for (int attacker = 0; attacker < players.size(); ++attacker) {
            if (!players[attacker]->isAlive())
                continue;
            bool canAttack = true;
            while (canAttack) {
                canAttack = false;
                for (int toAttack = 0; toAttack < players.size(); ++toAttack) {
                    if (toAttack == attacker || !players[toAttack]->isAlive()) continue;
                    canAttack = players[attacker]->attack(players[toAttack]);
                    break;
                    //Todo: arbitrary attack order
                }
            }
        }
    }
}
void GameMaster::showResults() {
    gui.clearScreen();
    std::cout << "Showing results" << std::endl;
    system("pause");
    //TODO
}
