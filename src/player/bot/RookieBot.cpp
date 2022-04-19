#include "RookieBot.h"


std::vector<Cell*> RookieBot::getNewShipCells(SimpleShip::Type type, int size) {
    for (int i = 0; i < GlobalSettings::getInstance().boardHeight; ++i) {
        for (int j = 0; j < GlobalSettings::getInstance().boardWidth; ++j) {
            Position upperLeft(i, j);
            for (auto dir : {Position(1, 0), Position(0, 1),
                             Position(0, -1), Position(-1, 0)}) {
                auto shipCells = ShipFactory::convertPositioning(
                        ShipFactory::generateShipCells(type, upperLeft, size, dir), *board);
                if (!shipCells.empty())
                    return shipCells;
            }
        }
    }

    throw std::logic_error("No space for new ship");
}

bool RookieBot::attack(Player* enemy) {

    while (true) {
        auto toAttack = get_random_cell();

        if (enemy->board->getCellPtr(toAttack)->isOkToAttack()) {
            return enemy->board->attack(toAttack);
        }
    }
}


RookieBot::RookieBot(int index) : Bot(index) {}
