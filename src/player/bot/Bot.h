#pragma once

#include "src/player/Player.h"

class Bot : public Player {
public:

    explicit Bot(int index) : Player(index) {}
    ~Bot() override = default;
};