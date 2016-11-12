#pragma once

#include "state.hh"

void apply_collisions(float& axis, float dx, area& a, std::vector<area>& areas);

void apply_physics(sarray<vectwo>& dirs, sarray<area>& areas,
        sarray<float>& speeds, level& level);

char detect_collision(const area& a, const area& two);
