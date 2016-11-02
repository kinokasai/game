#include <cmath>
#include <GL/glew.h>
#include <GL/gl.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/OpenGL.hpp>

#include "shader.hh"
#include "run.hh"

gl_state gl_init()
{
    float vertice[] =
    {
        -0.5f, 0.5f,
        0.5f, 0.5f,
        0.5f, -0.5f,
        -0.5f, -0.5f
    };

    float coord[] =
    {
        20, 20,
        20, 40,
        40, 40,
        40, 20
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
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertice), vertice, GL_STATIC_DRAW);

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
    for (auto i = 0; i < 8; i++)
        state.coord[i] = coord[i];
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

void draw(sf::RenderWindow& window, gl_state state)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    glm::mat4 view = glm::lookAt(
            glm::vec3(1.0f, 1.0f, 1.0f),
            glm::vec3(0.0f, 0.0f, 0.0f),
            glm::vec3(0.0f, 0.0f, 1.0f)
            );
    GLint uview = glGetUniformLocation(state.prog, "view");
    glUniformMatrix4fv(uview, 1, GL_FALSE, glm::value_ptr(view));

    /* Init as identity matrix */
    glm::mat4 mmat;
    mmat = glm::translate(mmat, glm::vec3(-1.0f, 1.0f, 0.0f));
    mmat = glm::scale(mmat, glm::vec3(0.05f, 0.05f, 1.0f));
    GLint transform = glGetUniformLocation(state.prog, "model");
    glUniformMatrix4fv(transform, 1, GL_FALSE, glm::value_ptr(mmat));

    GLint color = glGetUniformLocation(state.prog, "tri_color");
    glUniform3f(color, 1.0f, 0.0f, 0.0f);

    window.display();
}

/*void get_transorms(sarray<sf::Transform> transforms, sarray<sf::Vector2f> pos)
{
    for (auto it = transforms.begin(); it != transforms.end(); ++it)
    {
        int id = std::get<0>(*it);
        float rotation = 0;
        float angle = rotation * 3.141592654f / 180.f;
        float cosine = static_cast<float>(std::cos(angle));
        float sine   = static_cast<float>(std::sin(angle));
        float sxc = 0 * cosine;
        float syc = 0 * cosine;
        float sxs = 0 * sine;
        float sys = 0 * sine;
        float tx = pos[id].x;
        float ty = pos[id].y;
        auto tf = sf::Transform(sxc, sys, tx,
                               -sxs, syc, ty,
                                0.f, 0.f, 1.f);
        *it = std::make_pair(id, tf);
    }
}*/
