#include "chest.hh"
#include "id.hh"

void make_chest(float x, float y, int value, state& state)
{
    int id = new_id();
    std::cout << "Created chest id " << id << std::endl;
    state.areas.insert(id, make_area(x, y, 10, 10));
    state.colors.insert(id, make_color_hex(0xD15FEE));
    state.values.insert(id, value);
    state.entities.push_back(id);
    state.on_collides.insert(id, on_collide_chest);
    state.names.insert(id, "Chest");
}

void delete_chest(const int id, state& state)
{
    state.areas.erase(id);
    state.colors.erase(id);
    state.values.erase(id);
    state.entities.erase(std::find(state.entities.begin(), state.entities.end(), id));
    state.on_collides.erase(id);
}

void on_collide_chest(const std::pair<int, int>& ids, state& state)
{
    state.scores[ids.first] += state.values[ids.second];
    Logger::log().log_score_increase(ids.first, state);
    delete_chest(ids.second, state);
}
