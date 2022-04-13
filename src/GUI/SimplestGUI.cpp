#include "SimplestGUI.h"
#include "src/board/Position.h"
#include "src/board/Cell.h"
#include "src/board/Board.h"
#include "src/settings/GlobalSettings.h"
#include "src/player/Player.h"
#include "src/ship/ShipFactory.h"

#include <cstdlib>

using std::endl;
using std::cin;
using std::left;
using std::setw;
using std::setfill;
using std::cout;
using std::wcout;

template<typename T>
void SimplestGUI::printElement(T t, const int& width) {
    cout << left << setw(width) << setfill(' ') << t;
}
void SimplestGUI::wrongInput() {
    cout << "Incorrect input. Try again" << endl;
}
int SimplestGUI::getInt() {
    string choice_string;
    while (true) {
        cin >> choice_string;
        try {
            int choice = std::stoi(choice_string);
            return choice;
        }
        catch (std::invalid_argument& s) {
            wrongInput();
        }
    }
}
Position SimplestGUI::get1IndexedPosition() {
    Position answer;
    answer.x = getInt();
    answer.y = getInt();
    return answer;
}

Position SimplestGUI::get0IndexedPosition() {
    return get1IndexedPosition() - Position{1, 1};
}

char SimplestGUI::getChar(const std::string& valid) {
    while (true) {
        char choice;
        cin >> choice;
        choice = static_cast <char> (toupper(choice));
        if (std::find(valid.begin(), valid.end(), choice) == valid.end()) {
            wrongInput();
        } else {
            return choice;
        }
    }
}

void SimplestGUI::displayBoard(const Board& board, bool isMine) {
    for (int i = 0; i < board.height; ++i) {
        for (const auto& cell: board.cells[i]) {
            wchar_t toPrint;
            switch (cell.getState()) {
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
int SimplestGUI::displayOptions(const std::string& title, const vector<string>& options) {
    clearScreen();
    cout << title << endl;
    for (int i = 1; i <= options.size(); ++i) {
        cout << i << ". " << options[i - 1] << '\n';
    }
    cout << "Choose!\n";
    while (true) {
        int choice = getInt();
        if (1 <= choice and choice <= options.size())
            return choice - 1;
        else
            wrongInput();
    }
}
Position SimplestGUI::getAttack(const Player& player, const Board& attackedBoard) {
    clearScreen();
    cout << "Enemy board" << endl;
    //Todo replace attacked board with attacked player
    displayBoard(attackedBoard, false);
    cout << "Your board" << endl;
    displayBoard(player.board, true);
    cout << "Player " << player.getName() << " attack! (first row, then column)" << endl;
    while (true) {
        Position attackPosition = get0IndexedPosition();
        if (attackedBoard.withinBorders(attackPosition)
            and attackedBoard.cells[attackPosition.x][attackPosition.y].isOkToAttack())
            return attackPosition;
        else
            wrongInput();
    }
}
void SimplestGUI::displayPlayer(const Player& player, bool isMine) {
//    displayBoard(player.board, isMine);
}
std::vector<Cell*> SimplestGUI::placeShip(Player& player, Ship::Type type, int size) {
    clearScreen();
    displayBoard(player.board, true);
    cout << "Player " << player.getName() << " place a ship" << endl;
    cout << "Type: " << Ship::typeToString(type) << endl;
    cout << "Size: " << size << endl;
    std::vector<Position> positions;
    while (true) {
        positions.clear();
        if (type == Ship::Type::T ||
            type == Ship::Type::cross) {
            Position center;
            do {
                cout << "Write coordinates of the center of the ship (first row, then column)" << endl;
                center = get0IndexedPosition();
                if (player.board.withinBorders(center))
                    break;
                else
                    wrongInput();
            } while (true);

            if (type == Ship::Type::cross) {
                //Cross
                positions = ShipFactory::generateCrossShip(center, size);
            } else {
                //T
                cout << "Write the orientation of the ship (WASD)" << endl;
                auto direction = charToDirection(getChar("WASD"));
                positions = ShipFactory::generateTShip(center, direction, size);
            }
        } else {
            //Square
            cout << "Write coordinates of upper-left corner of the ship (first row, then column)" << endl;
            Position upperLeft = get0IndexedPosition();
            if (type == Ship::Type::square) {
                positions = ShipFactory::generateSquareShip(upperLeft, size);
            } else {
                //Line
                Position direction(1, 0);
                if (size != 1) {
                    cout << "Write the orientation of the ship (SD)" << endl;
                    direction = charToDirection(getChar("SD"));
                }
                positions = ShipFactory::generateLineShip(upperLeft, direction, size);
            }
        }

        for (auto el: positions) {
            std::cerr << el << endl;
        } //DEBUG

        auto result = ShipFactory::convertPositioning(positions, player.board);
        if (!result.empty()) {
            return result;
        } else {
            cout << "Incorrect Positioning. Try again" << endl;
        }
    }
}
Position SimplestGUI::charToDirection(char c) {
    switch (toupper(c)) {
        case 'W': return {-1, 0};
        case 'A': return {0, -1};
        case 'S': return {1, 0};
        case 'D': return {0, 1};
        default: throw std::logic_error("Incorrect direction char");
    }
}
void SimplestGUI::clearScreen() {
#ifdef _WIN32
    std::system("cls");
#else
    // Assume POSIX
    std::system("clear");
#endif
}
