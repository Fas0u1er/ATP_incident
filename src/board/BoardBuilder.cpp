#include "BoardBuilder.h"
#include "Board.h"
#include "src/settings/GlobalSettings.h"
#include "src/ship/ShipFactory.h"
#include "Position.h"
#include "Cell.h"

BoardBuilder& BoardBuilder::getInstance() {
    static BoardBuilder instance;
    return instance;
}

Board BoardBuilder::constructEmptyBoard() {
    Board board;
    board.width = GlobalSettings::getInstance().boardWidth;
    board.height = GlobalSettings::getInstance().boardHeight;
    board.ships = {};
    board.cells = std::vector<std::vector<Cell>>(board.height, std::vector<Cell>(board.width));

    for (int i = 0; i < board.height; ++i) {
        for (int j = 0; j < board.width; ++j) {
            board.cells[i][j] = Cell(&board, {i, j});
        }
    }

    return board;
}

void BoardBuilder::fillShips(Player* player, Board* board) {
    auto globalSettings = GlobalSettings::getInstance();
    auto shipFactory = ShipFactory::getInstance();
    for (int i = 0; i < globalSettings.shipsNumber; ++i) {
        Ship* ship = shipFactory.constructShip(player,
                                              globalSettings.shipTypes[i],
                                              globalSettings.shipSize[i]);
        board->insertShip(ship);
    }
}