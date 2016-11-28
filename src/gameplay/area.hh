#pragma once

#include "vectwo.hh"

struct area
{
    float x;
    float y;
    float h;
    float w;
    bool operator!=(area& two);
    bool operator==(area& two);
    void move(vectwo delta);
};

area make_area(float x, float y, float h, float w);

bool is_near(float radius, area& one, area& two);
