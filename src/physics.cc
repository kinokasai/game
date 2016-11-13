#include <cmath>

#include "physics.hh"

void apply_collisions(float& axis, float dx, area& a, std::vector<area>& areas)
{
    auto i = areas.cbegin();
    while (i != areas.cend())
    {
        while (detect_collision(a, *i))
            /* We need /2 because of float rounding behavior */
            /* It's basically adding 0.5f */
            axis -= dx/fmax(dx, -dx)/4.0f;
        ++i;
    }

}

void apply_collisions(sarray<area>& areas, const std::vector<int>& entities,
        std::vector<int>& moved, state& state)
{
    for (auto &it : moved)
    {
        auto& a = areas[it];

        std::vector<std::pair<int, area>> collides;
        for (auto& id : entities)
        {
            auto& area = areas[id];
            if (is_near(100, a, area) && detect_collision(a, area))
            {
                auto pair = std::make_pair(it, id);
                LOGC(pair, state);
                state.on_collides[id](pair, state);
            }
        }
    }
    moved.clear();
}

void apply_physics(sarray<vectwo>& dirs, sarray<area>& areas,
        sarray<speed>& speeds, level& level, std::vector<int>& solids)
{
    for (auto &it : dirs)
    {
        int id = it.first;
        vectwo& dir = it.second;
        auto& a = areas[id];

        float angle = std::atan2(dir.x, dir.y);
        float dx = sin(angle) * std::abs(dir.x) * get_speed(speeds[id]);
        float dy = cos(angle) * std::abs(dir.y) * get_speed(speeds[id]);

        std::vector<area> nearbys;
        for (auto& id : solids)
        {
            auto& area = areas[id];
            if (is_near(100, a, area))
                nearbys.push_back(area);
        }

        a.x += dx;
        apply_collisions(a.x, dx, a, nearbys);
        a.y += dy;
        apply_collisions(a.y, dy, a, nearbys);

        a.x = fmax(fmin(a.x, level.w * level.tile_size - a.w), 0);
        a.y = fmax(fmin(a.y, level.h * level.tile_size - a.h), 0);
    }

    dirs.clear();
}

inline
char detect_collision(const area& a, const area& two)
{
    return (a.x + a.w >= two.x &&
            two.x + two.w >= a.x) &&
        a.y + a.h >= two.y &&
        two.y + two.h >= a.y;
}
