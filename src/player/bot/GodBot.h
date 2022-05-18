#pragma once

#include "src/player/bot/Bot.h"
#include "src/player/bot/VeteranBot.h"

class PlayerFactory;

class GodBot : public Bot {
private:
    explicit GodBot(int index);

    static std::vector<Position> chooseEnemyShipCells(Board& enemyBoard);

    int assessShipsPositioning(std::vector<Cell*>& newShipCells);
public:

    std::vector<Cell*> getNewShipCells(SimpleShip::Type, int size) override;

    bool attack(Player* enemy) override;
    friend PlayerFactory;
};

