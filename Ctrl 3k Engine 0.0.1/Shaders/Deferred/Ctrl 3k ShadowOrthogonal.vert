#version 330 core

layout(location = 0) in vec3 in_position;

//Projection, View Matrix, and Model Matrix.
uniform mat4 L; //Light Matrix
uniform mat4 V;
uniform mat4 M;

void main()
{
	gl_Position = L * V * M * vec4(in_position, 1.0);
}