#pragma once

#include "state.hh"

void make_wall(float x, float y, float h, float w, color color,
        state& state);

void make_enemy(float x, float y, state& state);
