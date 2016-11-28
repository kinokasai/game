#include <cmath>

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

void area::move(vectwo delta)
{
    x += delta.x;
    y += delta.y;
}

bool area::operator==(area& two)
{
    return x == two.x && y == two.y
        && h == two.h && w == two.h;
}

bool area::operator!=(area& two)
{
    return !(*this == two);
}

bool is_near(float radius, area& one, area& two)
{
    return std::abs(one.x - two.x) < radius &&
        std::abs(one.y - two.y) < radius && one != two;
}
