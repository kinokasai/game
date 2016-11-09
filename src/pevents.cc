#include <iostream>
#include "pevents.hh"
#include <csignal>

void apply_events(struct state& state)
{
    for (auto& it : state.pevents)
    {
        auto event = it.second;
        auto id = it.first;
        if (event == PlayerEvent::Left)
            state.areas[id].x -= 0.1f;
        if (event == PlayerEvent::Right)
            state.areas[id].x += 0.1f;
        if (event == PlayerEvent::Up)
            state.areas[id].y -= 0.1f;
        if (event == PlayerEvent::Down)
            state.areas[id].y += 0.1f;
    }
    state.pevents.clear();
}
