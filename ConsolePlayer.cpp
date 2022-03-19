#include "ConsolePlayer.h"
#include "Global_Settings.h"
#include "Position.h"

void ConsolePlayer::fillBoard(GUI_Interface& gui) {
    int shipsNumber = Global_Settings::getInstance().playerSettings[index].shipsNumber;
    for (int i = 0; i < shipsNumber; ++i) {
        int shipLength = Global_Settings::getInstance().playerSettings[index].shipSize[i];
        std::pair<Position, Position> shipCoordinates = gui.placeShip(board, shipLength);
        Position shipBegin = shipCoordinates.first;
        Position shipEnd = shipCoordinates.second;
        board.addShip(shipBegin, shipEnd);
    }
}

void ConsolePlayer::attack(GUI_Interface& gui, Board& enemyBoard) {
    Position attackCoordinates = gui.getAttack(*this, enemyBoard);
    enemyBoard.attack(attackCoordinates);
}

