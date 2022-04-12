#include "Board.h"

bool Board::withinBorders(Position pos) {
    return 0 <= pos.x && pos.x < width &&
           0 <= pos.y && pos.y < height;
}

Cell* Board::getCellPtr(Position pos) {
    return &(cells[pos.x][pos.y]);
}

void Board::attack(Position pos) {
    cells[pos.x][pos.y].attack();
}

int Board::shipCount() {
    return ships.size();
}

int Board::deadShipCount() {
    int cnt = 0;
    for (auto& ship: ships) {
        if (ship.getState() == Ship::State::dead)
            ++cnt;
    }
    return cnt;
}

std::vector<Ship>& Board::getShips() {
    return ships;
}

void Board::insertShip(Ship& ship) {
    for(auto cellPtr: ship.getCells()) {
        cellPtr->bindToShip(ship);
    }

    ships.push_back(ship);
}

