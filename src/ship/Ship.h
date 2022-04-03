#pragma once
#include <vector>

#include "src/board/Cell.h"
#include "src/ship/ShipFactory.h"

class Ship {
public:
    enum State {
        untouched, attacked, dead
    };

    enum Type {
        line, cross, T, square
    };

    int getSize();

    int getHP();

    bool isAlive();

    Type getType();

    State getState();

    void updateState();

    std::vector<Cell*> getCells();

private:
    friend ShipFactory;
    std::vector<Cell*> cells;
    State state;
    Type type;
};