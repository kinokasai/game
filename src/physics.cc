#include <cmath>

#include "physics.hh"

void apply_physics(sarray<vectwo>& dirs, sarray<area>& areas,
        sarray<float>& speed)
{
    for (auto &it : dirs)
    {
        int id = it.first;
        vectwo& dir = it.second;

        float angle = std::atan2(dir.x, dir.y);
        float x = sin(angle) * std::abs(dir.x) * speed[id];
        float y = cos(angle) * std::abs(dir.y) * speed[id];

        areas[id].x += x;
        areas[id].y += y;
    }

    dirs.clear();
}
