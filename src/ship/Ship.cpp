#include <stdexcept>

#include "Ship.h"
#include "src/board/Cell.h"


int Ship::getSize() const {
    return cells.size();
}

int Ship::getHP() const {
    int cnt = 0;
    for (auto cellPtr: cells) {
        if (cellPtr->getState() == Cell::State::ship)
            ++cnt;
    }
    return cnt;
}

bool Ship::isAlive() const {
    return getHP() != 0;
}

Ship::Type Ship::getType() const {
    return type;
}

Ship::State Ship::getState() const {
    return state;
}

std::vector<Cell*>& Ship::getCells() {
    return cells;
}

const std::vector <std::string> Ship::typeToString = {
    "line",
    "cross",
    "T",
    "square",
};