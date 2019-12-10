#version 120

attribute vec3 position;
attribute vec2 texCoord;
attribute vec3 normal;

varying vec2 texCoord0;
varying vec3 normal0;
varying vec3 FragPos;

uniform mat4 model;
uniform mat4 MVP;
uniform mat4 Normal;


void main()
{
	gl_Position = MVP * vec4(position, 1.0);
	texCoord0 = texCoord;
    FragPos = vec3(model * vec4(position, 1.0f));
	normal0 = (Normal * vec4(normal, 0.0)).xyz;
}
