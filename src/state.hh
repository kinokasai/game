#pragma once

#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <vector>

#include "area.hh"
#include "ai_component.hh"
#include "camera.hh"
#include "color.hh"
#include "controller.hh"
#include "pevents.hh"
#include "sarray.hh"
#include "speed.hh"
#include "vectwo.hh"

struct state
{
    state();
    sarray<area> areas;
    sarray<ai_component> ai_components;
    sarray<color> colors;
    sarray<std::function<void(int, state& state)>> controls;
    sarray<vectwo> dirs;
    sarray<std::string> names;
    sarray<std::function<
        void(const std::pair<int, int>& ids, state& state)>> on_collides;
    sarray<int> scores;
    sarray<speed> speeds;
    sarray<int> values;

    std::vector<std::pair<int, PlayerEvent>> pevents;
    std::vector<int> controlled;
    std::vector<int> entities;
    std::vector<level> levels;
    std::vector<int> moved;
    std::vector<int> solids;
    camera cam;
    int player_id;
    bool lost;
};

state make_state();
void init_game(state& state, sf::RenderWindow& window);
