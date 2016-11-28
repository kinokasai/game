#include "chest.hh"
#include "id.hh"

void make_chest(float x, float y, int value, state& state)
{
    int id = new_id();
    std::cerr << "Created chest id " << id << std::endl;
    state.areas.insert(id, make_area(x, y, 10, 10));
    state.colors.insert(id, 4);
    state.values.insert(id, value);
    state.entities.push_back(id);
    state.types.insert(id, Type::Chest);
    state.names.insert(id, "Chest");
}

void delete_chest(const int id, state& state)
{
    assert(state.types[id] == Type::Chest);
    state.areas.erase(id);
    state.colors.erase(id);
    state.values.erase(id);
    state.entities.erase(std::find(state.entities.begin(), state.entities.end(), id));
    state.types.erase(id);
}
