#pragma once

#include "src/ship/Ship.h"

#include <string>
#include <vector>


using std::vector;
using std::string;
using std::pair;

class Position;
class Board;
class Cell;
class Player;

class GUIInterface {
private:

public:
    virtual int displayOptions(const std::string& title, const vector<string>& options) = 0;
    virtual void displayBoard(const Board& board, bool isMine) = 0;
    virtual Position getAttack(const Player& player, const Board& attackedBoard) = 0;
    virtual void displayPlayer(const Player& player, bool isMine) = 0;
    virtual std::vector<Cell*> placeShip(Player& player, Ship::Type type, int size) = 0;
    //Returns correctly placed ship, represented by a vector of cells
    virtual void clearScreen() = 0;

    virtual ~GUIInterface() = default;
};
