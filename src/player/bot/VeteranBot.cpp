#include "VeteranBot.h"


std::vector<Cell*> VeteranBot::getNewShipCells(SimpleShip::Type type, int size) {
    while (true) {
        Position upperLeft = get_random_cell();

        const std::vector<Position> directions = {Position(1, 0), Position(0, 1),
                                                  Position(0, -1), Position(-1, 0)};
        Position dir = directions[get_randint(directions.size())];
        auto shipCells = ShipFactory::convertPositioning(
                ShipFactory::generateShipCells(type, upperLeft, size, dir), board);
        if (!shipCells.empty())
            return shipCells;
    }
}

bool VeteranBot::attack(Player* enemy) {
    auto best = chooseBestAttacks(enemy->board);
    return enemy->board.attack(best[get_randint(best.size())]);
}

VeteranBot::VeteranBot(int index) : Bot(index) {}

std::vector<Position> VeteranBot::chooseBestAttacks(Board& boardToAttack) {
    const int INF = 1'000;
    int height = GlobalSettings::getInstance().boardHeight;
    int width = GlobalSettings::getInstance().boardWidth;
    const std::vector<Position> directions =
            {Position(1, 0), Position(0, 1), Position(1, 1), Position(1, -1),
             Position(0, -1), Position(-1, 0), Position(-1, -1), Position(-1, 1)};

    std::vector<Position> bestPossibleAttacks;
    int maxPriority = -INF;

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (!boardToAttack.getCellPtr(Position(i, j))->isOkToAttack()) {
                continue;
            }

            int attackPriority = 0 - static_cast<int>(i == 0) - static_cast<int>(j == 0);
            for (auto dir : directions) {
                auto neighbour = dir + Position{i, j};
                if (!boardToAttack.withinBorders(neighbour)) {
                    continue;
                }

                switch (boardToAttack.getCellPtr(neighbour)->getState()) {
                    case (Cell::deadShip):
                        attackPriority -= INF;
                        break;
                    case (Cell::attackedShip):
                        attackPriority += 4;
                        break;
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

