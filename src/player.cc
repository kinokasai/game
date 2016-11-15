#include "id.hh"
#include "player.hh"

/* Don't forget to pass controller id here */

void make_player(state& state)
{
    int id = new_id();
    state.areas.insert(id, make_area(0, 0,  20, 20));
    state.speeds.insert(id, make_speed(3.f));
    make_player_controller(id, state);
    state.colors.insert(id, 2);
    state.player_id = id;
    state.names.insert(id, "Player 1");
}

void print_scores(state& state)
{
    std::cout << "\n --- \n\n";
    for (auto& pair : state.scores)
    {
        int id = pair.first;
        std::cout << state.names[id] << " has " << pair.second << " money.\n";
    }
    std::cout << "\n --- \n";
}
