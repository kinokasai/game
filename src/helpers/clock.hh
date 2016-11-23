#pragma once

#include <SFML/System/Clock.hpp>

struct GameClock
{
    GameClock();
    static sf::Clock& clock();
};
