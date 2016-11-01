#version 130

out vec4 outColor;

uniform vec3 tri_color;

void main()
{
    outColor = vec4(tri_color, 0.0f);
}
