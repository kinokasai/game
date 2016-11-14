#pragma once

#include "state.hh"
#include "speed.hh"

void apply_collisions(float& axis, float dx, area& a, std::vector<area>& areas);
std::vector<std::pair<int, int>>  detect_collisions(sarray<area>& areas,
        const std::vector<int>& entities,
        boost::container::flat_set<int> moved, state& state);

void apply_physics(sarray<vectwo>& dirs, sarray<area>& areas,
        sarray<speed>& speeds, level& level, std::vector<int>& solids);
void apply_collisions(state& state);

char detect_collision(const area& a, const area& two);
