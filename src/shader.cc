#include <cstring>
#include <fstream>
#include <iostream>

#include "shader.hh"

char* load_shader(const std::string& fname)
{
	std::ifstream file;
    file.open(fname);
    if (!file)
        std::cout << "error on file";
    std::string contents((std::istreambuf_iterator<char>(file)),
                          std::istreambuf_iterator<char>());
    file.close();
    char *tmp = new char[contents.length() + 1];
    std::strcpy(tmp, contents.c_str());
    return tmp;
}

void check_shader(GLuint shader, std::string name)
{
    GLint status;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    if (status != GL_TRUE)
    {
        int len;
        char* log = new char[100];
        glGetShaderInfoLog(shader, 100, &len, log);
        std::cout << "Error in " << name << " shader!\n" << std::endl;
        std::cout << log << std::endl;
    }
}

GLuint get_vertex_shader()
{
    GLuint vert = glCreateShader(GL_VERTEX_SHADER);
    const char* vcode = load_shader("src/vertex.glsl");
    glShaderSource(vert, 1, &vcode, NULL);
    glCompileShader(vert);
    check_shader(vert, "vert");
    delete[] vcode;
    return vert;
}

GLuint get_fragment_shader()
{
    GLuint frag = glCreateShader(GL_FRAGMENT_SHADER);
    const char* fcode = load_shader("src/fragment.glsl");
    glShaderSource(frag, 1, &fcode, NULL);
    glCompileShader(frag);
    check_shader(frag, "frag");
    delete[] fcode;
    return frag;
}
