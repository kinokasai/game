#pragma once

#include <vector>

#include "area.hh"
#include "controller.hh"
#include "pevents.hh"
#include "sarray.hh"
#include "vectwo.hh"

struct state
{
    sarray<area> areas;
    sarray<struct controller> controllers;
    sarray<vectwo> dirs;
    sarray<float> speeds;
    std::vector<std::pair<int, PlayerEvent>> pevents;
};

state make_state();
