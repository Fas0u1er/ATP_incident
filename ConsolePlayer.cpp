#include "ConsolePlayer.h"
#include "Global_Settings.h"

void ConsolePlayer::fillBoard(GUI_Interface& gui) {
    int shipsNumber = Global_Settings::getInstance().playerSettings[playerIdx].shipsNumber;
    for (int i = 0; i < shipsNumber; ++i) {
        int shipLength = Global_Settings::getInstance().playerSettings[playerIdx].shipSize[i];
        auto shipCoordinates = gui.placeShip(board, shipLength);
        std::pair<int, int> shipBegin = shipCoordinates.first;
        std::pair<int, int> shipEnd = shipCoordinates.second;
        board.addShip(shipBegin.first, shipBegin.second, shipEnd.first, shipEnd.second);
    }
}

void ConsolePlayer::attack(GUI_Interface&, Board& enemyBoard) {
    std::pair<int, int> attackCoordinates = gui.getAttack(enemyBoard);
    enemyBoard.attack(attackCoordinates.first, attackCoordinates.second);
}

