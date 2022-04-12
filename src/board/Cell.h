#pragma once

#include "src/board/Board.h"
#include "src/board/Position.h"
#include "src/ship/Ship.h"

class Cell {
public:
    enum State {
        sea, deadSea, ship, attackedShip, deadShip
    };

    Cell(Board* brd, Position pos);

    void attack();

    Position getPosition();

    State getState();

    bool isShip();

    bool isFarFromShips();

    void bindToShip(Ship&);
private:
    friend Ship;

    Board* boardPtr;
    Ship* shipPtr;
    Position pos;
    State state;
};
