#include "HumanPlayer.h"
#include "src/board/BoardBuilder.h"
#include "src/board/Position.h"
#include "src/GUI/GUI.h"

HumanPlayer::HumanPlayer(int index, GUI* gui) : Player(index), gui(gui) {}


bool HumanPlayer::attack(Player* enemy) {
    Position attackCoordinates = gui->getAttack(*this, *enemy);
    return enemy->board->attack(attackCoordinates);
}

std::vector<Cell*> HumanPlayer::getNewShipCells(SimpleShip::Type type, int size) {
    return gui->placeShip(*this, type, size);
}

