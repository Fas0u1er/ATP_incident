#include "GodBot.h"
std::vector<Cell*> GodBot::getNewShipCells(SimpleShip::Type type, int size) {
    while (true) {
        Position upperLeft = get_random_cell();

        const std::vector<Position> directions = {Position(1, 0), Position(0, 1),
                                                  Position(0, -1), Position(-1, 0)};
        Position dir = directions[get_randint(directions.size())];
        auto shipCells = ShipFactory::convertPositioning(
                ShipFactory::generateShipCells(type, upperLeft, size, dir), *board);
        if (!shipCells.empty())
            return shipCells;
    }
}
bool GodBot::attack(Player* enemy) {
    int godBlessing = get_randint(3);

    std::vector<Position> best;
    if(godBlessing == 0) {
        best = chooseShipCells(*(enemy->board));
    } else {
        best = VeteranBot::chooseBestAttacks(*(enemy->board));
    }

    return enemy->board->attack(best[get_randint(best.size())]);
}


GodBot::GodBot(int index) : Bot(index) {}

std::vector<Position> GodBot::chooseShipCells(Board& board) {
    std::vector<Position> shipCells;

    int height = GlobalSettings::getInstance().boardHeight;
    int width = GlobalSettings::getInstance().boardWidth;

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if(board.getCellPtr({i, j})->isShip() && board.getCellPtr({i, j})->isOkToAttack()) {
                shipCells.emplace_back(i, j);
            }
        }
    }
    return shipCells;
}
