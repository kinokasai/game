#include "vectwo.hh"

vectwo make_vectwo(float x, float y)
{
    vectwo vec;
    vec.x = x;
    vec.y = y;
    return vec;
}

vectwo add_vectwo(const vectwo& a, const vectwo& b)
{
    return make_vectwo(a.x + b.x, a.y + b.y);
}

vectwo scalar_mult(const vectwo& a, float n)
{
    return make_vectwo(a.x * n, a.y * n);
}

vectwo reverse_vectwo(const vectwo& a)
{
    return make_vectwo(-a.x, -a.y);
}
