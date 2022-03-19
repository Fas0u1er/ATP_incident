#pragma once
#include "vector"
#include "Ship and Cell.h"

using std::vector;

struct Board {
    int width;
    int height;
    vector<Ship> ships;
    vector<vector<Cell>> cells;
    Board(int width, int height);
    void addShip(int, int, int, int);//four coordinates (l.x, l.y, r.x, r.y)

    int allShipCount();
    int deadShipCount();

    Cell& cellRef(int x, int y);

    void attack(int, int);// two coordinates
};
