#include "Board.h"

Board::Board(int width, int height) :
        width(width), height(height), ships(), cells(height, vector<Cell>(width)) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            cells[i][j].boardPtr = this;
            cells[i][j].x_cord = j;
            cells[i][j].y_cord = i;
        }
    }
}

void Board::addShip(int lx, int ly, int rx, int ry) {
    vector<Cell*> vCell;
    for (int i = lx; i <= rx; ++i) {
        for (int j = ly; j <= ry; ++j) {
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

void Board::attack(int x, int y) {
    cells[x][y].attack();
}

