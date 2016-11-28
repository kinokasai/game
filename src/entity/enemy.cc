#include "controller.hh"
#include "enemy.hh"
#include "id.hh"

void make_enemy(float x, float y, state& state)
{
    int id = new_id();
    state.areas.insert(id, make_area(x, y, 20, 20));
    state.colors.insert(id, 3);
    //state.controllers.insert(id, make_ia_controller());
    make_ai_controller(id, state);
    state.entities.push_back(id);
    state.speeds.insert(id, make_speed(2.f));
    state.on_collides.insert(id, on_collide_enemy);
    state.names.insert(id, "Guard " + std::to_string(id));
}

void on_collide_enemy(const std::pair<int, int>& ids, state& state)
{
    //if (std::find(state.players.begin(), state.players.end(), ids.first)
    if (ids.first == state.player_id && !state.lost)
    {
        std::cout << "You've been \033[31m DEAD \033[0m\n";
        state.lost = true;
    }
}