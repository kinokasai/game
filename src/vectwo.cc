#include "vectwo.hh"

vectwo make_vectwo(float x, float y)
{
    vectwo vec;
    vec.x = x;
    vec.y = y;
    return vec;
}

vectwo add_vectwo(vectwo& a, vectwo& b)
{
    return make_vectwo(a.x + b.x, a.y + b.y);
}
