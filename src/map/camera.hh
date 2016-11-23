#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

struct level;
struct state;

struct camera
{
    float x;
    float y;
    float max_x;
    float max_y;
    float win_x;
    float win_y;
    float gap;
};

struct camera make_default_camera(level& level, sf::RenderWindow& window);
void move_camera(state& state);

#include "level.hh"
#include "state.hh"
