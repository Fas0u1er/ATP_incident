#pragma once

class GUI;
class PlayerSettings;

class MenuDisplayer {
    GUI& gui;


    void exitMenu();
    void settingsMenu();
    void globalSettingsMenu();
    void playerSpecificSettings();
    void boardSettings();
    void shipSettings();
    void playerNumberSettings();
    void alterPlayerSettings(PlayerSettings&);
public:
    explicit MenuDisplayer(GUI& gui);
    void startingMenu();
};