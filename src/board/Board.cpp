#include "Board.h"
#include "src/ship/SimpleShip.h"


int Board::shipCount() const {
    return ships.size();
}

int Board::deadShipCount() {
    int cnt = 0;
    for (auto& ship: ships) {
        if (ship->getState() == Ship::State::dead)
            ++cnt;
    }
    return cnt;
}

std::vector<Ship*>& Board::getShips() {
    return ships;
}
