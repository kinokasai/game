#include "wall.hh"

void make_wall(float x, float y, float h, float w,
        state& state)
{
    int id = new_id();
    state.areas.insert(id, make_area(x, y, h, w));
    state.colors.insert(id, 1);
    state.solids.push_back(id);
    state.names.insert(id, "Wall");
}
