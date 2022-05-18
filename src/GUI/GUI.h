#pragma once

#include "src/ship/SimpleShip.h"

#include <string>
#include <vector>
#include <functional>
#include <variant>

class Position;
class Board;
class Setting;
class Cell;
class Player;


class GUI {
public:
    virtual int displayOptions(const std::string& title, const std::vector<std::string>& options) = 0;
    virtual Position getAttack(const Player& player, const Player& enemy) = 0;
    virtual std::vector<Cell*> placeShip(Player& player, SimpleShip::Type type, int size) = 0;
    //Returns correctly placed ship, represented by a vector of cells
    virtual void displaySettings(const std::string& title, std::vector<Setting*>&) = 0;
    // Given list of settings presents them to the user and allows to change them
    virtual void showResults(const Player& winner, int roundsPlayed) = 0;
    virtual void finishWork() = 0;
    virtual void waitForNextPlayer(const Player& player) = 0;
    virtual ~GUI() = default;
};
