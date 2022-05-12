#pragma once

#include "src/player/bot/Bot.h"
#include "src/ship/ShipFactory.h"
#include "src/settings/GlobalSettings.h"

class PlayerFactory;
class GodBot;

class VeteranBot : public Bot {
    explicit VeteranBot(int index);

    static std::vector<Position> chooseBestAttacks(Board& board);
public:
    std::vector<Cell*> getNewShipCells(SimpleShip::Type, int size) override;

    bool attack(Player* enemy) override;

friend PlayerFactory;
friend GodBot;
};

