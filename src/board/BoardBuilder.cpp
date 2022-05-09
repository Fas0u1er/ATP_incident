#include "BoardBuilder.h"
#include "RectangleBoard.h"
#include "src/settings/GlobalSettings.h"
#include "src/ship/ShipFactory.h"
#include "Position.h"
#include "Cell.h"

#include "memory"
#include "random"

BoardBuilder& BoardBuilder::getInstance() {
    static BoardBuilder instance;
    return instance;
}

std::unique_ptr<Board> BoardBuilder::constructEmptyRectangleBoard() {
    auto board = std::make_unique<RectangleBoard>();
    board->width = GlobalSettings::getInstance().boardWidth;
    board->height = GlobalSettings::getInstance().boardHeight;
    board->ships = {};
    board->cells = std::vector<std::vector<Cell>>(board->height);

    for (int i = 0; i < board->height; ++i) {
        board->cells.reserve(board->width);
        for (int j = 0; j < board->width; ++j) {
            board->cells[i].emplace_back(board.get(), Position(i, j));
        }
    }
    return board;
}

void BoardBuilder::fillShips(Player* player, Board* board) {
    auto& globalSettings = GlobalSettings::getInstance();
    auto shipFactory = ShipFactory::getInstance();
    for (const auto& [type, sizes] : globalSettings.ships) {
        for (auto size : sizes) {
            Ship* ship = shipFactory.constructSimpleShip(player, type, size);
            board->insertShip(ship);
        }
    }
}

int getRandint(int range, std::mt19937& gen) {
    return std::uniform_int_distribution<>(0, range - 1)(gen);
}


void BoardBuilder::addIsland(Board* board, int islandSize) {
    std::mt19937 gen((std::random_device()()));

    Position islandRoot = {getRandint(GlobalSettings::getInstance().boardHeight, gen),
                           getRandint(GlobalSettings::getInstance().boardWidth, gen)};

    Position centre = {GlobalSettings::getInstance().boardHeight / 2,
                       GlobalSettings::getInstance().boardWidth / 2};

    islandRoot = (islandRoot + centre) / 2;

    std::vector<Position> islandBorder = {islandRoot};

    for (int i = 0; i < islandSize; ++i) {
        Cell* newIslandCell = board->getCellPtr(islandBorder[getRandint(islandBorder.size(), gen)]);
        if (newIslandCell->getState() == Cell::island) {
            --i;
            continue;
        }
        newIslandCell->setState(Cell::island);
        for (auto neigh : newIslandCell->getNeighbours()) {
            islandBorder.push_back(neigh);
        }
    }
}
