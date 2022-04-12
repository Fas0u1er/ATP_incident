#pragma once
#include "src/board/Position.h"
#include "src/player/Player.h"
#include "src/board/Board.h"

#include "string"
#include "vector"

using std::vector;
using std::string;
using std::pair;

class GUIInterface {
private:

public:
    virtual pair<Position, Position> placeShip(const Board& board, int length) = 0;
    virtual int displayOptions(const vector<string>& options) = 0;
    virtual void displayBoard(const Board& board, bool isMine) = 0;
    virtual Position getAttack(const Player& player, const Board& attackedBoard) = 0;
    virtual void displayPlayer(const Player& player, bool isMine) = 0;

    virtual ~GUIInterface() = default;
};
