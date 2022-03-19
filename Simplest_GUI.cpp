#include "vector"
#include "iostream"
#include "string"

#include "Board.h"
#include "Simplest_GUI.h"

using std::vector;
using std::string;
using std::cout;
using std::wcout;
using std::cin;

class Simplest_GUI : GUI_Interface {
private:
    static int getInt() {
        int choice;
        while (true) {
            string choice_string;
            cin >> choice_string;
            try {
                choice = std::stoi(choice_string);
                break;
            }
            catch (std::invalid_argument& s) {
                cout << "Incorrect input. Try again";
            }
        }
        return choice;
    }
public:
    static int displayOptions(const vector<string>& options) {
        for (int i = 1; i <= options.size(); ++i) {
            cout << i << ". " << options[i] << '\n';
        }
        cout << "Choose!\n";
        int choice = getInt();
        return choice;
    }

    static void displayBoard(const Board& board, bool isMine) {
        for (int i = 0; i < board.height; ++i) {
            for (const auto& cell: board.cells[i]) {
                wchar_t toPrint;
                switch (cell.state) {
                    case Cell::sea:
                        toPrint = '~';
                        break;
                    case Cell::deadSea:
                        toPrint = 'O';
                        break;
                    case Cell::ship:
                        toPrint = isMine ? L'\u9632' : '~';
                        break;
                    case Cell::attackedShip:
                        toPrint = L'\u9707';
                        break;
                    case Cell::deadShip:
                        toPrint = 'X';
                        break;
                }
                wcout << toPrint;
            }
            cout << '\n';
        }
    }
};

