#pragma once

#include "Board.h"
#include "GUI_Interface.h"
#include "Ship and Cell.h"
#include "Global_Settings.h"



struct Player {
    Board board;
    int index;
    Player(int idx) : board(Global_Settings::getInstance().playerSettings[idx].boardWidth,
                            Global_Settings::getInstance().playerSettings[idx].boardHeight), index(idx) {}

    virtual void fillBoard(GUI_Interface&) = 0;

    virtual void attack(GUI_Interface&, Board& enemyBoard) = 0;

    virtual ~Player() = default;
};


