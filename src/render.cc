#include "render.hh"

float scale(int pixels, sf::RenderWindow& win)
{
    int h = win.getSize().x;
    return (0.5 * pixels) / (h / 4);
}
