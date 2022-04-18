#pragma once

#include <vector>

#include "Cell.h"
#include "src/ship/SimpleShip.h"

class BoardBuilder;
class Position;
class GUI;
class SimplestGUI;

class Board {
public:
    [[nodiscard]] bool withinBorders(Position) const;

    Cell* getCellPtr(Position);

    bool attack(Position);

    [[nodiscard]] int shipCount() const;

    int deadShipCount();

    std::vector<Ship*>& getShips();

    void insertShip(Ship*);
private:
    friend BoardBuilder;
    friend GUI;
    friend SimplestGUI;

    int width;
    int height;
    std::vector<std::vector<Cell>> cells;
    std::vector<Ship*> ships;
};

