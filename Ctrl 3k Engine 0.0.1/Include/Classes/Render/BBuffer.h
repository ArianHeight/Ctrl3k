#pragma once

class BBuffer
{
public:
	BBuffer(int width, int height);
	~BBuffer();

	void init();

	GLuint bBuffer;

	GLuint bColour;
	GLenum attachments[1] = { GL_COLOR_ATTACHMENT0 };
	int m_width;
	int m_height;
};
