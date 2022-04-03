#include "src/player/ConsolePlayer.h"
#include "src/settings/GlobalSettings.h"
#include "src/board/Position.h"

ConsolePlayer::ConsolePlayer(int idx, GUIInterface* gui) : Player(idx), gui(gui) {}

void ConsolePlayer::fillBoard() {
    BoardBuilder::getInstance().fillShips(this, &board);
}

void ConsolePlayer::attack(Player* enemy) {
    Position attackCoordinates = gui->getAttack(*this, enemy->board);
    enemy->board.attack(attackCoordinates);
}

std::vector<Cell*> ConsolePlayer::getNewShipCells(Ship::Type type, int size) {
    return gui->getShip(*this, type, size);
}

bool ConsolePlayer::isAlive() {
    return board.deadShipCount() != board.shipCount();
}
