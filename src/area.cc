#include "area.hh"

area make_area(float x, float y, float h, float w)
{
    area area;
    area.x = x;
    area.y = y;
    area.h = h;
    area.w = w;
    return area;
}
