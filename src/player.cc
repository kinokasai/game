#include "id.hh"
#include "player.hh"

void make_player(state& state)
{
    int id = new_id();
    state.areas.insert(id, make_area(0, 0,  20, 20));
    state.speeds.insert(id, 3.f);
    state.controllers.insert(id, make_controller(true, 0, 0));
}
