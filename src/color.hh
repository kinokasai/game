#pragma once

#include <string>

struct color
{
    float r;
    float g;
    float b;
};

color make_color(float r, float g, float b);
color make_color_hex(unsigned int num);
color make_color_hstring(const std::string& num);
