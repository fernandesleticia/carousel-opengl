#version 330 core
attribute vec3 position;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform mat4 MVP;

void main()
{
    gl_Position = MVP * vec4(position, 1.0f);
}