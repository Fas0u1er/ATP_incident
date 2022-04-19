#pragma once
#include "Position.h"

class RectangleBoard;
class SimpleShip;

class Cell {
public:
    enum State {
        sea, deadSea, ship, attackedShip, deadShip
    };

    Cell() = default;

    Cell(RectangleBoard* brd, Position pos);

    bool attack();

    Position getPosition();

    [[nodiscard]] State getState() const;

    [[nodiscard]] bool isShip() const;

    [[nodiscard]] bool isFarFromShips() const;

    [[nodiscard]] bool isOkToAttack() const;

    void bindToShip(SimpleShip*);
private:
    friend SimpleShip;

    RectangleBoard* boardPtr;
    SimpleShip* shipPtr;
    Position pos;
    State state;
};
