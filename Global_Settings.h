#pragma once
#include <vector>
#include "Player_Settings.h"

using std::vector;

struct Global_Settings {
    vector<Player_Settings> playerSettings;
    static Global_Settings& getInstance() {
        static Global_Settings obj;
        return obj;
    }

private:
    Global_Settings() = default;
};

