#pragma once

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

    enum State {
        sea, deadSea, ship, attackedShip, deadShip
    };

    State state = sea;
    Ship* shipPtr = nullptr;
    Board* boardPtr = nullptr;
    int x_cord = 0;
    int y_cord = 0;

    void attack();
};






