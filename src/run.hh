#pragma once
#include <GL/glew.h>
#include <GL/gl.h>
#include <SFML/Graphics.hpp>
#include "sarray.hxx"

struct state
{
    sarray<sf::Vector2f> pos;
    sarray<sf::Transform> transforms;
};

struct gl_state
{
    GLuint prog;
    float* coord;
    float xpos;
    float ypos;
    float counter;
};

void run(sf::RenderWindow& window);
void draw(sf::RenderWindow& window, gl_state& state);
