#pragma once

#include "state.hh"

void apply_collisions(float& axis, float dx, area& a, std::vector<area>& areas);
void apply_collisions(sarray<area>& areas, const std::vector<int>& entities,
        std::vector<int>& moved, state& state);

void apply_physics(sarray<vectwo>& dirs, sarray<area>& areas,
        sarray<float>& speeds, level& level, std::vector<int>& solids);

char detect_collision(const area& a, const area& two);
