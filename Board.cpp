#include "Board.h"

int Board::shipCount() {
    return false;
}


void Board::addShip(int lx, int ly, int rx, int ry) {

}

int Board::deadShipCount() {
    return 0;
}

void Board::attack(int, int) {

}

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
