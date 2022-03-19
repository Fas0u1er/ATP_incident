#pragma once

#include "Board.h"
#include "Settings.h"
#include "Ship and Cell.h"


class Player {
protected:
    Board board;
public:
    explicit Player(int width, int height) : board(width, height) {};

    virtual void fillBoard(int shipsNumber) = 0;

    virtual void attack(Board* enemyBoard) = 0;

    virtual ~Player() = 0;
};


