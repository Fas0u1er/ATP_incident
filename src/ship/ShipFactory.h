#pragma once
#include "Ship.h"
#include "src/player/Player.h"

class ShipFactory {
public:
    static ShipFactory& getInstance();

    Ship constructShip(Player*, Ship::Type, int size);

private:
    ShipFactory() = default;
};