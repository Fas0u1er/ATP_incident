#pragma once
#include <vector>
#include <string>
#include "Ship.h"


class SimpleShip : public Ship {
    friend ShipFactory;
public:
    void updateState() override;
};