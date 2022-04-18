#include <stdexcept>
#include "Cell.h"
#include "src/ship/SimpleShip.h"
#include "Board.h"

Cell::Cell(Board* brd, Position pos) :
    boardPtr(brd), shipPtr(nullptr), pos(pos), state(sea) {}

bool Cell::attack() {
    switch (state) {
        case deadSea:
        case deadShip:
        case attackedShip: throw std::logic_error("Attacking dead cells should be prohibited");
        case ship: {
            state = attackedShip;
            if (!shipPtr) {
                throw std::logic_error("Tried attacking nullptr ship");
            }
            shipPtr->updateState();
            return true;
        }
        case sea: {
            state = deadSea;
            return false;
        }
    }
}

Position Cell::getPosition() {
    return pos;
}

Cell::State Cell::getState() const {
    return state;
}

bool Cell::isShip() const {
    return
        state == Cell::State::attackedShip or
            state == Cell::State::ship or
            state == Cell::State::deadShip;
}

bool Cell::isFarFromShips() const {
    for (int xShift: {-1, 0, 1}) {
        for (int yShift: {-1, 0, 1}) {
            Position neigh = pos + Position{xShift, yShift};
            if (boardPtr->withinBorders(neigh) && boardPtr->getCellPtr(neigh)->isShip()) {
                return false;
            }
        }
    }
    return true;
}

void Cell::bindToShip(SimpleShip* ship) {
    shipPtr = ship;
    state = Cell::State::ship;
}
bool Cell::isOkToAttack() const {
    return
        state == Cell::State::ship or
            state == Cell::State::sea;
}
