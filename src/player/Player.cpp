#include "Player.h"
#include "src/settings/GlobalSettings.h"

bool Player::isAlive() {
    return board->deadShipCount() != board->shipCount();
}

void Player::fillBoard() {
    BoardBuilder::getInstance().fillShips(this, board.get());
}

std::string Player::getName() const {
    return GlobalSettings::getInstance().playerSettings[index].name;
}

Player::Player(int idx) : index(idx),
                          board(BoardBuilder::getInstance().constructEmptyRectangleBoard()) {
    if (GlobalSettings::getInstance().islandSize > 0) {
        BoardBuilder::getInstance().addIsland(board.get(),
                                              GlobalSettings::getInstance().islandSize);
    }
}
