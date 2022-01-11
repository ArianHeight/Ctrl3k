#pragma once

/*

Light Buffer Class

*/
class LBuffer
{
public:
	LBuffer(int *windowWidth, int *windowHeight);
	~LBuffer();

	void init();

	GLuint lBuffer;

	GLuint diffuseAccumulation;
	GLuint specularAccumulation;

	GLuint attachments[2] {GL_COLOR_ATTACHMENT0, GL_COLOR_ATTACHMENT1};

	int *wwPointer, *whPointer = NULL;
};
/*

end Light Buffer Class

*/