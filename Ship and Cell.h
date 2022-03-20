#pragma once
#include "Position.h"
#include <vector>

using std::vector;

struct Board;

struct Cell;
struct Ship;

struct Ship {
    enum State {
        untouched, attacked, dead
    };

    vector<Cell*> cells;
    State state = untouched;

    int getSize();

    void updateState();

    int getHP();

    Ship(vector<Cell*>& cells);
};

struct Cell {
    Cell() = default;

    enum States {
        sea, deadSea, ship, attackedShip, deadShip
    };

    States state = sea;
    Ship* shipPtr = nullptr;
    Board* boardPtr = nullptr;
    Position pos = {0, 0};

    void attack();
};






