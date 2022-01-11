#pragma once

class SCBuffer
{
public:
	SCBuffer(int width, int height);
	~SCBuffer();

	void init();

	GLuint scBuffer;

	GLuint scColour;
	GLuint exposureTarget;
	GLenum attachments[2] = {GL_COLOR_ATTACHMENT0, GL_COLOR_ATTACHMENT1};
	int m_width;
	int m_height;
};