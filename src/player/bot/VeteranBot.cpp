#include "VeteranBot.h"

std::vector<Cell*> VeteranBot::getNewShipCells(SimpleShip::Type type, int size) {
    while (true) {
        Position upperLeft = getRandomCell();

        const std::vector<Position> directions = {Position(1, 0), Position(0, 1),
                                                  Position(0, -1), Position(-1, 0)};
        Position dir = directions[getRandint(directions.size())];
        auto shipCells = ShipFactory::convertPositioning(
                ShipFactory::generateShipPositions(type, upperLeft, size, dir),
                *board);
        if (!shipCells.empty())
            return shipCells;
    }
}

bool VeteranBot::attack(Player* enemy) {
    auto best = chooseBestAttacks(*(enemy->board));
    return enemy->board->attack(best[getRandint(best.size())]);
}

VeteranBot::VeteranBot(int index) : Bot(index) {}

std::vector<Position> VeteranBot::chooseBestAttacks(Board& board) {
    const int INF = 1'000;
    int height = GlobalSettings::getInstance().boardHeight;
    int width = GlobalSettings::getInstance().boardWidth;

    std::vector<Position> bestPossibleAttacks;
    int maxPriority = -INF;

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (!board.getCellPtr(Position(i, j))->isOkToAttack()) {
                continue;
            }

            int attackPriority = 0 - static_cast<int>(i == 0 || i == height)
                                 - static_cast<int>(j == 0 || j == width);
            for (auto neighbour : board.getCellPtr(Position(i, j))->getNeighbours()) {
                switch (board.getCellPtr(neighbour)->getState()) {
                    case (Cell::deadShip): {
                        attackPriority -= INF;
                        break;
                    }
                    case (Cell::attackedShip): {
                        attackPriority += 8;
                        break;
                    }

                    case (Cell::island): {
                        attackPriority -= 1;
                        break;
                    }

                    default:
                        break;
                }
            }

            if (attackPriority == maxPriority) {
                bestPossibleAttacks.emplace_back(i, j);
            }

            if (attackPriority > maxPriority) {
                maxPriority = attackPriority;
                bestPossibleAttacks = {{i, j}};
            }
        }
    }

    return bestPossibleAttacks;
}

