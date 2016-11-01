#pragma once

#include <GL/glew.h>
#include <GL/gl.h>

GLuint get_fragment_shader();
GLuint get_vertex_shader();
char* load_shader(char* fname);
