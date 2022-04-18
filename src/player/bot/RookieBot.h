#pragma once

#include "src/player/bot/Bot.h"
class PlayerFactory;

class RookieBot : public Bot {
private:
    explicit RookieBot(int index);
public:

    std::vector<Cell*> getNewShipCells(SimpleShip::Type, int size) override;

    bool attack(Player* enemy) override;

    friend PlayerFactory;
};

