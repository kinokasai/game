#include <cmath>
#include <GL/glew.h>
#include <GL/gl.h>
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
        0.0f, 0.5f,
        0.5f, -0.5f,
        -0.5f, -0.5f
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

void get_transorms(sarray<sf::Transform> transforms, sarray<sf::Vector2f> pos)
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
}

void draw(sf::RenderWindow& window, gl_state state)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    GLint color = glGetUniformLocation(state.prog, "tri_color");
    glUniform3f(color, 1.0f, 0.0f, 0.0f);

    window.display();
}
