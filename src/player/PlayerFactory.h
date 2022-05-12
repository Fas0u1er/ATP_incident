#pragma once

#include "src/settings/PlayerSettings.h"

class GUI;
class Player;
class PlayerFactory {
private:
    int playerIndex = 0;
public:
    PlayerFactory() = default;

    Player* constructPlayer(PlayerSettings::Type, GUI*);
};

