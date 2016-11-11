#include <cstdlib>

#include "color.hh"
#include "id.hh"
#include "randomizer.hh"

void populate(sarray<area>& areas, sarray<color>& colors)
{
    for (int i = 0; i < 5; i++)
    {
        float size = std::rand()%40;
        int id = new_id();
        areas.insert(std::make_pair(id,
            make_area(std::rand()%800, std::rand()%600, size, size)));
        colors.insert(id, make_color(.8, .2, .2));
    }
}
