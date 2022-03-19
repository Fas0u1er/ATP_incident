#pragma once
#include <vector>

using std::vector;

struct Player_Settings {
    int shipsNumber = 6;
    vector<int> shipSize = {1, 1, 2, 2, 3, 4};
    int boardWidth = 8;
    int boardHeight = 8;
};

