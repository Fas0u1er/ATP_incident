#pragma once
class GUI_Interface {
private:
    GUI_Interface() = default;
public:
    static GUI_Interface& getInstance() {
        static GUI_Interface gui;
        return gui;
    }
    virtual ~GUI_Interface() = default;
};
