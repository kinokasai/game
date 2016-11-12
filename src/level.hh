#pragma once

#include "area.hh"
#include "color.hh"
#include "sarray.hh"
#include "state.hh"

struct level
{
    int h;
    int w;
    std::vector<char> tilemap;
    int wall_size;
};

void load_level(const level& level, state& state);
level make_level();
