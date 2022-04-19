#include "BoardBuilder.h"
#include "RectangleBoard.h"
#include "src/settings/GlobalSettings.h"
#include "src/ship/ShipFactory.h"
#include "Position.h"
#include "Cell.h"
#include "memory"

BoardBuilder& BoardBuilder::getInstance() {
    static BoardBuilder instance;
    return instance;
}

std::unique_ptr <Board> BoardBuilder::constructEmptyRectangleBoard() {
    auto board = std::make_unique<RectangleBoard>();
    board->width = GlobalSettings::getInstance().boardWidth;
    board->height = GlobalSettings::getInstance().boardHeight;
    board->ships = {};
    board->cells = std::vector<std::vector<Cell>>(board->height, std::vector<Cell>(board->width));

    for (int i = 0; i < board->height; ++i) {
        for (int j = 0; j < board->width; ++j) {
            board->cells[i][j] = Cell(board.get(), {i, j});
        }
    }
    return board;
}

void BoardBuilder::fillShips(Player* player, Board* board) {
    auto& globalSettings = GlobalSettings::getInstance();
    auto shipFactory = ShipFactory::getInstance();
    for (const auto& [type, sizes]: globalSettings.ships) {
        for (auto size: sizes) {
            Ship* ship = shipFactory.constructSimpleShip(player, type, size);
            board->insertShip(ship);
        }
    }
}