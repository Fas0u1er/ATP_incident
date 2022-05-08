#pragma once

#include <vector>

#include "Position.h"

class Board;
class SimpleShip;

class Cell {
public:
    enum State {
        sea, deadSea, ship, attackedShip, deadShip, pendingShip, misplacedShip
    };

    Cell(Board* board, Position pos);

    bool attack();

    Position getPosition();

    [[nodiscard]] State getState() const;

    void setState(Cell::State newState);

    [[nodiscard]] bool isShip() const;

    [[nodiscard]] bool isFarFromShips() const;

    [[nodiscard]] bool isOkToAttack() const;

    void bindToShip(SimpleShip*);

    std::vector <Position> getNeighbours() const;
private:
    friend SimpleShip;

    Board* boardPtr;
    SimpleShip* shipPtr;
    Position pos;
    State state;
};
