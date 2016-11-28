#pragma once

#include <boost/container/flat_set.hpp>
#include <unordered_map>
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
#include "type.hh"
#include "vectwo.hh"

using type_map = std::unordered_multimap<Type, int>;
using bump_func = std::function<void(type_map&, state&)>;

struct state
{
    state();
    sarray<area> areas;
    sarray<ai_component> ai_components;
    sarray<int> colors;
    sarray<std::function<void(int, state& state)>> controls;
    sarray<vectwo> dirs;
    sarray<vectwo> delta_moves;
    sarray<std::string> names;
    sarray<bump_func> bumps;
    sarray<int> scores;
    sarray<speed> speeds;
    sarray<Type> types;
    sarray<int> values;

    std::vector<std::pair<int, PlayerEvent>> pevents;
    std::vector<int> controlled;
    std::vector<int> entities;
    std::vector<color> palette_colors;
    std::vector<level> levels;
    boost::container::flat_set<int> moved;
    std::vector<int> solids;
    camera cam;
    int player_id;
    int palette;
    bool lost;
};

state make_state();
void init_game(state& state, sf::RenderWindow& window);
