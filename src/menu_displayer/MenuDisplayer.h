#pragma once

class GUIInterface;

class MenuDisplayer {
    GUIInterface& gui;


    void exitMenu();
    void settingsMenu();
    void globalSettings();
    void playerSpecificSettings();

public:
    explicit MenuDisplayer(GUIInterface& gui);
    void startingMenu();
};