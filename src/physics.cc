#include <cmath>

#include "physics.hh"

void apply_collisions(float& axis, float dx, area& a, std::vector<area>& areas)
{
    auto i = areas.cbegin();
    while (i != areas.cend())
    {
        while (detect_collision(a, *i))
            /* We need /2 because of float rounding behavior */
            axis -= dx/fmax(dx, -dx)/2;
        ++i;
    }

}

void apply_physics(sarray<vectwo>& dirs, sarray<area>& areas,
        sarray<float>& speeds)
{
    for (auto &it : dirs)
    {
        int id = it.first;
        vectwo& dir = it.second;
        auto& a = areas[id];

        float angle = std::atan2(dir.x, dir.y);
        float dx = sin(angle) * std::abs(dir.x) * speeds[id];
        float dy = cos(angle) * std::abs(dir.y) * speeds[id];

        auto fn = std::bind(is_near, 100, a, std::placeholders::_1);
        std::vector<area> nearbys = areas.filter_vec(fn);

        a.x += dx;
        apply_collisions(a.x, dx, a, nearbys);
        a.y += dy;
        apply_collisions(a.y, dy, a, nearbys);

        a.x = fmax(fmin(a.x, 800 - a.w), 0);
        a.y = fmax(fmin(a.y, 600 - a.h), 0);
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
