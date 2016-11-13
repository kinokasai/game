#include "id.hh"
#include "player.hh"

/* Don't forget to pass controller id here */

void make_player(state& state)
{
    int id = new_id();
    state.areas.insert(id, make_area(0, 0,  20, 20));
    state.speeds.insert(id, make_speed(3.f));
    state.controllers.insert(id, make_controller(true, 0, 0));
    state.colors.insert(id, make_color(0, .6, .8));
    state.player_id = id;
    state.names.insert(id, "Player 1");
}
