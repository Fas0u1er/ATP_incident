#include "GameMaster.h"

void GameMaster::menu() {
    /*
     * Options:
     * Play
     * Settings
     * Exit
     */
    int choice = gui.displayOptions({"Play", "Settings", "Exit"});
    switch (choice) {
        case 0: menu_Play(); break;
        case 1: menu_Settings(); break;
        case 2: menu_Exit(); break;
    }
}


void GameMaster::menu_Play() {
    players.reserve(Global_Settings::getInstance().playerSettings.size());
    int i = 0;
    for (auto &el : players) {
        el = std::make_unique <ConsolePlayer> (i++);
    }
    for (auto &player : players) {
        player->fillBoard(gui);
    }

    while (countPlayers() > 1) {
        for (auto &player : players)
            if (!player.dead())
                player->attack(gui);
    }
}
void GameMaster::menu_Settings() {
    exit(0);
}
void GameMaster::menu_Exit() {
    exit(0);
}
void GameMaster::play_FillBoards() {

}
void GameMaster::play_DoTurns() {

}
int GameMaster::countPlayers() {

}

GameMaster::GameMaster(GUI_Interface& gui) : players(), gui(gui) {}

void GameMaster::run() {
}


void GameMaster::play_SetPlayers() {

}
