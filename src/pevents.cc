#include <iostream>
#include "pevents.hh"
#include <csignal>

void apply_events(struct state& state)
{
    for (auto& it : state.pevents)
    {
        auto event = it.second;
        auto id = it.first;
        float xdir = 0;
        float ydir = 0;
        if (event == PlayerEvent::Left)
            xdir = -1;
        if (event == PlayerEvent::Right)
            xdir = 1;
        if (event == PlayerEvent::Up)
            ydir = -1;
        if (event == PlayerEvent::Down)
            ydir = 1;

        if (xdir || ydir)
        {
            vectwo vdir = make_vectwo(xdir, ydir);
            auto it = state.dirs.find(id);
            if (it != state.dirs.end())
                it->second = add_vectwo(it->second, vdir);
            else
                state.dirs.insert(std::make_pair(id, vdir));
        }
    }
    state.pevents.clear();
}
