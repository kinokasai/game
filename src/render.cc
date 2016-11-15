#include "area.hh"
#include "color.hh"
#include "palette.hh"
#include "render.hh"
#include "sarray.hh"
#include "shader.hh"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

void draw_entities(renderer &rendr, sf::RenderWindow& window,
        sarray<area>& areas, sarray<int>& colors, camera& cam, state& state)
{
    color ccolor = get_color(0, state);
    glClearColor(ccolor.r, ccolor.g, ccolor.b, 0);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::mat4 vmat;

    GLint uview = glGetUniformLocation(rendr.program, "view");
    glUniformMatrix4fv(uview, 1, GL_FALSE, glm::value_ptr(vmat));

    /* Square the square - Aspect Ratio */
    glm::mat4 omat = glm::ortho(cam.x, cam.x + cam.win_x, cam.y + cam.win_y, cam.y);

    GLint uortho = glGetUniformLocation(rendr.program, "ortho");
    glUniformMatrix4fv(uortho, 1, GL_FALSE, glm::value_ptr(omat));

    for (auto& it : areas)
    {
        auto id = it.first;
        auto& i = it.second;
        glm::mat4 mmat;
        mmat = glm::translate(mmat, glm::vec3(i.x, i.y, 0.f));

        mmat = glm::translate(mmat, glm::vec3(.5f * i.w, .5f * i.h, 0.f));
        mmat = glm::rotate(mmat, 0.f, glm::vec3(0.f, 0.f, 1.f));
        mmat = glm::translate(mmat, glm::vec3(-.5f * i.w, -.5f * i.h, 0.f));

        mmat = glm::scale(mmat, glm::vec3(i.w, i.h, 1.0f));

        GLint transform = glGetUniformLocation(rendr.program, "model");
        glUniformMatrix4fv(transform, 1, GL_FALSE, glm::value_ptr(mmat));

        color color = get_color(colors[id], state);
        GLint ucolor = glGetUniformLocation(rendr.program, "color");
        glUniform3f(ucolor, color.r, color.g, color.b);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }

    window.display();
}

renderer init_renderer()
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

    glewExperimental = true;
    glewInit();

    renderer rendr;

    glGenVertexArrays(1, &rendr.vao);
    glBindVertexArray(rendr.vao);

    rendr.vert = get_vertex_shader();
    rendr.frag = get_fragment_shader();

    glGenBuffers(1, &rendr.vbo);
    glBindBuffer(GL_ARRAY_BUFFER, rendr.vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    /* Element buffers are for re-using vertices */

    glGenBuffers(1, &rendr.ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rendr.ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements),
                 elements, GL_STATIC_DRAW);

    /* The program links together the vertex and fragment shader */

    rendr.program = glCreateProgram();
    glAttachShader(rendr.program, rendr.vert);
    glAttachShader(rendr.program, rendr.frag);
    glBindFragDataLocation(rendr.program, 0, "outColor");

    glLinkProgram(rendr.program);
    glUseProgram(rendr.program);

    GLint unicolor = glGetUniformLocation(rendr.program, "tri_color");
    glUniform3f(unicolor, 1.0f, 0.0f, 0.0f);


    GLint pos = glGetAttribLocation(rendr.program, "position");
    glVertexAttribPointer(pos, 2, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(pos);

    return rendr;
}

renderer::~renderer()
{
    Logger::log().log("Free OpenGL resources...");
    glDeleteProgram(program);
    glDeleteShader(frag);
    glDeleteShader(vert);
    glDeleteBuffers(1, &ebo);
    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);
}
