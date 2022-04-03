#include "vector"
#include "iostream"
#include "string"
#include "cassert"
#include "iomanip"

#include "src/board/Board.h"
#include "src/player/Player.h"
#include "src/GUI/SimplestGUI.h"
#include "src/board/Position.h"

using std::endl;
using std::cin;
using std::left;
using std::setw;
using std::setfill;
using std::cout;
using std::wcout;

class SimplestGUI : public GUIInterface {
private:

    template<typename T>
    void printElement(T t, const int& width) {
        cout << left << setw(width) << setfill(' ') << t;
    }

    static void wrongInput() {
        cout << "Incorrect input. Try again" << endl;
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
                wrongInput();
            }
        }
        return choice;
    }

    static Position getPosition() {
        Position answer;
        answer.x = getInt();
        answer.y = getInt();
        return answer;
    }

    static char getChar(const std::vector<char>& valid) {
        while (true) {
            char choice;
            cin >> choice;
            choice = toupper(choice);
            if (std::find(valid.begin(), valid.end(), choice) == valid.end()) {
                wrongInput();
            } else {
                return choice;
            }
        }
    }

public:
    void displayBoard(const Board& board, bool isMine) override {
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

    int displayOptions(const vector<string>& options) override {
        for (int i = 1; i <= options.size(); ++i) {
            cout << i << ". " << options[i] << '\n';
        }
        cout << "Choose!\n";
        while (true) {
            int choice = getInt();
            if (0 <= choice and choice < options.size())
                return choice;
            else
                wrongInput();
        }
    }

    //Returns {bottom-left corner, upper-right corner}
    pair<Position, Position> placeShip(const Board& board, int length) override {
        while (true) {
            cout << "Write coordinates of bottom-left corner of the ship (column, then row)" << endl;
            Position blPosition = getPosition();
            cout << "Now write direction (WD)" << endl;
            static std::vector<char> valid({'W', 'D'});
            char cdirection = getChar(valid);
            Position direction;
            switch (cdirection) {
                case 'W': direction = {0, 1};
                    break;
                case 'D': direction = {1, 0};
                    break;
                default: assert(false);
            }
            pair <Position, Position> answer = {blPosition,
                      blPosition + direction * length};
            bool isCorrectPlacement = true;
            int amountOfChecks = length;
            for (Position pos = blPosition; amountOfChecks--; pos += direction) {
                if (not (board.withinBorders(pos) and board.hasNoShipNeighbours(pos))) {
                    isCorrectPlacement = false;
                    break;
                }
            }
            if (isCorrectPlacement) {
                return answer;
            }
            else {
                wrongInput();
            }
        }
    }

    Position getAttack(const Player& player, const Board& attackedBoard) override {
        cout << "Player " << player.index << " attack!" << endl;
        while (true) {
            Position attackPosition = getPosition();
            if (attackedBoard.withinBorders(attackPosition) and attackedBoard.cells[attackPosition.x][attackPosition.y].state == Cell::States::sea)
                return attackPosition;
            else
                wrongInput();
        }
    }

    void displayPlayer(const Player& player, bool isMine) override {
        displayBoard(player.board, isMine);
    }

};

