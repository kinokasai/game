#pragma once
#include <GL/glew.h>
#include <GL/gl.h>
#include <SFML/Graphics.hpp>

#include "area.hh"
#include "camera.hh"
#include "color.hh"
#include "sarray.hh"

struct renderer
{
    GLuint program;
    GLuint vao;
    GLuint vbo;
    GLuint ebo;
    GLuint vert;
    GLuint frag;
    ~renderer();
};

void draw_entities(renderer& rendr, sf::RenderWindow& window,
        sarray<area>& areas, sarray<color>& colors, camera& cam);

renderer init_renderer();
