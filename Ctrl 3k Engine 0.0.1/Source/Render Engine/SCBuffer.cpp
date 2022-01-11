#include <Ctrl 3kPCH.h>

SCBuffer::SCBuffer(int width, int height)
{
	this->m_width = width;
	this->m_height = height;
}

void SCBuffer::init()
{
	glGenFramebuffers(1, &scBuffer);
	glBindFramebuffer(GL_FRAMEBUFFER, scBuffer);

	glGenTextures(1, &scColour);
	glBindTexture(GL_TEXTURE_2D, scColour);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA16F, this->m_width, this->m_height, 0, GL_RGBA, GL_FLOAT, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, scColour, 0);

	glGenTextures(1, &exposureTarget);
	glBindTexture(GL_TEXTURE_2D, exposureTarget);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA16F, this->m_width, this->m_height, 0, GL_RGBA, GL_FLOAT, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT1, GL_TEXTURE_2D, exposureTarget, 0);

	glDrawBuffers(2, attachments);

	GLenum status = glCheckFramebufferStatus(GL_FRAMEBUFFER);

	if (status != GL_FRAMEBUFFER_COMPLETE)
	{
		std::cerr << "Frame Buffer Error! Status : 0x" << status << std::endl;
	}

	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glBindTexture(GL_TEXTURE_2D, 0);
}

SCBuffer::~SCBuffer()
{
	glDeleteTextures(1, &scColour);
	glDeleteTextures(1, &exposureTarget);
	glDeleteFramebuffers(1, &scBuffer);
}