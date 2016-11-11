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
};

void load_level(const level& level, state& state);
level make_level();
