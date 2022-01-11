#version 430 core

in vs_viewRayBL;

uniform samplerBuffer lightVSPos;
uniform samplerBuffer lightAtt;
uniform int numPLights;

out 