#pragma once
#include <vector>
#include <unordered_map>
#include <cassert>
#include <iostream>

#include "PlayerSettings.h"
#include "src/ship/SimpleShip.h"

class GlobalSettings {
public:
    int boardWidth = 15;
    int boardHeight = 10;
    bool haveIsland = true;
    int islandSize = 13;

    int shipsNumber = 5;
    std::unordered_map<Ship::Type, std::vector <int>> ships = {
            {Ship::Type::line, {1, 2, 4}},
            {Ship::Type::square, {2}},
            {Ship::Type::T, {1}}
    };
    int playerNumber = 2;
    std::vector<PlayerSettings> playerSettings{{"Human", PlayerSettings::Type::Human},
                                               {"God Bot", PlayerSettings::Type::GodBot}};

    static GlobalSettings& getInstance();

    void resize(int newPlayerNumber);
    GlobalSettings(const GlobalSettings&) = delete;
    GlobalSettings( GlobalSettings&&) = delete;
private:
    GlobalSettings();


};

