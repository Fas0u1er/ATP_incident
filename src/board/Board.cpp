#include "Board.h"
#include "Position.h"
#include "Cell.h"
#include "src/ship/SimpleShip.h"

bool Board::withinBorders(Position pos) const {
    return 0 <= pos.x && pos.x < height &&
           0 <= pos.y && pos.y < width;
}

Cell* Board::getCellPtr(Position pos) {
    return &(cells[pos.x][pos.y]);
}

bool Board::attack(Position pos) {
    return cells[pos.x][pos.y].attack();
}

int Board::shipCount() const {
    return ships.size();
}

int Board::deadShipCount() {
    int cnt = 0;
    for (auto& ship: ships) {
        if (ship->getState() == SimpleShip::State::dead)
            ++cnt;
    }
    return cnt;
}

std::vector<Ship*>& Board::getShips() {
    return ships;
}

void Board::insertShip(Ship* ship) {
    ships.push_back(ship);
}

