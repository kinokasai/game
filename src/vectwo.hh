#pragma once

struct vectwo
{
    float x;
    float y;
};

vectwo make_vectwo(float x, float y);
vectwo add_vectwo(vectwo& a, vectwo& b);
