#pragma once

#include "state.hh"

void make_chest(float x, float y, int value, state& state);

void on_collide_chest(const std::pair<int, int>& ids, state& state);
