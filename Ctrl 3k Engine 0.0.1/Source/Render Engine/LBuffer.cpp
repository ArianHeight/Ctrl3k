#include <Ctrl 3kPCH.h>

LBuffer::LBuffer(int *windowWidth, int *windowHeight) : wwPointer(windowWidth), whPointer(windowHeight)
{

}

void LBuffer::init()
{
	glGenFramebuffers(1, &lBuffer);
	glBindFramebuffer(GL_FRAMEBUFFER, lBuffer);

	glGenTextures(1, &diffuseAccumulation);
	glBindTexture(GL_TEXTURE_2D, diffuseAccumulation);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA16F, *wwPointer, *whPointer, 0, GL_RGBA, GL_FLOAT, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, diffuseAccumulation, 0);

	glGenTextures(1, &specularAccumulation);
	glBindTexture(GL_TEXTURE_2D, specularAccumulation);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA16F, *wwPointer, *whPointer, 0, GL_RGBA, GL_FLOAT, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT1, GL_TEXTURE_2D, specularAccumulation, 0);

	glDrawBuffers(2, attachments);

	GLenum status = glCheckFramebufferStatus(GL_FRAMEBUFFER);

	if (status != GL_FRAMEBUFFER_COMPLETE)
	{
		std::cerr << "Frame Buffer Error! Status : 0x" << status << std::endl;
	}

	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glBindTexture(GL_TEXTURE_2D, 0);
}

LBuffer::~LBuffer()
{
	glDeleteTextures(1, &diffuseAccumulation);
	glDeleteTextures(1, &specularAccumulation);
	glDeleteFramebuffers(1, &lBuffer);
}