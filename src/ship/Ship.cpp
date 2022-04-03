#include "Ship.h"

int Ship::getSize() {
    return cells.size();
}

int Ship::getHP() {
    int cnt = 0;
    for (auto cellPtr : cells) {
        if (cellPtr->getState() == Cell::State::ship)
            ++cnt;
    }
    return cnt;
}

bool Ship::isAlive() {
    return getHP() != 0;
}

Ship::Type Ship::getType() {
    return type;
}

Ship::State Ship::getState() {
    return state;
}

void Ship::updateState() {
    if (getSize() == getHP()) {
        state = untouched;
        return;
    }

    if (getHP() == 0) {
        state = dead;
        for(auto* cellPtr:cells) {
            cellPtr->state = Cell::State::deadShip;
        }
        return;
    }

    state = attacked;
}

std::vector<Cell*> Ship::getCells() {
    return cells;
}
