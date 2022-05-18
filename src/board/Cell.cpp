#include <stdexcept>
#include "Cell.h"
#include "src/ship/SimpleShip.h"
#include "RectangleBoard.h"

Cell::Cell(Board* board, Position pos) :
    boardPtr(board), shipPtr(nullptr), pos(pos), state(sea) {}

bool Cell::attack() {
    switch (state) {
        case deadSea:
        case deadShip:
        case island:
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
        default: throw std::logic_error("Tried to attack unknown type of cell");
    }
}

Position Cell::getPosition() {
    return pos;
}

Cell::State Cell::getState() const {
    return state;
}

void Cell::setState(Cell::State newState) {
    state = newState;
}

bool Cell::isShip() const {
    return
        state == Cell::State::attackedShip or
            state == Cell::State::ship or
            state == Cell::State::deadShip;
}

bool Cell::isFarFromShips() const {
    for (auto neigh: getNeighbours()) {
        if (boardPtr->getCellPtr(neigh)->isShip()) {
            return false;
        }
    }
    return true;
}

bool Cell::isOkToPlaceShip() const {
    return isFarFromShips() && state != island;
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


std::vector<Position> Cell::getNeighbours() const {
    std::vector<Position> result;
    for (int xShift: {-1, 0, 1}) {
        for (int yShift: {-1, 0, 1}) {
            Position neigh = pos + Position{xShift, yShift};
            if (boardPtr->withinBorders(neigh)) {
                result.push_back(neigh);
            }
        }
    }
    return result;
}

