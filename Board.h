#pragma once

#include "vector"
#include "Ship and Cell.h"
#include "Position.h"

using std::vector;

struct Board {
    int width;
    int height;
    vector<Ship> ships;
    vector<vector<Cell>> cells;
    Board(int width, int height);

    void addShip(Position, Position);//two coordinates (begin, end)

    int allShipCount();

    int deadShipCount();

    void attack(Position);// coordinates of attack
};
