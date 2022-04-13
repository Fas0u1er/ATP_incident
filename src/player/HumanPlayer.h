#pragma once

#include "Player.h"
#include "src/ship/Ship.h"
class GUIInterface;
class Cell;
class PlayerFactory;

class HumanPlayer : public Player {
private:
    GUIInterface* gui;
    HumanPlayer(int index, GUIInterface* gui);
public:

    bool attack(Player* enemy) override;

    std::vector<Cell*> getNewShipCells(Ship::Type, int size) override;

    ~HumanPlayer() override = default;

    friend PlayerFactory;
};


