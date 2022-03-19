#pragma once

#include "Board.h"
#include "GUI_Interface.h"
#include "Ship and Cell.h"



struct Player {
    Board board;
    int playerIdx;
    Player(int width, int height, int idx) : board(width, height), playerIdx(idx) {}

    virtual void fillBoard(GUI_Interface&, int shipNumber) = 0;

    virtual void attack(GUI_Interface&, Board* enemyBoardPtr) = 0;

    virtual ~Player() = default;
};


