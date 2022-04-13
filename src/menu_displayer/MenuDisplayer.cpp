#include <cassert>
#include <stdexcept>
#include <iostream>

#include "MenuDisplayer.h"
#include "src/GUI/GUIInterface.h"
MenuDisplayer::MenuDisplayer(GUIInterface& gui) : gui(gui) {}

void MenuDisplayer::startingMenu() {
    static std::vector<std::string> options{
        "Play",
        "Settings",
        "Exit"
    };
    while (true) {
        int choice = gui.displayOptions("Choose Your Destiny", options);
        switch (choice) {
            case 0: return;
            case 1: {
                settingsMenu();
                break;
            }
            case 2: {
                exitMenu();
                break;
            }
            default: throw std::logic_error("Wrong choice in main menu");
        }
    }
}
void MenuDisplayer::settingsMenu() {
    static std::vector<std::string> options{
        "Global",
        "Player-Specific",
        "Go back",
    };
    while (true) {
        int choice = gui.displayOptions("Choose Your Destiny", options);
        switch (choice) {
            case 0: {
                globalSettings();
                break;
            }
            case 1: {
                playerSpecificSettings();
                break;
            }
            case 2: {
                return;
            }
            default: throw std::logic_error("Wrong choice in settings menu");
        }
    }
}
void MenuDisplayer::exitMenu() {
    int choice = gui.displayOptions("You sure, buddy?", {
        "Exit already",
        "Go back",
    });
    switch (choice) {
        case 0: {
            exit(0);
        }
        case 1: {
            return;
        }
        default: throw std::logic_error("Wrong choice in exit menu");
    }
}
void MenuDisplayer::playerSpecificSettings() {
    std::cout << "In " << __PRETTY_FUNCTION__ << std::endl;
}
void MenuDisplayer::globalSettings() {
    std::cout << "In " << __PRETTY_FUNCTION__ << std::endl;
}
