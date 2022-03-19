#pragma once

#include "Ship.h"

struct Cell {
    Cell(Board* board, int x, int y);

    enum State {
        sea, deadSea, ship, attackedShip, deadShip
    };
    State state = sea;
    Ship* shipPtr = nullptr;
    Board* boardPtr = nullptr;
    int x_cord = 0;
    int y_cord = 0;
};


