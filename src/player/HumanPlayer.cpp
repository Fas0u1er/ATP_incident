#include "HumanPlayer.h"
#include "src/board/BoardBuilder.h"
#include "src/board/Position.h"
#include "src/GUI/GUIInterface.h"

HumanPlayer::HumanPlayer(int index, GUIInterface* gui) : Player(index), gui(gui) {}


bool HumanPlayer::attack(Player* enemy) {
    Position attackCoordinates = gui->getAttack(*this, enemy->board);
    return enemy->board.attack(attackCoordinates);
}

std::vector<Cell*> HumanPlayer::getNewShipCells(Ship::Type type, int size) {
    return gui->placeShip(*this, type, size);
}

