#include <Ctrl 3kPCH.h>

#include <Ctrl 3kPCH.h>

BBuffer::BBuffer(int width, int height)
{
	this->m_width = width;
	this->m_height = height;
}

void BBuffer::init()
{
	glGenFramebuffers(1, &bBuffer);
	glBindFramebuffer(GL_FRAMEBUFFER, bBuffer);

	glGenTextures(1, &bColour);
	glBindTexture(GL_TEXTURE_2D, bColour);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA16F, this->m_width, this->m_height, 0, GL_RGBA, GL_FLOAT, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, bColour, 0);

	glDrawBuffers(1, attachments);

	GLenum status = glCheckFramebufferStatus(GL_FRAMEBUFFER);

	if (status != GL_FRAMEBUFFER_COMPLETE)
	{
		std::cerr << "Frame Buffer Error! Status : 0x" << status << std::endl;
	}

	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glBindTexture(GL_TEXTURE_2D, 0);
}

BBuffer::~BBuffer()
{
	glDeleteTextures(1, &bColour);
	glDeleteFramebuffers(1, &bBuffer);
}