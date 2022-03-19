#pragma once
#include "Player.h"

struct ConsolePlayer : public Player {
public:

    void fillBoard(GUI_Interface&) override;

    void attack(GUI_Interface&, Board& enemyBoard) override;


    ~ConsolePlayer() override = default;
};


