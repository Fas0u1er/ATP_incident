#include "SimpleShip.h"
#include "src/board/Cell.h"
#include "src/board/Board.h"
void SimpleShip::updateState() {
    if (getSize() == getHP()) {
        state = untouched;
        return;
    }

    if (!isAlive()) {
        state = dead;
        for (auto* cellPtr: cells) {
            cellPtr->state = Cell::State::deadShip;
            for (auto position : cellPtr->getNeighbours()) {
                auto neighbour = cellPtr->boardPtr->getCellPtr(position);
                if (neighbour->getState() == Cell::sea) {
                    neighbour->state = Cell::deadSea;
                }
            }
        }
        return;
    }

    state = attacked;
}