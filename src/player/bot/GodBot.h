#pragma once

#include "src/player/bot/Bot.h"
class PlayerFactory;

class GodBot : public Bot {
private:
    explicit GodBot(int index);
public:

    std::vector<Cell*> getNewShipCells(Ship::Type, int size) override;

    bool attack(Player* enemy) override;
    friend PlayerFactory;
};

