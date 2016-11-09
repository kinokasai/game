#pragma once
#include <GL/glew.h>
#include <GL/gl.h>
#include <SFML/Graphics.hpp>

struct renderer
{
    GLuint program;
};

void draw_entities(renderer& rendr, sf::RenderWindow& window);
renderer init_renderer();
