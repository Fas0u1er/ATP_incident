#pragma once

#include <vector>

#include "Board.h"

class BoardBuilder;
class Position;
class GUI;
class SimplestGUI;
class Ship;

class RectangleBoard : public Board {
public:
    [[nodiscard]] bool withinBorders(Position) const override;

    Cell* getCellPtr(Position) override;

    bool attack(Position) override;

    void insertShip(Ship*) override;
private:
    friend BoardBuilder;
    friend GUI;
    friend SimplestGUI;

};

