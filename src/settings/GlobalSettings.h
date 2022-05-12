#pragma once
#include <vector>
#include <unordered_map>
#include <cassert>
#include <iostream>

#include "PlayerSettings.h"
#include "src/ship/SimpleShip.h"

class GlobalSettings {
public:
    int boardWidth = 10;
    int boardHeight = 10;
    int shipsNumber = 4;
    std::unordered_map<Ship::Type, std::vector <int>> ships = {
            {Ship::Type::line, {1, 2}},
            {Ship::Type::square, {4}},
            {Ship::Type::T, {2}}
    };
    int playerNumber = 2;
    std::vector<PlayerSettings> playerSettings{{"Human", PlayerSettings::Type::Human},
                                               {"God Bot", PlayerSettings::Type::GodBot}};


    //    int boardWidth = 8;
//    int boardHeight = 8;
//    int shipsNumber = 5;
//    std::unordered_map<Ship::Type, std::vector <int>> ships = {
//        {Ship::Type::line, {1, 1, 1, 1}},
//        {Ship::Type::square, {4}},
//
//    };
//    int playerNumber = 2;

//    std::vector<PlayerSettings> playerSettings;

    static GlobalSettings& getInstance();

    void resize(int newPlayerNumber);
    GlobalSettings(const GlobalSettings&) = delete;
    GlobalSettings( GlobalSettings&&) = delete;
private:
    GlobalSettings();


};

