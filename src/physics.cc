#include <cmath>

#include "physics.hh"

void apply_physics(sarray<vectwo>& dirs, sarray<area>& areas,
        sarray<float>& speed)
{
    for (auto &it : dirs)
    {
        int id = it.first;
        vectwo& dir = it.second;
        auto& a = areas[id];

        float angle = std::atan2(dir.x, dir.y);
        float dx = sin(angle) * std::abs(dir.x) * speed[id];
        float dy = cos(angle) * std::abs(dir.y) * speed[id];

        a.x += dx;
        if (a.x < 0)
            a.x = 0;
        else if (a.x + a.w > 800)
            a.x = 800 - a.w;
        a.y += dy;
        if (a.y < 0)
            a.y = 0;
        else if (a.y + a.h > 600)
            a.y = 600 - a.h;
    }

    dirs.clear();
}
