#include "SimpleShip.h"
#include "src/board/Cell.h"

void SimpleShip::updateState() {
    if (getSize() == getHP()) {
        state = untouched;
        return;
    }

    if (!isAlive()) {
        state = dead;
        for (auto* cellPtr: cells) {
            cellPtr->state = Cell::State::deadShip;
        }
        return;
    }

    state = attacked;
}