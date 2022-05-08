#pragma once

#include <vector>

#include "Cell.h"

class BoardBuilder;
class Position;
class GUI;
class SimplestGUI;
class Ship;

class Board {
public:
    [[nodiscard]] virtual bool withinBorders(Position) const = 0;

    virtual Cell* getCellPtr(Position) = 0;

    virtual bool attack(Position) = 0;

    [[nodiscard]] int shipCount() const;

    int deadShipCount();

    std::vector<Ship*>& getShips();

    virtual void insertShip(Ship*) = 0;

    virtual ~Board() = default;
protected:
    friend BoardBuilder;
    friend GUI;
    friend SimplestGUI;

    int width;
    int height;
    std::vector<std::vector<Cell>> cells;
    std::vector<Ship*> ships;
};

