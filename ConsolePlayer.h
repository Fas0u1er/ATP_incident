#pragma once
#include "Player.h"

struct ConsolePlayer : public Player {
public:

    void fillBoard(int shipsNumber) override;

    void attack(Board* enemyBoardPtr) override;


    ~ConsolePlayer() override = default;
};


