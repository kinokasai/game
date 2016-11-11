#pragma once
#include <GL/glew.h>
#include <GL/gl.h>
#include <SFML/Graphics.hpp>

#include "area.hh"
#include "color.hh"
#include "sarray.hh"

struct renderer
{
    GLuint program;
};

void draw_entities(renderer& rendr, sf::RenderWindow& window,
        sarray<area>& areas, sarray<color>& colors);

renderer init_renderer();
