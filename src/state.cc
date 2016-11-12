#include <iostream>

#include "level.hh"
#include "randomizer.hh"
#include "state.hh"

state::state()
    : areas("areas"), colors("colors"),
      controllers("controllers"),
      dirs("dirs"), speeds("speeds")
{
}

state make_state()
{
    state state;
    populate(state.areas, state.colors);
    return state;
}

void init_game(state& state, sf::RenderWindow& window)
{
    state.levels.push_back(make_level());
    load_level(state.levels[0], state);
    state.cam = make_default_camera(state.levels[0], window);
}
