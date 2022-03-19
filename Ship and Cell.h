#pragma once
#include <vector>

using std::vector;

class Board;
struct Cell;


struct Ship {
    Ship(Board*, Cell*, Cell*);

    enum State {
        untouched, attacked, dead
    };

    Board* board;
    vector<Cell*> cells;
    State state = untouched;

    int getSize();
    void updateState();
    int getHP();
};


struct Cell {
    Cell(Board* board, int x, int y);

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

