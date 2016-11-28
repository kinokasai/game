#include <iostream>

#include "bump.hh"
#include "level.hh"
#include "palette.hh"
#include "state.hh"

state::state()
    : areas("areas"), ai_components("ai_components"),
      colors("colors"),
      controls("controls"),
      dirs("dirs"), delta_moves("delta"),
      names("names"), bumps("bumps"),
      scores("scores"),
      speeds("speeds"), types("types"),
      values("values")
{
    this->lost = false;
    this->palette_colors = make_palettes();
    this->palette = 0;
    this->bumps = init_bumps();
}

state make_state()
{
    state state;
    return state;
}

void init_game(state& state, sf::RenderWindow& window)
{
    state.levels.push_back(make_level());
    load_level(state.levels[0], state);
    state.cam = make_default_camera(state.levels[0], window);
}
