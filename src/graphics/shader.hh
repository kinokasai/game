#pragma once

#include <GL/glew.h>
#include <GL/gl.h>
#include <string>

GLuint get_fragment_shader();
GLuint get_vertex_shader();
char* load_shader(const std::string& fname);
