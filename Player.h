#pragma once

#include "Board.h"
#include "Ship and Cell.h"
#include "Global_Settings.h"

#include "string"

using std::string;

struct GUI_Interface;


struct Player {
    Board board;
    int index;
    string name;

    Player(int idx) : board(Global_Settings::getInstance().boardWidth,
                            Global_Settings::getInstance().boardHeight), index(idx) {}

    virtual void fillBoard(GUI_Interface&) = 0;

    virtual void attack(GUI_Interface&, Board& enemyBoard) = 0;

    virtual ~Player() = default;
};


#include "GUI_Interface.h"
