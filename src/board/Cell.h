#pragma once
#include "Position.h"

class Board;
class SimpleShip;

class Cell {
public:
    enum State {
        sea, deadSea, ship, attackedShip, deadShip
    };

    Cell() = default;

    Cell(Board* brd, Position pos);

    bool attack();

    Position getPosition();

    [[nodiscard]] State getState() const;

    [[nodiscard]] bool isShip() const;

    [[nodiscard]] bool isFarFromShips() const;

    [[nodiscard]] bool isOkToAttack() const;

    void bindToShip(SimpleShip*);
private:
    friend SimpleShip;

    Board* boardPtr;
    SimpleShip* shipPtr;
    Position pos;
    State state;
};
