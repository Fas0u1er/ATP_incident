#include "BoardBuilder.h"

BoardBuilder& BoardBuilder::getInstance() {
    static BoardBuilder instance;
    return instance;
}

Board BoardBuilder::constructEmptyBoard() {
    Board brd;
    brd.width = GlobalSettings::getInstance().boardWidth;
    brd.height = GlobalSettings::getInstance().boardHeight;
    brd.ships = {};
    brd.cells = std::vector<std::vector<Cell>> (brd.width, std::vector<Cell>(brd.height));

    for(int i = 0; i < brd.width; ++i) {
        for (int j = 0; j < brd.height; ++j) {
            brd.cells[i][j] = Cell(&brd, Position({i, j}));
        }
    }

    return brd;
}

void BoardBuilder::fillShips(Player* player, Board* brd) {
    for(auto type: GlobalSettings::getInstance().shipTypes) {
        Ship ship = ShipFactory::getInstance().constructShip(player, type);
        brd->insertShip(ship);
    }
}