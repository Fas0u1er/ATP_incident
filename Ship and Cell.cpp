#include "Ship and Cell.h"

int Ship::getSize() {
    return 0;
}

Ship::Ship(Board* board, Cell* begin, Cell* end) :
        board(board), cells(), state(untouched) {
    for(int i = begin->x_cord; i <= end->x_cord; ++i) {
        for(int j = begin->y_cord; j <= end->y_cord; ++j) {
            cells.push_back(&(board->cellRef(i, j)));
            (board->cellRef(i, j)).shipPtr = this;
            (board->cellRef(i, j)).state = Cell::State::ship;
        }
    }
}

void Ship::updateState() {
    if(getSize() == getHP()) {
        state = untouched;
        return;
    }

    if(getHP() == 0) {
        state = dead;
        return;
    }

    state = attacked;
}

int Ship::getHP() {
    int cnt = 0;
    for (auto cellPtr:cells) {
        if(cellPtr->state == Cell::State::ship)
            ++cnt;
    }
}

Cell::Cell(Board*, int x, int y) {

}

void Cell::attack() {
    switch (state) {
        case deadSea:
            return;
        case deadShip:
            return;
        case attackedShip:
            return;
        case ship:
            state = attackedShip;
            shipPtr->updateState();
            break;
        case sea:
            state = deadSea;
            break;
    }
}
