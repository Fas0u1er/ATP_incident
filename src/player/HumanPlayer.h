#pragma once

#include "Player.h"
#include "src/ship/SimpleShip.h"
class GUI;
class Cell;
class PlayerFactory;

class HumanPlayer : public Player {
private:
    GUI* gui;
    HumanPlayer(int index, GUI* gui);
public:

    bool attack(Player* enemy) override;

    std::vector<Cell*> getNewShipCells(SimpleShip::Type, int size) override;

    ~HumanPlayer() override = default;

    friend PlayerFactory;
};


