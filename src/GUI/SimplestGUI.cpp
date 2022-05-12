#include "SimplestGUI.h"
#include "src/board/Position.h"
#include "src/board/Cell.h"
#include "src/board/RectangleBoard.h"
#include "src/settings/GlobalSettings.h"
#include "src/player/Player.h"
#include "src/ship/ShipFactory.h"
#include "src/settings/Setting.h"

#include <sstream>
#include <cstdlib>
#include <algorithm>


template<typename T>
void SimplestGUI::printElement(T t, const int& width) {
    std::cout << std::left << std::setw(width) << std::setfill(' ') << t;
}
void SimplestGUI::wrongInput(bool waitForEnter) {
    std::cout << "Incorrect input. Try again" << std::endl;
    if (waitForEnter) {
        systemPause();
    }
}
int SimplestGUI::getInt() {
    std::string choice_string;
    while (true) {
        std::cin >> choice_string;
        try {
            int choice = std::stoi(choice_string);
            return choice;
        }
        catch (std::invalid_argument& s) {
            wrongInput(false);
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
        std::cin >> choice;
        choice = static_cast <char> (toupper(choice));
        if (std::find(valid.begin(), valid.end(), choice) == valid.end()) {
            wrongInput(false);
        } else {
            return choice;
        }
    }
}

int countDigits (int x) {
    int counter = 0;
    while(x) {
        x /= 10;
        ++counter;
    }

    return counter;
}

void SimplestGUI::displayBoard(const Board& board, bool isMine) {

    for (int i = 0; i < countDigits(board.width); ++i) {
        std::cout << " ";
    }

    for (int i = 0; i < board.width; ++i) {
        std::cout << i + 1;
    }
    std::cout << "\n";

    for (int i = 0; i < board.height; ++i) {
        for (int j = 0; j < countDigits(board.width) - countDigits(i + 1); ++j) {
            std::cout << " ";
        }
        std::cout << i + 1;
        for (const auto& cell: board.cells[i]) {
            wchar_t toPrint;
            switch (cell.getState()) {
                case Cell::sea:toPrint = '~';
                    break;
                case Cell::deadSea:toPrint = 'O';
                    break;
                case Cell::ship:toPrint = isMine ? '#' : '~';
                    break;
                case Cell::attackedShip:toPrint = '*';
                    break;
                case Cell::deadShip:toPrint = 'X';
                    break;
            }
            std::wcout << toPrint;
        }
        std::wcout << '\n';
    }
}
int SimplestGUI::displayOptions(const std::string& title, const std::vector<std::string>& options) {
    clearScreen();
    std::cout << title << std::endl;
    for (int i = 1; i <= options.size(); ++i) {
        std::cout << i << ". " << options[i - 1] << std::endl;
    }
    std::cout << "Choose!\n";
    while (true) {
        int choice = getInt();
        if (1 <= choice and choice <= options.size())
            return choice - 1;
        else
            wrongInput(false);
    }
}
Position SimplestGUI::getAttack(const Player& player, Player& enemy) {
    clearScreen();
    std::cout << enemy.getName() <<  "'s board" << std::endl;
    displayBoard(*enemy.board, false);
    std::cout << "Your board" << std::endl;
    displayBoard(*(player.board), true);
    std::cout << "Player " << player.getName() << " attack! (first row, then column)" << std::endl;
    while (true) {
        Position attackPosition = get0IndexedPosition();
        if (enemy.board->withinBorders(attackPosition)
            and enemy.board->cells[attackPosition.x][attackPosition.y].isOkToAttack())
            return attackPosition;
        else
            wrongInput(false);
    }
}
void SimplestGUI::displayPlayer(const Player& player, bool isMine) {
//    displayBoard(player.board, isMine);
}
std::vector<Cell*> SimplestGUI::placeShip(Player& player, SimpleShip::Type type, int size) {
    clearScreen();
    displayBoard(*player.board, true);
    std::cout << "Player " << player.getName() << " place a ship" << std::endl;
    std::cout << "Type: " << Ship::typeToString[type] << std::endl;
    std::cout << "Size: " << size << std::endl;
    std::vector<Position> positions;
    while (true) {
        positions.clear();
        if (type == SimpleShip::Type::T ||
            type == SimpleShip::Type::cross) {
            //Cross or T
            Position center;
            std::cout << "Write coordinates of the center of the ship (first row, then column)" << std::endl;
            center = get0IndexedPosition();

            if (type == SimpleShip::Type::cross) {
                //Cross
                positions = ShipFactory::generateCrossShip(center, size);
            } else {
                //T
                std::cout << "Write the orientation of the ship (WASD)" << std::endl;
                auto direction = charToDirection(getChar("WASD"));
                positions = ShipFactory::generateTShip(center, direction, size);
            }
        } else {
            //Square or Line
            std::cout << "Write coordinates of upper-left corner of the ship (first row, then column)" << std::endl;
            Position upperLeft = get0IndexedPosition();
            if (type == SimpleShip::Type::square) {
                positions = ShipFactory::generateSquareShip(upperLeft, size);
            } else {
                //Line
                Position direction(1, 0);
                if (size != 1) {
                    std::cout << "Write the orientation of the ship (SD)" << std::endl;
                    direction = charToDirection(getChar("SD"));
                }
                positions = ShipFactory::generateLineShip(upperLeft, direction, size);
            }
        }

//        for (auto el: positions) {
//            std::cerr << el << std::endl;
//        } //DEBUG

        auto result = ShipFactory::convertPositioning(positions, *player.board);
        if (!result.empty()) {
            return result;
        } else {
            std::cout << "Incorrect Positioning. Try again" << std::endl;
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
std::string SimplestGUI::getNewLine() {
    std::string temp;
    std::cin.ignore();
    std::getline(std::cin, temp);
    std::cin.putback('\n');
    return temp;
}
void SimplestGUI::systemPause() {
    std::cout << "Press enter to continue" << std::endl;
    getNewLine();
}

void SimplestGUI::displaySettings(const std::string& title, std::vector<Setting*>& settings) {
    while (true) {
        clearScreen();
        if (!title.empty())
            std::cout << title << std::endl;
        for (int i = 1; i <= settings.size(); ++i) {
            std::cout << std::to_string(i) << ". " << settings[i - 1]->getDescription() << ": "
                 << settings[i - 1]->toString() << std::endl;
        }
        std::cout
            << "If you want to change any of these, first print the index of the option, then its new value (on one line, whitespace separated).\n"
               "Once you are done, hit enter to exit" << std::endl;
        auto temp = getNewLine();
        if (temp.empty()) //We are done
            return;

        std::stringstream input(temp);

        int index = -1;
        input >> temp;
        try {
            index = std::stoi(temp);
        }
        catch (std::invalid_argument& err) {
            wrongInput(true);
            continue;
        }
        index--;
        if (index >= settings.size() || index < 0) {
            wrongInput(true);
            continue;
        }
        if (!settings[index]->parseFromInput(input)) {
            wrongInput(true);
            continue;
        }
    }
}

void SimplestGUI::showResults(const Player& winner, int roundsPlayed) {
    std::cout <<"Results: \n";

    std::cout << winner.getName() << " won after " + std::to_string(roundsPlayed) + " rounds\n";
}

void SimplestGUI::finishWork() {
    std::cout << "Press enter to exit\n";

    getNewLine();
}
