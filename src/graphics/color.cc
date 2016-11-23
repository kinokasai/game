#include "color.hh"

color make_color(float r, float g, float b)
{
    color color;
    color.r = r;
    color.g = g;
    color.b = b;
    return color;
}

inline
color make_color_hstring(const std::string& num)
{
    return make_color_hex(std::stoul(num, nullptr, 16));
}

color make_color_hex(unsigned int num)
{
    struct color color;
    color.r = ((num >> 16) & 0xFF) / 255.0;
    color.g = ((num >> 8) & 0xFF) / 255.0;
    color.b = (num & 0xFF) / 255.0;
    return color;
}
