#pragma once

#include <vector>

#include "area.hh"
#include "controller.hh"
#include "pevents.hh"
#include "sarray.hh"

struct state
{
    sarray<area> areas;
    sarray<struct controller> controllers;
    std::vector<std::pair<int, PlayerEvent>> pevents;
};

state make_state();
