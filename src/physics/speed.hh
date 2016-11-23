#pragma once

#include <SFML/System/Clock.hpp>

struct speed
{
    float max_speed;
    sf::Clock clock;
};

speed make_speed(float speed);

float get_speed(speed& speed);
