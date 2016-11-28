#include "controller.hh"
#include "enemy.hh"
#include "id.hh"

void make_enemy(float x, float y, state& state)
{
    int id = new_id();
    state.areas.insert(id, make_area(x, y, 20, 20));
    state.colors.insert(id, 3);
    make_ai_controller(id, state);
    state.entities.push_back(id);
    state.speeds.insert(id, make_speed(2.f));
    state.types.insert(id, Type::Guard);
    state.names.insert(id, "Guard " + std::to_string(id));
}
