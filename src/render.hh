#pragma once
#include <GL/glew.h>
#include <GL/gl.h>
#include <SFML/Graphics.hpp>

#include "sarray.hh"
#include "area.hh"

struct renderer
{
    GLuint program;
};

void draw_entities(renderer& rendr, sf::RenderWindow& window,
        sarray<area> areas);

renderer init_renderer();
