#include <cstdlib>

#include "id.hh"
#include "randomizer.hh"

void populate(sarray<area>& areas)
{
    for (int i = 0; i < 5; i++)
    {
        float size = std::rand()%40;
        areas.insert(std::make_pair(new_id(),
            make_area(std::rand()%800, std::rand()%600, size, size)));
    }
}
