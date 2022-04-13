#pragma once
#include <string>

struct PlayerSettings {
    enum Type {
        Human, RookieBot, VeteranBot, GodBot
    };
    std::string name;
    Type type;
};

