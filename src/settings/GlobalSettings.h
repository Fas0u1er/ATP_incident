#pragma once
#include <vector>
#include <cassert>

#include "PlayerSettings.h"
#include "src/ship/Ship.h"

class GlobalSettings {
public:
    int boardWidth = 8;
    int boardHeight = 8;
    int shipsNumber = 2;
    std::vector<int> shipSize = {
        1,
//        1,
//        1,
//        1,
        4
    };
    std::vector<Ship::Type> shipTypes = {
        Ship::Type::line,
//        Ship::Type::line,
//        Ship::Type::line,
//        Ship::Type::line,
//        Ship::Type::line,
      Ship::Type::square
    };

    int playerNumber = 2;
    std::vector<PlayerSettings> playerSettings;

    static GlobalSettings& getInstance() {
        static GlobalSettings obj;
        return obj;
    }

private:
    GlobalSettings() : playerSettings(playerNumber) {
        assert(shipSize.size() == shipsNumber);
        assert(shipTypes.size() == shipsNumber);
        for (int i = 0; i < playerNumber; ++i) {
            playerSettings[i].name = "Placeholder name #" + std::to_string(i + 1);
        }
    }
};

