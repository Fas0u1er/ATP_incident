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

int Board::allShipCount() {
    return ships.size();
}

int Board::deadShipCount() {
    int cnt = 0;
    for (const auto& ship : ships) {
        if (ship.state == Ship::State::dead)
            ++cnt;
    }
    return cnt;
}

void Board::attack(Position toAttack) {
    cells[toAttack.x][toAttack.y].attack();
}

