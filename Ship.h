#pragma once
#include <vector>
#include "Cell.h"
#include "Board.h"
using std::vector;

struct Ship {
    enum State {
        untouched, attacked, dead
    };

    Board* board;
    vector<Cell*> cells;
    State state = untouched;

    int getSize();
    Ship(Board*, Cell*, Cell*);
};

