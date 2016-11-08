#version 130

in vec2 position;

uniform mat4 model;
uniform mat4 view;
uniform mat4 ortho;

void main()
{
    gl_Position = ortho * view * model * vec4(position, 0.0, 1.0);
}
