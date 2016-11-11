#include <iostream>

#include "randomizer.hh"
#include "state.hh"

state::state()
    : areas("areas"), colors("colors"),
      controllers("controllers"),
      dirs("dirs"), speeds("speeds")
{
}

state make_state()
{
    state state;
    populate(state.areas, state.colors);
    return state;
}
