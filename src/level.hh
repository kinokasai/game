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
    static const int chestnum = 10;
    static const int tile_size = 50;
    float chest_pos[chestnum * 2];
    int values[chestnum];
};

void load_level(const level& level, state& state);
level make_level();
