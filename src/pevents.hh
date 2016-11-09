#pragma once

struct state;

enum PlayerEvent
{
    Left,
    Right,
    Up,
    Down
};

void apply_events(struct state& state);

#include "state.hh"
