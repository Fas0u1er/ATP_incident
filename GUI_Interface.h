#pragma once
class GUI_Interface {
private:
    GUI_Interface() = default;
public:
    static GUI_Interface& getInstance() {

    }
    virtual ~GUI_Interface() = default;
};
