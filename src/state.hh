#pragma once

#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <vector>

#include "area.hh"
#include "camera.hh"
#include "color.hh"
#include "controller.hh"
#include "pevents.hh"
#include "sarray.hh"
#include "vectwo.hh"

struct state
{
    state();
    sarray<area> areas;
    sarray<color> colors;
    sarray<struct controller> controllers;
    sarray<vectwo> dirs;
    sarray<float> speeds;
    std::vector<std::pair<int, PlayerEvent>> pevents;
    std::vector<level> levels;
    camera cam;
    int player_id;
};

state make_state();
void init_game(state& state, sf::RenderWindow& window);
