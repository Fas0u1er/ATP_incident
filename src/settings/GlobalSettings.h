#pragma once
#include <vector>
#include "PlayerSettings.h"
#include "src/ship/Ship.h"

class GlobalSettings {
public:
    int boardWidth = 8;
    int boardHeight = 8;
    int shipsNumber = 6;
    std::vector<int> shipSize = {1, 2, 3, 3, 3, 2};
    std::vector<Ship::Type> shipTypes = {Ship::Type::line,
                                         Ship::Type::line,
                                         Ship::Type::line,
                                         Ship::Type::cross,
                                         Ship::Type::T,
                                         Ship::Type::square};


    int playerNumber = 2;
    std::vector<PlayerSettings> playerSettings = vector<PlayerSettings> (2);

    static GlobalSettings& getInstance() {
        static GlobalSettings obj;
        return obj;
    }

private:
    GlobalSettings(): playerSettings(2) {}
};

