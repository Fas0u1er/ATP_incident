#pragma once

#include <vector>

#include "src/board/Cell.h"
#include "src/board/BoardBuilder.h"
#include "src/ship/Ship.h"

class Board {
public:
    bool withinBorders(Position);

    Cell* getCellPtr(Position);

    void attack(Position);

    int shipCount();

    int deadShipCount();

    std::vector<Ship>& getShips();

    void insertShip(Ship&);
private:
    friend BoardBuilder;
    int width;
    int height;
    std::vector<Ship> ships;
    std::vector<std::vector<Cell>> cells;
};