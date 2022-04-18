#pragma once
#include "SimpleShip.h"
#include "src/board/Board.h"
class Player;
class Position;
class Cell;
class Board;

class ShipFactory {
public:
    static ShipFactory& getInstance();

    Ship* constructSimpleShip(Player*, Ship::Type, int size);

    static std::vector<Cell*> convertPositioning(const std::vector<Position>& positions, Board& board);

    static std::vector <Position> generateLineShip(Position upperLeft, Position direction, int size);
    static std::vector <Position> generateSquareShip(Position upperLeft, int size);
    static std::vector <Position> generateTShip(Position center, Position direction, int size);
    static std::vector <Position> generateCrossShip(Position center, int size);

private:
    ShipFactory() = default;
};