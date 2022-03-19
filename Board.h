#pragma once
#include "vector"
#include "Ship.h"
#include "Cell.h"

using std::vector;

class Board {
    int width;
    int height;
    vector<Ship> ships;
    vector<vector<Cell>> cells;
public:
    Board(int width, int height);
    void addShip(int, int, int, int);//four coordinates (l.x, l.y, r.x, r.y)

    int shipCount();
    int deadShipCount();

    void attack(int, int);// two coordinates
};
