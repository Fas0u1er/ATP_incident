#include "Cell.h"
#include <cassert>

Cell::Cell(Board* brd, Position pos) :
        boardPtr(brd), shipPtr(nullptr), pos(pos), state(sea) {}


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
            assert(shipPtr != nullptr);
            shipPtr->updateState();
            break;
        case sea:
            state = deadSea;
            break;
    }
}

Position Cell::getPosition() {
    return pos;
}

Cell::State Cell::getState() {
    return state;
}

bool Cell::isShip() {
    return state == Cell::State::attackedShip or
            state == Cell::State::ship or
            state == Cell::State::deadShip;
}

bool Cell::isFarFromShips() {
    for(int xShift: {-1, 0, 1}) {
        for(int yShift: {-1, 0, 1}) {
            Position neigh = pos + Position({xShift, yShift});
            if(boardPtr->withinBorders(neigh) && boardPtr->getCellPtr(neigh)->isShip()) {
                return false;
            }
        }
    }
    return true;
}

void Cell::bindToShip(Ship& ship) {
    shipPtr = &(ship);
    state = Cell::State::ship;
}