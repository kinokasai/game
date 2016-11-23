#pragma once
#include <SFML/System/Clock.hpp>

struct ai_component
{
    sf::Clock clock;
    float seconds;
    int event_x;
    int event_y;
};
