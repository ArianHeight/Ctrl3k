#pragma once

class SBuffer
{
public:
	SBuffer(int resolution);
	~SBuffer();

	void init();

	GLuint sBuffer;

	GLuint sDepth;
	int m_resolution;
};