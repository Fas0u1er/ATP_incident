#pragma once
#include "Board.h"
#include "Cell.h"
#include "src/player/Player.h"
#include "src/settings/GlobalSettings.h"
#include <vector>

class BoardBuilder {
public:
    static BoardBuilder& getInstance();

    Board constructEmptyBoard();

    static void fillShips(Player*, Board*);

private:
    BoardBuilder() = default;
};