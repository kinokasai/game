#include "area.hh"
#include "render.hh"
#include "sarray.hh"
#include "shader.hh"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

void draw_entities(renderer &rendr, sf::RenderWindow& window)
{
    /* To remove */

    sarray<area> areas;
    areas.insert(std::make_pair(1, make_area(20, 20, 20, 20)));
    areas.insert(std::make_pair(3, make_area(300, 400, 40, 40)));

    /*          */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::mat4 vmat;

    GLint uview = glGetUniformLocation(rendr.program, "view");
    glUniformMatrix4fv(uview, 1, GL_FALSE, glm::value_ptr(vmat));

    /* Square the square - Aspect Ratio */

    glm::mat4 omat = glm::ortho(0.0f, 800.0f, 600.f, 0.f, -1.f, 0.f);

    GLint uortho = glGetUniformLocation(rendr.program, "ortho");
    glUniformMatrix4fv(uortho, 1, GL_FALSE, glm::value_ptr(omat));

    for (auto& it : areas)
    {
        auto& i = it.second;
        glm::mat4 mmat;
        mmat = glm::translate(mmat, glm::vec3(i.x, i.y, 0.f));

        mmat = glm::translate(mmat, glm::vec3(.5f * i.w, .5f * i.h, 0.f));
        mmat = glm::rotate(mmat, 0.f, glm::vec3(0.f, 0.f, 1.f));
        mmat = glm::translate(mmat, glm::vec3(-.5f * i.w, -.5f * i.h, 0.f));

        mmat = glm::scale(mmat, glm::vec3(i.w, i.h, 1.0f));

        GLint transform = glGetUniformLocation(rendr.program, "model");
        glUniformMatrix4fv(transform, 1, GL_FALSE, glm::value_ptr(mmat));

        GLint color = glGetUniformLocation(rendr.program, "tri_color");
        glUniform3f(color, 1.0f, 0.0f, 0.0f);

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

    renderer rendr;
    rendr.program = prog;
    return rendr;
}
