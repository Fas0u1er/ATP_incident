#pragma once

#include "random"


#include "src/player/Player.h"
#include "src/settings/GlobalSettings.h"

class Bot : public Player {
public:
    explicit Bot(int index);
    ~Bot() override = default;
protected:
    Position get_random_cell();
    int get_randint(int max_result);
private:
    std::mt19937 gen;
};
