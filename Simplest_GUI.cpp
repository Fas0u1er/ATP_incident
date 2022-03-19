#include "vector"
#include "iostream"
#include "string"
#include "cassert"
#include "iomanip"

#include "Board.h"
#include "Player.h"
#include "Simplest_GUI.h"

using std::vector;
using std::string;
using std::cout;
using std::wcout;
using std::pair;
using std::endl;
using std::cin;
using std::left;
using std::setw;
using std::setfill;

class Simplest_GUI : public GUI_Interface {
private:

    template<typename T>
    void printElement(T t, const int& width) {
        cout << left << setw(width) << setfill(' ') << t;
    }

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
                cout << "Incorrect input. Try again" << endl;
            }
        }
        return choice;
    }

    static char getChar(const std::vector<char>& valid) {
        char choice;
        while (true) {
            cin >> choice;
            choice = toupper(choice);
            if (std::find(valid.begin(), valid.end(), choice) == valid.end()) {
                cout << "Incorrect input. Try again" << endl;
            } else {
                break;
            }
        }
        return choice;
    }

public:
    void displayBoard(const Board& board, bool isMine) {
        for (int i = 0; i < board.height; ++i) {
            for (const auto& cell: board.cells[i]) {
                wchar_t toPrint;
                switch (cell.state) {
                    case Cell::sea:toPrint = '~';
                        break;
                    case Cell::deadSea:toPrint = 'O';
                        break;
                    case Cell::ship:toPrint = isMine ? 'K' : '~';
                        break;
                    case Cell::attackedShip:toPrint = 'A';
                        break;
                    case Cell::deadShip:toPrint = 'X';
                        break;
                }
                wcout << toPrint;
            }
            wcout << '\n';
        }
    }

    int displayOptions(const vector<string>& options) {
        for (int i = 1; i <= options.size(); ++i) {
            cout << i << ". " << options[i] << '\n';
        }
        cout << "Choose!\n";
        int choice = getInt();
        return choice;
    }

    //Returns {bottom-left corner, upper-right corner}
    pair<pair<int, int>, pair<int, int>> placeShip(const Board& board, int length) {
        cout << "Write coordinates of bottom-left corner of the ship (column, then row)" << endl;
        pair<int, int> blPosition;
        blPosition.first = getInt();
        blPosition.second = getInt();
        cout << "Now write direction (WASD)" << endl;
        static std::vector<char> valid({'W', 'A', 'S', 'D'});
        char cdirection = getChar(valid);
        pair<int, int> direction;
        switch (cdirection) {
            case 'W': direction = {0, 1};
                break;
            case 'A': direction = {-1, 0};
                break;
            case 'S': direction = {0, -1};
                break;
            case 'D': direction = {1, 0};
                break;
            default: assert(false);
        }
        return {blPosition,
                {blPosition.first + direction.first * length,
                 blPosition.second + direction.second * length}};
    }

    pair <int, int> getAttack(const Player& player, const Board& attackedBoard) {
        cout << "Player " << player.index << " attack!" << endl;
        while (true) {
            int x, y;
            x = getInt();
            y = getInt();
        }
    }

    void displayPlayer(const Player& player, bool isMine) {
        displayBoard(player.board, isMine);
    }

};

