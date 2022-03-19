#include "Ship and Cell.h"

int Ship::getSize() {
    return cells.size();
}

Ship::Ship(vector<Cell*>& cells) : cells(cells) {
    for (auto* cellPtr : cells) {
        cellPtr->state = Cell::State::ship;
        cellPtr->shipPtr = this;
    }
}

void Ship::updateState() {
    if (getSize() == getHP()) {
        state = untouched;
        return;
    }

    if (getHP() == 0) {
        state = dead;
        return;
    }

    state = attacked;
}

int Ship::getHP() {
    int cnt = 0;
    for (auto cellPtr : cells) {
        if (cellPtr->state == Cell::State::ship)
            ++cnt;
    }
    return cnt;
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
