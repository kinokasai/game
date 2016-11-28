#pragma once

#include "state.hh"
#include "speed.hh"

void apply_physics(sarray<vectwo>& dirs, sarray<area>& areas,
        sarray<speed>& speeds, level& level,
        std::vector<int>& entities, state& state);
