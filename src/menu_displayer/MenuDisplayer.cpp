#include <cassert>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <functional>

#include "MenuDisplayer.h"
#include "src/GUI/GUI.h"
#include "src/settings/GlobalSettings.h"
#include "src/settings/PlayerSettings.h"
#include "src/settings/Setting.h"

MenuDisplayer::MenuDisplayer(GUI& gui) : gui(gui) {}

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
                globalSettingsMenu();
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
    static std::vector<std::string> options{
        "Exit already",
        "Go back",
    };
    int choice = gui.displayOptions("You sure, buddy?", options);
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

    auto& globalSettings = GlobalSettings::getInstance();
    while (true) {
        std::vector<std::string> options;
        for (auto& playerSetting: globalSettings.playerSettings) {
            options.emplace_back(playerSetting.name);
        }
        options.emplace_back("Go back");
        int choice = gui.displayOptions("Which player options would you like to change?", options);
        if (choice == options.size() - 1)
            return;
        alterPlayerSettings(globalSettings.playerSettings[choice]);

    }
}

void MenuDisplayer::globalSettingsMenu() {
    static std::vector<std::string> options{
        "Board settings",
        "Ships",
        "Number of players",
        "Go back",
    };
    //Todo: Maybe display current?
    while (true) {
        int choice = gui.displayOptions("What would you like to change?", options);
        switch (choice) {
            case 0: {
                boardSettings();
                break;
            }
            case 1: {
                shipSettings();
                break;
            }
            case 2: {
                playerNumberSettings();
                break;
            }
            case 3: {
                return;
            }
            default:throw std::logic_error("Wrong choice in global settings menu");
        }
    }
}

void MenuDisplayer::boardSettings() {
    auto& globalSettings = GlobalSettings::getInstance();
    std::vector<Setting*> settings;
    settings.emplace_back(
        new ConcreteSetting<int>("Height", globalSettings.boardHeight)
    );
    settings.emplace_back(
        new ConcreteSetting<int>("Width", globalSettings.boardWidth)
    );
    gui.displaySettings("Board settings:", settings);
}

void MenuDisplayer::shipSettings() {
    auto& globalSettings = GlobalSettings::getInstance();
    std::vector<Setting*> settings;
    for (int i = 0; i < Ship::typeToString.size(); ++i) {
        settings.emplace_back(new ConcreteSetting<std::vector<int>>
                                  (Ship::typeToString[i],
                                   globalSettings.ships[static_cast<Ship::Type>(i)]));
    }
    gui.displaySettings("Ship settings:", settings);
}

void MenuDisplayer::playerNumberSettings() {
    auto& globalSettings = GlobalSettings::getInstance();
    std::vector<Setting*> settings;
    settings.emplace_back(new ConcreteSetting<int>("Number of players", globalSettings.playerNumber));
    gui.displaySettings("", settings);
    globalSettings.resize(globalSettings.playerNumber);
}
void MenuDisplayer::alterPlayerSettings(PlayerSettings& playerSettings) {
    std::vector<Setting*> settings;
    settings.emplace_back(new ConcreteSetting<std::string>("Name", playerSettings.name));
    int workaround = static_cast <int>(playerSettings.type);
    settings.emplace_back(new ConcreteSetting<int>(
        "Type (0 for human, 1 for Rookie Bot,\n 2 for Veteran Bot, 3 for God Bot)",
        workaround));

    gui.displaySettings("Choose new name and a type for the player", settings);

    playerSettings.type = static_cast <PlayerSettings::Type> (workaround);

}
