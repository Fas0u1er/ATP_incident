#include "GodBot.h"

int GodBot::assessShipsPositioning(std::vector<Cell*>& newShipCells) {
    int height = GlobalSettings::getInstance().boardHeight;
    int width = GlobalSettings::getInstance().boardWidth;

    int freeSea = 0;

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {

            bool isFarFromNewShip = true;
            for(auto neigh: board->getCellPtr({i, j})->getNeighbours()) {
                for (auto shipsCell: newShipCells) {
                    if(board->getCellPtr(neigh) == shipsCell)
                        isFarFromNewShip = false;
                }
            }

            if (board->getCellPtr({i, j})->isOkToPlaceShip() && isFarFromNewShip)
                freeSea++;
        }
    }

    return freeSea;
}

std::vector<Cell*> GodBot::getNewShipCells(SimpleShip::Type type, int size) {

    std::vector<Cell*> shipCells;
    int bestRating = 0;

    for (int i = 0; i < 10; ++i) {


        std::vector<Cell*> newShipCells;
        while (true) {
            Position upperLeft = getRandomCell();

            const std::vector<Position> directions = {Position(1, 0), Position(0, 1),
                                                      Position(0, -1), Position(-1, 0)};
            Position dir = directions[getRandint(directions.size())];
            newShipCells = ShipFactory::convertPositioning(
                    ShipFactory::generateShipPositions(type, upperLeft, size, dir), *board);
            if (!newShipCells.empty())
                break;
        }

        if(i != 0 && getRandint(4) == 0) {
            //some ships are placed randomly
            break;
        }

        int rating = assessShipsPositioning(newShipCells);

        if(rating > bestRating) {
            shipCells = newShipCells;
            bestRating = rating;
        }
    }

    return shipCells;
}

bool GodBot::attack(Player* enemy) {
    int godBlessing = getRandint(7);

    std::vector<Position> best;
    if (godBlessing == 0) {
        best = chooseEnemyShipCells(*(enemy->board));
    } else {
        best = VeteranBot::chooseBestAttacks(*(enemy->board));
    }

    return enemy->board->attack(best[getRandint(best.size())]);
}

GodBot::GodBot(int index) : Bot(index) {}

std::vector<Position> GodBot::chooseEnemyShipCells(Board& enemyBoard) {
    std::vector<Position> shipCells;

    int height = GlobalSettings::getInstance().boardHeight;
    int width = GlobalSettings::getInstance().boardWidth;

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (enemyBoard.getCellPtr({i, j})->isShip() && enemyBoard.getCellPtr({i, j})->isOkToAttack()) {
                shipCells.emplace_back(i, j);
            }
        }
    }
    return shipCells;
}
