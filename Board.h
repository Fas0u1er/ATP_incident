#pragma once

#include "vector"
#include "Ship and Cell.h"
#include "Position.h"

using std::vector;
using std::pair;

struct Board {
    int width;
    int height;
    vector<Ship> ships;
    vector<vector<Cell>> cells;
    Board(int width, int height);

    void addShip(Position, Position);//two coordinates (begin, end)

    int allShipCount() const;

    int deadShipCount();

    void attack(Position);// coordinates of attack

    bool withinBorders(Position pos) const;

    bool hasNoShipNeighbours(Position pos) const;
};
