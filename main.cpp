//#include "GameMaster.h"
//#include "ConsoleLibrary/ConsoleDisplayer.h"
#include "Simplest_GUI.cpp"
#include "iostream"
using namespace std;
int main() {
    Board board(9, 9);
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            board.cells[i][j].state = (Cell::State) (rand() % 5);
            cout << board.cells[i][j].state << ' ';
        }
        cout << endl;
    }
    Simplest_GUI gui;
    gui.displayBoard(board, true);
    return 0;
}