#pragma once
#include "Player.h"

struct ConsolePlayer : public Player {
public:

    explicit ConsolePlayer(int idx) : Player(idx) {}

    void fillBoard(GUI_Interface&) override;

    void attack(GUI_Interface&, Board& enemyBoard) override;


    ~ConsolePlayer() override = default;
};


