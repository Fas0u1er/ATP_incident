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
