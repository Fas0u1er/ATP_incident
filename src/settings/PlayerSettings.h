#pragma once
#include <string>

struct PlayerSettings {
    enum Type{
        human, bot
    };
    std::string name;
    Type type;
};

