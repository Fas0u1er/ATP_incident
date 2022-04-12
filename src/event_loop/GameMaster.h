#pragma once

#include "src/player/Player.h"
#include "src/GUI/GUIInterface.h"
#include "src/player/ConsolePlayer.h"

#include <vector>

using std::vector;

class GameMaster {
    vector<Player*> players;
    GUIInterface& gui;
public:
    explicit GameMaster(GUIInterface& gui);
    void run();

private:
    void openMenu();

    void runBattle();
};
