#pragma once
#include "src/player/Player.h"

class ConsolePlayer : public Player {
private:
    GUIInterface* gui;
public:
    ConsolePlayer(int idx, GUIInterface* gui);

    void fillBoard() override;

    void attack(Player* enemy) override;

    std::vector<Cell*> getNewShipCells(Ship::Type, int size) override;

    bool isAlive() override;

    ~ConsolePlayer() override = default;
};


