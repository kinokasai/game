#include <iostream>

#include "randomizer.hh"
#include "state.hh"

state make_state()
{
    state state;
    populate(state.areas);
    return state;
}
