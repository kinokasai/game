#pragma once
struct area
{
    float x;
    float y;
    float h;
    float w;
    bool operator!=(area& two);
    bool operator==(area& two);
};

area make_area(float x, float y, float h, float w);

bool is_near(float radius, area& one, area& two);
