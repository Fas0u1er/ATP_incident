#include "GameMaster.h"

GameMaster::GameMaster(GUIInterface& gui) : players(), gui(gui) {}

void GameMaster::run() {
    //
}

void GameMaster::openMenu() {

}

void GameMaster::runBattle() {
    for (int i = 0; i < GlobalSettings::getInstance().playerNumber; ++i) {
        if(GlobalSettings::getInstance().playerSettings[i].type == PlayerSettings::Type::human) {
            auto player = ConsolePlayer(i, &gui);
            players.push_back(static_cast<Player*>(&player));

            player.fillBoard();
        }
    }

    while(true) {
        int isAliveCnt = 0;
        for(auto& player: players) {
            if(player->isAlive())
                ++isAliveCnt;
        }
        if(isAliveCnt <= 1)
            break;

        for(auto& player: players) {
            player->attack(std::prev(player));
        }
    }
}