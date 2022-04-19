#pragma once

#include <string>

#include "src/board/RectangleBoard.h"
#include "src/board/BoardBuilder.h"
#include "src/ship/SimpleShip.h"

class PlayerFactory;
class Position;

class Player {
public:
    int index;
    std::unique_ptr <Board> (board);

    explicit Player(int idx) : index(idx),
                               board(BoardBuilder::getInstance().constructEmptyRectangleBoard()) {}

    void fillBoard();

    virtual std::vector<Cell*> getNewShipCells(SimpleShip::Type, int size) = 0;


    virtual bool attack(Player* enemy) = 0;

    bool isAlive();

    [[nodiscard]] std::string getName() const;

    virtual ~Player() = default;

    friend PlayerFactory;
};
