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
private:

public:
    virtual int displayOptions(const std::string& title, const std::vector<std::string>& options) = 0;
    virtual void displayBoard(const Board& board, bool isMine) = 0;
    virtual Position getAttack(const Player& player, const Board& attackedBoard) = 0;
    virtual void displayPlayer(const Player& player, bool isMine) = 0;
    virtual std::vector<Cell*> placeShip(Player& player, SimpleShip::Type type, int size) = 0;
    //Returns correctly placed ship, represented by a vector of cells
    virtual void clearScreen() = 0;
    virtual void displaySettings(const std::string& title, std::vector<Setting*>&) = 0;
    // Given list of pairs {label, vector <int>} presents them to the user and allows to change them
    virtual ~GUI() = default;
};
