#pragma once

#include "src/GUI/GUIInterface.h"
#include "src/board/BoardBuilder.h"
#include "src/board/Board.h"
#include "src/settings/GlobalSettings.h"
#include "src/board/Cell.h"

class Player {
public:
    int index;
    Board board;

    explicit Player(int idx) : index(idx),
                               board(BoardBuilder::getInstance().constructEmptyBoard()) {}

    virtual void fillBoard() = 0;

    virtual std::vector<Cell*> getNewShipCells(Ship::Type, int size) = 0;

    virtual void attack(Player* enemy) = 0;

    virtual bool isAlive() = 0;

    virtual ~Player() = default;
};
