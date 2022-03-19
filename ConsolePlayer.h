#pragma once
#include "Player.h"

struct ConsolePlayer : public Player {
public:

    void fillBoard(GUI_Interface&, int shipsNumber) override;

    void attack(GUI_Interface&, Board* enemyBoardPtr) override;


    ~ConsolePlayer() override = default;
};


