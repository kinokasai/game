#include <cmath>
#include <set>

#include "physics.hh"
#include "bump.hh"

void apply_physics(sarray<vectwo>& dirs, sarray<area>& areas,
        sarray<speed>& speeds, level& level,
        std::vector<int>& entities, state& state)
{
    sarray<std::pair<vectwo, vectwo>> moved("moved");
    for (auto& it : dirs)
    {
        int id = it.first;
        vectwo& dir = it.second;
        auto& a = areas[id];

        float angle = std::atan2(dir.x, dir.y);
        float dx = sin(angle) * std::abs(dir.x) * get_speed(speeds[id]);
        float dy = cos(angle) * std::abs(dir.y) * get_speed(speeds[id]);
        vectwo from = make_vectwo(a.x, a.y);
        vectwo delta = make_vectwo(dx +0.0000001f, dy + 0.000001f);
        a.move(delta);
        a.x = fmax(fmin(a.x, level.w * level.tile_size - a.w), 0);
        a.y = fmax(fmin(a.y, level.h * level.tile_size - a.h), 0);
        moved.insert(std::make_pair(id, std::make_pair(from, delta)));
        state.delta_moves.insert(std::make_pair(id, delta));
    }

    dirs.clear();
    std::vector<std::pair<int, int>> collisions;
    for (auto& it : moved)
    {
        int self_id = it.first;
        auto& self_area = areas[self_id];

        std::vector<int> nearbys(10);
        for (auto& id : entities)
        {
            auto& area = areas[id];
            if (is_near(100, self_area, area) && detect_bump(self_area, area))
                collisions.emplace_back(std::make_pair(self_id, id));
        }
    }

    type_map type_ids;
    for (auto& it : collisions)
    {
        int xid = it.first;
        int yid = it.second;
        bump(xid, yid, state);
    }
    state.delta_moves.clear();
}
