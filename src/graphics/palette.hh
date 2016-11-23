#pragma once

#include "color.hh"
#include "state.hh"

std::vector<color> make_palettes();
color get_color(int idx, state& state);
