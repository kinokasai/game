#pragma once

#include <vector>

struct state;

enum PlayerEvent
{
    Stop,
    Left,
    Right,
    Up,
    Down,
    Run,
    Walk,
    AIWalk
};

using pevents = std::vector<std::pair<int, PlayerEvent>>;

void apply_events(struct state& state);

#include "state.hh"
