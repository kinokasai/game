#pragma once

#include "area.hh"
#include "color.hh"
#include "sarray.hh"
#include "state.hh"
#include "vectwo.hh"

struct level
{
    int h;
    int w;
    std::vector<char> tilemap;
    std::vector<vectwo> enemy_pos;
    static const int tile_size = 50;
    std::vector<vectwo> chest_pos;
    std::vector<int> values;
};

vectwo get_empty_spot(level& level);

inline
float map_to_pixel(level& level, int x) { return x * level.tile_size;};
vectwo map_to_pixel(level& level, const vectwo& v);
void load_level(const level& level, state& state);
level make_level();
