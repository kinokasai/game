#pragma once

#include "state.hh"

void apply_collisions(float& axis, float dx, area& a, sarray<area>& areas);

void apply_physics(sarray<vectwo>& dirs, sarray<area>& areas,
        sarray<float>& speeds);

char detect_collision(const area& a, const area& two);
