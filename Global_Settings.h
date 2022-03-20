#pragma once
#include <vector>
#include "Player_Settings.h"

using std::vector;

struct Global_Settings {
    int boardWidth = 8;
    int boardHeight = 8;
    int shipsNumber = 6;
    vector<int> shipSize = {1, 1, 2, 2, 3, 4};

    vector<Player_Settings> playerSettings = vector<Player_Settings> (2);

    static Global_Settings& getInstance() {
        static Global_Settings obj;
        return obj;
    }

private:
    Global_Settings(): playerSettings(2) {}
};

