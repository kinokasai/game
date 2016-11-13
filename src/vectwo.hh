#pragma once

struct vectwo
{
    float x;
    float y;
};

vectwo make_vectwo(float x, float y);
vectwo add_vectwo(const vectwo& a, const vectwo& b);
vectwo scalar_mult(const vectwo& a, float n);
