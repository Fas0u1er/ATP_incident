#pragma once

#include <string>

#include "src/board/Board.h"
#include "src/board/BoardBuilder.h"
#include "src/ship/Ship.h"

class PlayerFactory;
class Position;

class Player {
public:
    int index;
    Board board;

    explicit Player(int idx) : index(idx),
                               board(BoardBuilder::getInstance().constructEmptyBoard()) {}

    void fillBoard();

    virtual std::vector<Cell*> getNewShipCells(Ship::Type, int size) = 0;


    virtual bool attack(Player* enemy) = 0;

    bool isAlive();

    [[nodiscard]] std::string getName() const;

    virtual ~Player() = default;

    friend PlayerFactory;
};
