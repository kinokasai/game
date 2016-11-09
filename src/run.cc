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

gl_state gl_init()
{
    float vertices[] =
    {
        0, 1,
        1, 1,
        1, 0,
        0, 0
    };

    GLuint elements[] = {
        0, 1, 2,
        2, 3, 0
    };

    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    GLuint vert = get_vertex_shader();
    GLuint frag = get_fragment_shader();

    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    /* Element buffers are for re-using vertices */

    GLuint ebo;
    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements),
                 elements, GL_STATIC_DRAW);

    /* The program links together the vertex and fragment shader */

    GLuint prog = glCreateProgram();
    glAttachShader(prog, vert);
    glAttachShader(prog, frag);
    glBindFragDataLocation(prog, 0, "outColor");

    glLinkProgram(prog);
    glUseProgram(prog);

    GLint unicolor = glGetUniformLocation(prog, "tri_color");
    glUniform3f(unicolor, 1.0f, 0.0f, 0.0f);


    GLint pos = glGetAttribLocation(prog, "position");
    glVertexAttribPointer(pos, 2, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(pos);

    std::cout << glGetError() << std::endl;
    gl_state state;
    state.prog = prog;
    state.coord = new float[8];
    state.counter = 0;
    for (auto i = 0; i < 8; i++)
        state.coord[i] = vertices[i];
    return state;
}

void run(sf::RenderWindow& window)
{
    glewExperimental = true;
    glewInit();
    gl_state state = gl_init();
    while (true)
        draw(window, state);
}

float* transform(sf::RenderWindow& window, float* coord)
{
    float* vertices = new float[8];
    int width = window.getSize().x;
    int height = window.getSize().y;
    for (int i = 0; i < 8; i = i+2)
    {
        vertices[i] = (coord[i] - (width / 2)) / width;
        vertices[i+1] = (coord[i] - (height / 2)) / height;
    }
    return vertices;
}

void draw(sf::RenderWindow& window, gl_state& state)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    float pos[] = {20, 20, 80, 10, 300, 400};

    glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(float), state.coord, GL_STATIC_DRAW);

    glm::mat4 vmat;

    GLint uview = glGetUniformLocation(state.prog, "view");
    glUniformMatrix4fv(uview, 1, GL_FALSE, glm::value_ptr(vmat));

    /* Square the square - Aspect Ratio */

    glm::mat4 omat = glm::ortho(0.0f, 800.0f, 600.f, 0.f, -1.f, 0.f);

    GLint uortho = glGetUniformLocation(state.prog, "ortho");
    glUniformMatrix4fv(uortho, 1, GL_FALSE, glm::value_ptr(omat));

    float xsize = 20;
    float ysize = 20;

    for (int i = 0; i < 6; i+=2)
    {

        glm::mat4 mmat; /* Init as identity matrix */
        mmat = glm::translate(mmat, glm::vec3(pos[i], pos[i+1], 0.0f));

        /* When there's rotation, shift origin to middle of quad. */

        mmat = glm::translate(mmat, glm::vec3(.5f * xsize, .5f * ysize, 0.f));
        mmat = glm::rotate(mmat, 0.f, glm::vec3(0.f, 0.f, 1.f));
        mmat = glm::translate(mmat, glm::vec3(-.5f * xsize, -.5f * ysize, 0.f));

        mmat = glm::scale(mmat, glm::vec3(xsize, ysize, 1.0f));

        GLint transform = glGetUniformLocation(state.prog, "model");
        glUniformMatrix4fv(transform, 1, GL_FALSE, glm::value_ptr(mmat));

        GLint color = glGetUniformLocation(state.prog, "tri_color");
        glUniform3f(color, 1.0f, 0.0f, 0.0f);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }

    window.display();
}
