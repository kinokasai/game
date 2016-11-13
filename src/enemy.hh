#pragma once

#include "state.hh"

void make_enemy(float x, float y, state& state);

void on_collide_enemy(const std::pair<int, int>& ids, state& state);

void delete_enemy(state& state);
