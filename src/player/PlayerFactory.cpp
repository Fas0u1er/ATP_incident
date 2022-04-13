#include "PlayerFactory.h"
#include "src/player/bot/RookieBot.h"
#include "src/player/bot/VeteranBot.h"
#include "src/player/bot/GodBot.h"
#include "src/player/HumanPlayer.h"

Player* PlayerFactory::constructPlayer(PlayerSettings::Type skillLevel, GUIInterface* gui) {
    Player* result;
    switch (skillLevel) {
        case PlayerSettings::Type::RookieBot: result = new RookieBot(playerIndex++);
            break;
        case PlayerSettings::Type::VeteranBot:result = new VeteranBot(playerIndex++);
            break;
        case PlayerSettings::Type::GodBot:result = new GodBot(playerIndex++);
            break;
        case PlayerSettings::Type::Human: result = new HumanPlayer(playerIndex++, gui);
            break;
    }
    result->fillBoard();
    return result;
}
