#include "RectangleBoard.h"
#include "Position.h"
#include "Cell.h"
#include "src/ship/SimpleShip.h"

bool RectangleBoard::withinBorders(Position pos) const {
    return 0 <= pos.x && pos.x < height &&
           0 <= pos.y && pos.y < width;
}

Cell* RectangleBoard::getCellPtr(Position pos) {
    return &(cells[pos.x][pos.y]);
}

bool RectangleBoard::attack(Position pos) {
    return cells[pos.x][pos.y].attack();
}

void RectangleBoard::insertShip(Ship* ship) {
    ships.push_back(ship);
}

