#include <Ctrl 3kPCH.h>

SBuffer::SBuffer(int resolution)
{
	this->m_resolution = resolution;
}

void SBuffer::init()
{
	glGenFramebuffers(1, &sBuffer);
	glBindFramebuffer(GL_FRAMEBUFFER, sBuffer);

	glGenTextures(1, &sDepth);
	glBindTexture(GL_TEXTURE_2D, sDepth);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, m_resolution, m_resolution, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
	//glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, this->m_resolution, this->m_resolution, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, sDepth, 0);

	glDrawBuffer(GL_NONE);
	glReadBuffer(GL_NONE);

	GLenum status = glCheckFramebufferStatus(GL_FRAMEBUFFER);

	if (status != GL_FRAMEBUFFER_COMPLETE)
	{
		std::cerr << "Frame Buffer Error! Status : 0x" << status << std::endl;
	}

	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glBindTexture(GL_TEXTURE_2D, 0);
}

SBuffer::~SBuffer()
{
	glDeleteTextures(1, &sDepth);
	glDeleteFramebuffers(1, &sBuffer);
}