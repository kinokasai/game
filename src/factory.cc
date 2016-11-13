#include "factory.hh"
#include "id.hh"

void make_wall(float x, float y, float h, float w, color color,
        state& state)
{
    int id = new_id();
    state.areas.insert(id, make_area(x, y, h, w));
    state.colors.insert(id, color);
    state.solids.push_back(id);
    state.names.insert(id, "Wall");
}
