#include <cmath>
#include <GL/glew.h>
#include <GL/gl.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/OpenGL.hpp>

#include "shader.hh"
#include "render.hh"
#include "run.hh"

void run(sf::RenderWindow& window)
{
    glewExperimental = true;
    glewInit();
    renderer rendr = init_renderer();
    while(true)
        draw_entities(rendr, window);
}
