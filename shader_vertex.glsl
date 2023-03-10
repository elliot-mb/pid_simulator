#version 330 core

layout (location = 0) in vec3 aPos;

out vec4 ourColor;

uniform mat4 transform;
uniform vec4 colour;

void main()
{
    gl_Position = transform * vec4(aPos, 1.0);
    ourColor = colour;
}