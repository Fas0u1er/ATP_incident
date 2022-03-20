#include "Board.h"

Board::Board(int width, int height) :
    width(width), height(height), ships(), cells(height, vector<Cell>(width)) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            cells[i][j].boardPtr = this;
            cells[i][j].pos = {j, i};
        }
    }
}

void Board::addShip(Position begin, Position end) {
    vector<Cell*> vCell;

    if(begin.x > end.x or begin.y > end.y)
        std::swap(begin, end);

    for (int i = begin.x; i <= end.x; ++i) {
        for (int j = begin.y; j <= end.y; ++j) {
            vCell.push_back(&cells[i][j]);
        }
    }
    ships.emplace_back(vCell);
}

int Board::allShipCount() const {
    return ships.size();
}

int Board::deadShipCount() {
    int cnt = 0;
    for (const auto& ship: ships) {
        if (ship.state == Ship::State::dead)
            ++cnt;
    }
    return cnt;
}
bool Board::withinBorders(Position pos) const {
    return (0 <= pos.x and pos.x < width and 0 <= pos.y and pos.y < height);
}
bool Board::hasNoShipNeighbours(Position pos) const {
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            Position newPosition(pos + Position{dx, dy});
            if (withinBorders(newPosition) && cells[newPosition.x][newPosition.y].state != Cell::sea)
                return false;
        }
    }
    return true;
}

void Board::attack(Position toAttack) {
    cells[toAttack.x][toAttack.y].attack();
}

