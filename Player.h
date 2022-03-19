#pragma once

#include "Board.h"
#include "GUI_Interface.h"
#include "Ship and Cell.h"



struct Player {
    Board board;
    int idx;
    Player(int width, int height, int idx) : board(width, height), idx(idx) {}

    virtual void fillBoard(int shipsNumber) = 0;

    virtual void attack(Board* enemyBoardPtr) = 0;

    virtual ~Player() = 0;
};


