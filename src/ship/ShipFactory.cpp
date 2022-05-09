#include <vector>

#include "ShipFactory.h"
#include "src/player/Player.h"
#include "src/board/Cell.h"
#include "src/board/RectangleBoard.h"
#include "src/board/Position.h"

ShipFactory& ShipFactory::getInstance() {
    static ShipFactory instance;
    return instance;
}

Ship* ShipFactory::constructSimpleShip(Player* playerPtr, Ship::Type type, int size) {
    /* Constructs the ship by asking the player*/
    auto* ship = new SimpleShip();
    auto shipCells = playerPtr->getNewShipCells(type, size);
    ship->cells = shipCells;
    ship->state = SimpleShip::State::untouched;
    ship->type = type;
    for (auto cellPtr: ship->getCells()) {
        cellPtr->bindToShip(ship);
    }

    return ship;
}
std::vector<Cell*> ShipFactory::convertPositioning(const std::vector<Position>& positions, Board& board) {
    std::vector<Cell*> cells;
    for (auto position: positions) {
        if (!board.withinBorders(position))
            return {};
        auto cellPtr = board.getCellPtr(position);
        if (!cellPtr->isOkToPlaceShip()) {
            return {};
        }
        cells.push_back(cellPtr);
    }
    return cells;
}
std::vector<Position> ShipFactory::generateLineShip(Position upperLeft, Position direction, int size) {
    std::vector<Position> positions;
    for (int shift = 0; shift < size; ++shift) {
        positions.emplace_back(upperLeft + direction * shift);
    }
    return positions;
}
std::vector<Position> ShipFactory::generateSquareShip(Position upperLeft, int size) {
    std::vector<Position> positions;
    for (int xshift = 0; xshift < size; ++xshift) {
        for (int yshift = 0; yshift < size; ++yshift) {
            positions.emplace_back(upperLeft + Position{xshift, yshift});
        }
    }
    return positions;
}
std::vector<Position> ShipFactory::generateTShip(Position center, Position direction, int size) {
    std::vector<Position> positions;
    Position perpendicular = {1 - abs(direction.x), 1 - abs(direction.y)};
    //Part, intersected in middle
    for (int shift = -size; shift <= size; ++shift)
        positions.emplace_back(center + perpendicular * shift);
    //The other part
    for (int shift = 1; shift <= 2 * size; ++shift)
        positions.emplace_back(center + direction * shift);
    return positions;
}
std::vector<Position> ShipFactory::generateCrossShip(Position center, int size) {
    std::vector<Position> positions;
    positions.push_back(center);
    for (auto direction: {
        Position(1, 0),
        Position(-1, 0),
        Position(0, -1),
        Position(0, 1),
    }) {
        for (int shift = 1; shift <= size; ++shift)
            positions.emplace_back(center + direction * shift);
    }
    return positions;
}

std::vector<Position> ShipFactory::generateShipPositions(Ship::Type type, Position upperLeft,
                                                         int size, Position direction = {0, 1}) {
    switch (type) {
        case Ship::line: return ShipFactory::generateLineShip(upperLeft, direction, size);
        case Ship::T: return ShipFactory::generateTShip(upperLeft, direction, size);
        case Ship::square: return ShipFactory::generateSquareShip(upperLeft, size);
        case Ship::cross: return ShipFactory::generateCrossShip(upperLeft, size);
        default: throw std::logic_error("Unknown ship type");
    }

}
