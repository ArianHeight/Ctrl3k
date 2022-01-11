#include "stdafx.h"
#include <Ctrl 3kPCH.h>

#define CTRL_3D_CAMERA ctrlThreeDCam
#define CTRL_2D_CAMERA ctrlTwoDCam

//for native engine code
#define CTRL_GAME_PAUSED pause

//used for .ctrlscript/.3kscript files
#define CTRL_TWOD 0
#define CTRL_THREED 1
#define CTRL_BOTH 2

#define CTRL_UNOPTQUATCAM 0
#define CTRL_OPTQUATCAM 1
#define CTRL_FPSCAM 2
#define CTRL_LOOKATCAM 3
#define CTRL_ARCBALLCAM 4
#define CTRL_TWODCAM 5

//key indices
#define KNULL 0
#define KSTART_OF_HEADER 1
#define KSTART_OF_TEXT 2
#define KEND_OF_TEXT 3
#define KEND_OF_TRANSIMISSION 4
#define KENQUIRY 5
#define KACKNOWLEDGMENT 6
#define KBELL 7
#define KBACKSPACE 8
#define KHORIZANTAL_TAB 9
#define KLINE_FEED 10
#define KVERTICAL_TAB 11
#define KFORM_FEED 12
#define KENTER 13
#define KSHIFT_OUT 14
#define KSHIFT_IN 15
#define KDATA_LINE_ESCAPE 16
#define KDEVICE_CONTROL1 17
#define KDEVCIE_CONTROL2 18
#define KDEVICE_CONTROL3 19
#define KDEVICE_CONTROL4 20
#define KNEGATIVE_ACKNOWLEDGMENT 21
#define KSYNCHRONOUS_IDLE 22
#define KEND_OF_TRANSMIT_BLOCK 23
#define KCANCEL 24
#define KEND_OF_MEDIUM 25
#define KSUBSITUTE 26
#define KESCAPE 27
#define KFILE_SEPERATOR 28
#define KGROUP_SEPERATOR 29
#define KRECORD_SEPERATOR 30
#define KUNIT_SEPERATOR 31

#define KSPACE 32
#define KEXCLAIMATION 33
#define KDOUBLEQUOTES 34
#define KNUMBER 35
#define KDOLLAR 36
#define KPROCENTTEKEN 37
#define KAMPERSAND 38
#define KSINGLEQUOTE 39
#define KOPENPARENTHESIS 40
#define KCLOSEPARENTHESIS 41
#define KASTERISK 42
#define KPLUS 43
#define KCOMMA 44
#define KHYPHEN 45
#define KPERIOD 46
#define KSLASH 47

#define K0 48
#define K1 49
#define K2 50
#define K3 51
#define K4 52
#define K5 53
#define K6 54
#define K7 55
#define K8 56
#define K9 57

#define KCOLON 58
#define KSEMICOLON 59
#define KLESS_THAN 60
#define KEQUALS 61
#define KGREATER_THAN 62
#define KQUESTION_MARK 63
#define KAT_SYMBOL 64

#define KA 65
#define KB 66
#define KC 67
#define KD 68
#define KE 69
#define KF 70
#define KG 71
#define KH 72
#define KI 73
#define KJ 74
#define KK 75
#define KL 76
#define KM 77
#define KN 78
#define KO 79
#define KP 80
#define KQ 81
#define KR 82
#define KS 83
#define KT 84
#define KU 85
#define KV 86
#define KW 87
#define KX 88
#define KY 89
#define KZ 90

#define KOPENING_BRACKET 91
#define KBACK_SLASH 92
#define KCLOSING_BRACKET 93
#define KCARET 94
#define KUNDERSCORE 95
#define KGRAVE_ACCENT 96

#define Ka 97
#define Kb 98
#define Kc 99
#define Kd 100
#define Ke 101
#define Kf 102
#define Kg 103
#define Kh 104
#define Ki 105
#define Kj 106
#define Kk 107
#define Kl 108
#define Km 109
#define Kn 110
#define Ko 111
#define Kp 112
#define Kq 113
#define Kr 114
#define Ks 115
#define Kt 116
#define Ku 117
#define Kv 118
#define Kw 119
#define Kx 120
#define Ky 121
#define Kz 122

#define KOPENING_BRACE 123
#define KVERTICAL_BAR 124
#define KCLOSING_BRACE 125
#define KTILDE 126
#define KDELETE 127
//end key indices

//keys
#define CTRL_KNULL key[0]
#define CTRL_KSTART_OF_HEADER key[1]
#define CTRL_KSTART_OF_TEXT key[2]
#define CTRL_KEND_OF_TEXT key[3]
#define CTRL_KEND_OF_TRANSIMISSION key[4]
#define CTRL_KENQUIRY key[5]
#define CTRL_KACKNOWLEDGMENT key[6]
#define CTRL_KBELL key[7]
#define CTRL_KBACKSPACE key[8]
#define CTRL_KHORIZANTAL_TAB key[9]
#define CTRL_KLINE_FEED key[10]
#define CTRL_KVERTICAL_TAB key[11]
#define CTRL_KFORM_FEED key[12]
#define CTRL_KENTER key[13]
#define CTRL_KSHIFT_OUT key[14]
#define CTRL_KSHIFT_IN key[15]
#define CTRL_KDATA_LINE_ESCAPE key[16]
#define CTRL_KDEVICE_CONTROL1 key[17]
#define CTRL_KDEVCIE_CONTROL2 key[18]
#define CTRL_KDEVICE_CONTROL3 key[19]
#define CTRL_KDEVICE_CONTROL4 key[20]
#define CTRL_KNEGATIVE_ACKNOWLEDGMENT key[21]
#define CTRL_KSYNCHRONOUS_IDLE key[22]
#define CTRL_KEND_OF_TRANSMIT_BLOCK key[23]
#define CTRL_KCANCEL key[24]
#define CTRL_KEND_OF_MEDIUM key[25]
#define CTRL_KSUBSITUTE key[26]
#define CTRL_KESCAPE key[27]
#define CTRL_KFILE_SEPERATOR key[28]
#define CTRL_KGROUP_SEPERATOR key[29]
#define CTRL_KRECORD_SEPERATOR key[30]
#define CTRL_KUNIT_SEPERATOR key[31]

#define CTRL_KSPACE key[32]
#define CTRL_KEXCLAIMATION key[33]
#define CTRL_KDOUBLEQUOTES key[34]
#define CTRL_KNUMBER key[35]
#define CTRL_KDOLLAR key[36]
#define CTRL_KPROCENTTEKEN key[37]
#define CTRL_KAMPERSAND key[38]
#define CTRL_KSINGLEQUOTE key[39]
#define CTRL_KOPENPARENTHESIS key[40]
#define CTRL_KCLOSEPARENTHESIS key[41]
#define CTRL_KASTERISK key[42]
#define CTRL_KPLUS key[43]
#define CTRL_KCOMMA key[44]
#define CTRL_KHYPHEN key[45]
#define CTRL_KPERIOD key[46]
#define CTRL_KSLASH key[47]

#define CTRL_K0 key[48]
#define CTRL_K1 key[49]
#define CTRL_K2 key[50]
#define CTRL_K3 key[51]
#define CTRL_K4 key[52]
#define CTRL_K5 key[53]
#define CTRL_K6 key[54]
#define CTRL_K7 key[55]
#define CTRL_K8 key[56]
#define CTRL_K9 key[57]

#define CTRL_KCOLON key[58]
#define CTRL_KSEMICOLON key[59]
#define CTRL_KLESS_THAN key[60]
#define CTRL_KEQUALS key[61]
#define CTRL_KGREATER_THAN key[62]
#define CTRL_KQUESTION_MARK key[63]
#define CTRL_KAT_SYMBOL key[64]

#define CTRL_KA key[65]
#define CTRL_KB key[66]
#define CTRL_KC key[67]
#define CTRL_KD key[68]
#define CTRL_KE key[69]
#define CTRL_KF key[70]
#define CTRL_KG key[71]
#define CTRL_KH key[72]
#define CTRL_KI key[73]
#define CTRL_KJ key[74]
#define CTRL_KK key[75]
#define CTRL_KL key[76]
#define CTRL_KM key[77]
#define CTRL_KN key[78]
#define CTRL_KO key[79]
#define CTRL_KP key[80]
#define CTRL_KQ key[81]
#define CTRL_KR key[82]
#define CTRL_KS key[83]
#define CTRL_KT key[84]
#define CTRL_KU key[85]
#define CTRL_KV key[86]
#define CTRL_KW key[87]
#define CTRL_KX key[88]
#define CTRL_KY key[89]
#define CTRL_KZ key[90]

#define CTRL_KOPENING_BRACKET key[91]
#define CTRL_KBACK_SLASH key[92]
#define CTRL_KCLOSING_BRACKET key[93]
#define CTRL_KCARET key[94]
#define CTRL_KUNDERSCORE key[95]
#define CTRL_KGRAVE_ACCENT key[96]

#define CTRL_Ka key[97]
#define CTRL_Kb key[98]
#define CTRL_Kc key[99]
#define CTRL_Kd key[100]
#define CTRL_Ke key[101]
#define CTRL_Kf key[102]
#define CTRL_Kg key[103]
#define CTRL_Kh key[104]
#define CTRL_Ki key[105]
#define CTRL_Kj key[106]
#define CTRL_Kk key[107]
#define CTRL_Kl key[108]
#define CTRL_Km key[109]
#define CTRL_Kn key[110]
#define CTRL_Ko key[111]
#define CTRL_Kp key[112]
#define CTRL_Kq key[113]
#define CTRL_Kr key[114]
#define CTRL_Ks key[115]
#define CTRL_Kt key[116]
#define CTRL_Ku key[117]
#define CTRL_Kv key[118]
#define CTRL_Kw key[119]
#define CTRL_Kx key[120]
#define CTRL_Ky key[121]
#define CTRL_Kz key[122]

#define CTRL_KOPENING_BRACE key[123]
#define CTRL_KVERTICAL_BAR key[124]
#define CTRL_KCLOSING_BRACE key[125]
#define CTRL_KTILDE key[126]
#define CTRL_KDELETE key[127]
//end keys

//various buffers
std::vector<bool> key(128, 0);
std::vector<Material*> materialBuffer;
std::vector<Texture*> textureBuffer;
std::vector<VisualObject*> visualObjectBuffer;
std::vector<directionalLight> dLights;
glm::vec4 dLightVsNormalColour[2];
std::vector<pointLight> dynamicPLights;
std::vector<glm::vec4> pLightWPos;
std::vector<glm::vec4> pLightVsPos;
std::vector<glm::vec4> pLightAttenuations;
std::vector<glm::vec4> pLightColour;
GLuint pLightBuffers[3];
GLuint pLightBTextures[3];

bool ctrlThreeDCam = false;
bool ctrlTwoDCam = false;

bool pause = false;

int gl_iWindowWidth = 1280; //window dimensions
int gl_iWindowHeight = 720;
int gl_iScreenWidth; //screen dimension values
int gl_iScreenHeight;
float gl_fAspectRatio;
int gl_iCenter[2] = { 0, 0 }; //center point of the window
GLuint gl_iWindowHandle; //window object

glm::ivec2 gl_iMousePos;

std::clock_t gl_cCurrentFrame; //time of current frame
std::clock_t gl_cPreviousFrame; //time of previous frame
double gl_dSecondsElapsed; //seconds elapsed since last frame

GLint gl_diffuseSP = 0; //store the diffuse shader program
GLint gl_diNoSP = 0; //stores the diffuse normal shading program
GLint gl_geoPass = -1;
GLint gl_shdwPass = -1;
GLint gl_lightPass = -1;
GLint gl_finalShading = -1;
GLint gl_directionalBlur = -1;
GLint gl_downSample = -1;
GLint gl_brightPass = -1;
GLint gl_postProcess = -1;

GLint dsp_uniV = -1; //stores the V matrix
GLint dsp_uniP = -1; //stores the P matrix
GLint dsp_uniM = -1; //stores the M Matrix
GLint dsp_uniWEyePos = -1; //eye's position in world space
GLint dsp_uniWLightPos = -1; //light's position in world space
GLint dsp_uniLightColour = -1; //light's colour
GLint dsp_uniAmbient = -1; //ambient contribution(global ambient * material ambient)
GLint dsp_uniMaterialEmissive = -1; //material's emissive property
GLint dsp_uniMaterialDiffuse = -1; //material's diffuse property
GLint dsp_uniMaterialSpecular = -1; //material's specular property
GLint dsp_uniMaterialShininess = -1; //material's shininess constant
GLint dsp_uniMaterialSharpness = -1; //material's sharpness constant
GLint dsp_uniDiffuseSampler = -1; //diffuse map sampler

GLint dnsp_uniMVP = -1; //stores the VP matrix
GLint dnsp_uniM = -1; //stores the M Matrix
GLint dnsp_uniWEyePos = -1; //eye's position in world space
GLint dnsp_uniWLightPos = -1; //light's position in world space
GLint dnsp_uniLightColour = -1; //light's colour
GLint dnsp_uniAmbient = -1; //ambient contribution(global ambient * material ambient)
GLint dnsp_uniMaterialEmissive = -1; //material's emissive property
GLint dnsp_uniMaterialDiffuse = -1; //material's diffuse property
GLint dnsp_uniMaterialSpecular = -1; //material's specular property
GLint dnsp_uniMaterialShininess = -1; //material's shininess constant
GLint dnsp_uniMaterialSharpness = -1; //material's sharpness constant
GLint dnsp_uniDiffuseSampler = -1; //diffuse map sampler
GLint dnsp_uniNormalSampler = -1; //normal map sampler

GLint geo_uniM = -1;
GLint geo_uniV = -1;
GLint geo_uniP = -1;
GLint geo_uniMatID = -1;
GLint geo_uniDiffuseSampler = -1;
GLint geo_uniNormalSampler = -1;
GLint geo_uniDisplacementSampler = -1;
GLint geo_uniParallax = -1;

GLint shdw_uniM = -1;
GLint shdw_uniV = -1;
GLint shdw_uniL = -1;

GLint light_uniCornerBL = -1;
GLint light_uniFrustrum = -1;
GLint light_uniTileNum = -1;
GLint light_uniTilePD = -1;
GLint light_uniVPLP = -1;
GLint light_uniVPLA = -1;
GLint light_uniProjA = -1;
GLint light_uniProjB = -1;
GLint light_uniNumPointL = -1;
GLint light_uniPointLP = -1;
GLint light_uniPointLA = -1;
GLint light_uniPointLC = -1;
GLint light_uniCullPlanes = -1;
GLint light_uniDLight = -1;
GLint light_uniDLightData = -1;
GLint light_uniDLightSpace = -1;
GLint light_uniDLightMap = -1;
GLint light_uniSpecLobeSampler = -1;
GLint light_uniDepthSampler = -1;
GLint light_uniNormalSampler = -1;

GLint fs_uniDiffuseASampler = -1;
GLint fs_uniSpecularASampler = -1;
GLint fs_uniAlbedoSampler = -1;

GLint db_uniTargetSampler = -1;
GLint db_uniTexelOffset = -1;
GLint db_uniDirection = -1;

GLint dd_uniSampler = -1;

GLint b_uniBloom = -1;
GLint b_uniBloomTwo = -1;
GLint b_uniBloomFour = -1;
GLint b_uniBloomSixteen = -1;

GLint pp_uniSampler = -1;
GLint pp_uniBloom = -1;
GLint pp_uniBloomTwo = -1;
GLint pp_uniBloomFour = -1;
GLint pp_uniTexelOffset = -1;

Camera *cam = NULL;
Frustrum *viewFrustrum = NULL;
unsigned int activeCameraType;
GBuffer *gl_gBuffer = NULL;
LBuffer *gl_lBuffer = NULL;
SBuffer *gl_sBuffer = NULL;
SCBuffer *gl_scBuffer = NULL;
BBuffer *gl_bBuffer[8] = { NULL, NULL , NULL, NULL, NULL, NULL}; //5x1, 5x5, 11x1, 11x11, 21x1, 21x21, 42x1, 42x42
Cube smallCube(true, glm::vec3(0, -8, -10), glm::quat(cosf(glm::radians(90 * 0.5f)), sinf(glm::radians(90 * 0.5f)), 0, 0), 5.0f);
Cube smallSpike(true, glm::vec3(0, -2, -10), glm::quat(cosf(glm::radians(45 * 0.5f)), 0, sinf(glm::radians(45 * 0.5f)), 0));

float x, y, z, mX, mY, mZ = 0; //camera input source vars
GLuint emptyAlbedo, emptyNormals, specularLobeShapes, specularTints;
GLuint tempParallax,tempNormal, tempDiffuse;

//GLuint positionAttrib, normalAttrib, texcoord0Attrib;
GLuint vo;
GLuint spike;

//updates gl_dSecondsElapsed every frame
void updateTime()
{
	gl_cCurrentFrame = std::clock();
	gl_dSecondsElapsed = (double)(gl_cCurrentFrame - gl_cPreviousFrame) / 1000;
	gl_cPreviousFrame = gl_cCurrentFrame;
}

//updates the center values of the window
void updateCenter()
{
	gl_iCenter[0] = gl_iWindowWidth * 0.5;
	gl_iCenter[1] = gl_iWindowHeight * 0.5;
}

int loadCubeMesh()
{
	//return loadTriMesh("Resources/Models/Simple Cube.obj");
	//return loadTriMesh("Resources/Models/Simple Sphere.obj");
	return loadVO("Resources/Models/spike.obj");
	//return loadTriMesh("Resources/Models/Cube With Material.obj");
	//return loadTriMesh("Resources/Models/smoothflat.obj");
	//return loadTriMesh("Resources/Models/Plane.obj");
	//return loadTriMesh("Resources/Models/monkey.obj");
}

//loads texture object and adds to texture buffer, returning index TO THE BUFFER!!
int loadTextureObject(std::string filePath)
{
	std::string name;
	getTokenPath(name, filePath); //seperates fiilename from filepath

	int tBIndex = textureBuffer.size();

	Texture* tex = NULL;
	tex = new Texture(name, loadTexture(filePath));

	textureBuffer.push_back(tex);

	return tBIndex;
}

//returns textureBuffer index of a texture given the name (or -1 if no texture object with such name is found)
int findTexture(std::string name)
{
	int text = -1;
	int size = textureBuffer.size();

	for (int i = 0; i < size; ++i)
	{
		if (textureBuffer[i]->m_name == name)
		{
			text = i;
			return text;
		}
	}

	return text;
}

//clears the textureBuffer and unloads all textures from openGL
void clearTextureBuffer()
{
	int size = textureBuffer.size();

	for (int i = 0; i < size; ++i)
	{
		glDeleteTextures(1, &textureBuffer[i]->m_texture);
		delete textureBuffer[i];
		textureBuffer[i] = NULL;
	}

	textureBuffer.clear();
}

//loads a material and adds it to buffer, returning index to material in materialBuffer or -1 if loading was unsuccessful
int loadMaterial(std::string &name, Material *&mat)
{
	int mBIndex = materialBuffer.size();

	Material *materia = NULL;
	materia = new Material(name);

	materialBuffer.push_back(materia);

	mat = materia;

	return mBIndex;
}

//finds and returns index to materialBuffer given material name (or -1 if no material with specified name is found)
int findMaterial(std::string name)
{
	int mat = -1;
	int size = materialBuffer.size();

	for (int i = 0; i < size; ++i)
	{
		if (materialBuffer[i]->m_name == name)
		{
			mat = i;
			return mat;
		}
	}

	return mat;
}

void clearMaterialBuffer()
{
	int size = materialBuffer.size();

	for (int i = 0; i < size; ++i)
	{
		delete materialBuffer[i];
		materialBuffer[i] = NULL;
	}

	materialBuffer.clear();
}

int loadVO(std::string filePath)
{
	int VOBIndex = visualObjectBuffer.size();
	bool requestKeep; //will be set to false if .mtl parsing is unsuccessful

	VisualObject *obj = NULL;
	obj = new VisualObject(filePath, requestKeep);

	if (!requestKeep) //if .mtl wasn't loaded properly
	{
		std::cerr << "Sorry, Could Not Load C3 Object.\n\tFile Path : " << filePath << "\n\tPlease Double Check File Path." << std::endl;
		return -1;
	}

	visualObjectBuffer.push_back(obj);

	return VOBIndex;
}

int findVO(std::string name)
{
	int vo = -1;
	int size = visualObjectBuffer.size();

	for (int i = 0; i < size; ++i)
	{
		if (visualObjectBuffer[i]->m_name == name)
		{
			vo = i;
			return vo;
		}
	}

	return vo;
}

void clearVOBuffer()
{
	int size = visualObjectBuffer.size();

	for (int i = 0; i < size; ++i)
	{
		delete visualObjectBuffer[i];
		visualObjectBuffer[i] = NULL;
	}

	visualObjectBuffer.clear();
}

GLuint quadVao = 0;
GLuint quadVbo;

void drawScreenQuad()
{
	if (quadVao == 0)
	{
		GLfloat quadVertices[] = {
			-1.0f, 1.0f, 0.0f, 0.0f, 1.0f,
			-1.0f, -1.0f, 0.0f, 0.0f, 0.0f,
			1.0f, 1.0f, 0.0f, 1.0f, 1.0f,
			1.0f, -1.0f, 0.0f, 1.0f, 0.0f
		};
		glGenVertexArrays(1, &quadVao);
		glBindVertexArray(quadVao);
		glGenBuffers(1, &quadVbo);
		glBindBuffer(GL_ARRAY_BUFFER, quadVbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), &quadVertices, GL_STATIC_DRAW);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GL_FLOAT), (GLvoid*)0);
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GL_FLOAT), (GLvoid*)(3 * sizeof(GL_FLOAT)));
	}
	glBindVertexArray(quadVao);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	glBindVertexArray(0);
}

//initializes and checks for GL Extension Wrangler support for version context
void initializeGLEW()
{
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		std::cerr << "There was a problem initializing GL Extension Wrangler...\nExiting...." << std::endl;
		exit(-1);
	}
	if (!GLEW_VERSION_3_3)
	{
		std::cerr << "OpenGL 3.3 Version Support Not Present For Engine Use...." << std::endl;
		exit(-1);
	}
#ifdef _WIN32
	if (WGLEW_EXT_swap_control)
	{
		wglSwapIntervalEXT(0); //disables Vertical-Sync
	}
#endif
}

//initializes openGL with version context
void initializeGL(int argc, char* argv[])
{
	std::cout << "Please Wait While OpenGL Is Initializing....." << std::endl;

	glutInit(&argc, argv); //Initializes GL Utility Tools

	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

	//Window Stuffs
	gl_iScreenWidth = glutGet(GLUT_SCREEN_WIDTH);
	gl_iScreenHeight = glutGet(GLUT_SCREEN_HEIGHT);
	gl_fAspectRatio = (float)gl_iWindowWidth / (float)gl_iWindowHeight;
	updateCenter();
	glutInitDisplayMode(GLUT_RGBA | GLUT_ALPHA | GLUT_DEPTH | GLUT_DOUBLE);

	//creates OpenGL 3.3 core forward compatible context
	glutInitContextVersion(3, 3);
	glutInitContextProfile(GLUT_CORE_PROFILE);
	//glutInitContextFlags(GLUT_FORWARD_COMPATIBLE);

	glutInitWindowPosition((gl_iScreenWidth - gl_iWindowWidth) / 2, (gl_iScreenHeight - gl_iWindowHeight) / 2);
	glutInitWindowSize(gl_iWindowWidth, gl_iWindowHeight);
	gl_iWindowHandle = glutCreateWindow("Ctrl 3K Engine");

	//setup GLUT funciton callbacks
	glutDisplayFunc(displayUpdate);
	glutIdleFunc(idle);
	glutKeyboardFunc(keyboardHandle);
	glutKeyboardUpFunc(keyboardUp);
	glutSpecialFunc(specialHandle);
	glutSpecialUpFunc(specialUp);
	glutMouseFunc(mouseClick);
	glutMotionFunc(mouseHandle);
	glutPassiveMotionFunc(mouseHandle);
	glutReshapeFunc(resizeWindow);

	//Other Setups
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	//glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	std::cout << "OpenGL Has Initialized Successfully" << std::endl;

	glutSetCursor(GLUT_CURSOR_NONE);
	glutWarpPointer(gl_iCenter[0], gl_iCenter[1]);
}

void renderVO(int voIndex, glm::mat4& m, glm::mat4& v, glm::mat4& p)
{
	int size = visualObjectBuffer[voIndex]->m_meshGroups.size();
	int diffuseIndex, normIndex, dispIndex;
	//m = ;

	glUniformMatrix4fv(geo_uniP, 1, GL_FALSE, glm::value_ptr(p));
	glUniformMatrix4fv(geo_uniV, 1, GL_FALSE, glm::value_ptr(v));
	glUniformMatrix4fv(geo_uniM, 1, GL_FALSE, glm::value_ptr(m));
	for (int i = 0; i < size; ++i)
	{
		glBindVertexArray(*visualObjectBuffer[voIndex]->m_meshGroups[i]->m_GLvao);

		diffuseIndex = materialBuffer[visualObjectBuffer[voIndex]->m_materials[i]]->m_maps[1];
		normIndex = materialBuffer[visualObjectBuffer[voIndex]->m_materials[i]]->m_maps[7];
		dispIndex = materialBuffer[visualObjectBuffer[voIndex]->m_materials[i]]->m_maps[5];

		glActiveTexture(GL_TEXTURE0);
		if (diffuseIndex != -1)
		{
			glBindTexture(GL_TEXTURE_2D, textureBuffer[diffuseIndex]->m_texture);
		}
		else
		{
			glBindTexture(GL_TEXTURE_2D, emptyAlbedo);
		}
		glUniform1i(geo_uniDiffuseSampler, 0); //tex unit 0
		glActiveTexture(GL_TEXTURE1);
		if (normIndex != -1)
		{
			glBindTexture(GL_TEXTURE_2D, textureBuffer[normIndex]->m_texture);
		}
		else
		{
			glBindTexture(GL_TEXTURE_2D, emptyNormals);
		}
		glUniform1i(geo_uniNormalSampler, 1); //text unit 1
		if (dispIndex != -1)
		{
			glActiveTexture(GL_TEXTURE2);
			glBindTexture(GL_TEXTURE_2D, textureBuffer[dispIndex]->m_texture);
			glUniform1i(geo_uniDisplacementSampler, 2); //text unit 2
			glUniform1i(geo_uniParallax, 1); //parallax
		}
		else
		{
			glUniform1i(geo_uniParallax, 0); //no parallax
		}

		//glUniform1f(geo_uniMatID, 0.0f);

		glDrawElements(GL_TRIANGLES, *visualObjectBuffer[voIndex]->m_meshGroups[i]->m_indexCount, GL_UNSIGNED_INT, BUFFER_OFFSET(0));

		glBindVertexArray(0);
		glBindTexture(GL_TEXTURE_2D, 0);
	}
}

void drawShadowToBuffer(int voIndex)
{
	int size = visualObjectBuffer[voIndex]->m_meshGroups.size();

	for (int i = 0; i < size; ++i)
	{
		glBindVertexArray(*visualObjectBuffer[voIndex]->m_meshGroups[i]->m_GLvao);

		glDrawElements(GL_TRIANGLES, *visualObjectBuffer[voIndex]->m_meshGroups[i]->m_indexCount, GL_UNSIGNED_INT, BUFFER_OFFSET(0));

		glBindVertexArray(0);
	}
}

//updates lights
void updateLights(glm::mat4& v)
{
	int size = dynamicPLights.size();
	pLightWPos.resize(size);
	for (int i = 0; i < size; ++i)
	{
		pLightWPos[i] = v * dynamicPLights[i].wPos;
	}
	pLightVsPos.clear();
	pLightAttenuations.clear();
	pLightColour.clear();
	viewFrustrum->cullPointLights(dynamicPLights, pLightWPos, pLightVsPos, pLightAttenuations, pLightColour);
	glBindBuffer(GL_TEXTURE_BUFFER, pLightBuffers[0]);
	glBufferData(GL_TEXTURE_BUFFER, sizeof(glm::vec4) * pLightVsPos.size(), pLightVsPos.data(), GL_DYNAMIC_DRAW);
	glBindBuffer(GL_TEXTURE_BUFFER, pLightBuffers[1]);
	glBufferData(GL_TEXTURE_BUFFER, sizeof(glm::vec4) * pLightAttenuations.size(), pLightAttenuations.data(), GL_DYNAMIC_DRAW);
	glBindBuffer(GL_TEXTURE_BUFFER, pLightBuffers[2]);
	glBufferData(GL_TEXTURE_BUFFER, sizeof(glm::vec4) * pLightColour.size(), pLightColour.data(), GL_DYNAMIC_DRAW);
	glBindBuffer(GL_TEXTURE_BUFFER, 0);

	size = dLights.size();
	for (int i = 0; i < size; ++i)
	{
		dLightVsNormalColour[0] = v * dLights[i].wNormal;
		dLightVsNormalColour[1] = dLights[i].lightColour;
	}
}

//renders shadows
void shadowPass(glm::mat4& v, glm::mat4& l, SBuffer* targetMap)
{
	glBindFramebuffer(GL_FRAMEBUFFER, targetMap->sBuffer);
	glViewport(0, 0, targetMap->m_resolution, targetMap->m_resolution);
	glEnable(GL_DEPTH_TEST);
	glClear(GL_DEPTH_BUFFER_BIT);

	int size = dLights.size();
	glm::vec4 dLightTangent;
	glm::vec4 dLightBiTan;
	glm::vec4 dLightNormal;
	for (int i = 0; i < size; ++i)
	{
		dLightVsNormalColour[0] = v * dLights[i].wNormal;
		dLightVsNormalColour[1] = dLights[i].lightColour;
		dLightNormal = -(v * dLights[i].wNormal);
		dLightTangent = v * dLights[i].wTangent;
		dLightBiTan = glm::vec4(glm::cross(glm::vec3(dLightNormal), glm::vec3(dLightTangent)), 0.0f);
	}

	float hLD = viewFrustrum->m_longestDistance / 2.0;
	//glm::mat4 l = glm::ortho(-hLD, hLD, -hLD, hLD, -hLD, hLD);
	glm::mat4 vsl = glm::transpose(glm::mat4(dLightTangent, dLightBiTan, dLightNormal, glm::vec4(0.0f, 0.0f, 0.0f, 1.0f))) * glm::translate(glm::vec3(0.0f, 0.0f, 10.0f));
	l = l * vsl;

	glUseProgram(gl_shdwPass);

	glUniformMatrix4fv(shdw_uniL, 1, GL_FALSE, glm::value_ptr(l));
	glUniformMatrix4fv(shdw_uniV, 1, GL_FALSE, glm::value_ptr(v));

	glm::mat4 m = smallCube.getWorld();
	glUniformMatrix4fv(shdw_uniM, 1, GL_FALSE, glm::value_ptr(m));
	drawShadowToBuffer(vo);

	m = smallSpike.getWorld();
	glUniformMatrix4fv(shdw_uniM, 1, GL_FALSE, glm::value_ptr(m));
	drawShadowToBuffer(spike);
}

//opaque geometry pass
void geometryPass(glm::mat4 &v, glm::mat4 &p, GLint targetFBO)
{
	//geometry render to G Buffer
	glBindFramebuffer(GL_FRAMEBUFFER, targetFBO);
	glViewport(0, 0, gl_iWindowWidth, gl_iWindowHeight);
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::mat4 m;

	glUseProgram(gl_geoPass);
	m = smallCube.getWorld();
	renderVO(vo, m, v, p);
	m = smallSpike.getWorld();
	renderVO(spike, m, v, p);
}

//light geometry pass
void lightingPass(glm::mat4 &v, glm::mat4 &l, GLint targetFBO)
{
	glBindFramebuffer(GL_FRAMEBUFFER, targetFBO); //remember, I have depth test and depth buffer disabled for this pass!!!!!!
	glViewport(0, 0, gl_iWindowWidth, gl_iWindowHeight);
	glUseProgram(gl_lightPass);
	glDisable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT);

	//gets needed values
	float maxDepth = cam->getRenderF();
	float minDepth = cam->getRenderN();
	float projA = maxDepth / (maxDepth - minDepth);
	float projB = (-maxDepth * minDepth) / (maxDepth - minDepth);
	glm::vec3 corners[4];
	viewFrustrum->getFarPoints(corners);
	for (int i = 0; i < 4; ++i)
	{
		corners[i] /= corners[i].z;
		corners[i] *= -1;
	}

	updateLights(v);

	//setup
	//glm::ivec2 tiles = glm::ivec2(gl_iWindowWidth / 32, gl_iWindowHeight / 36);
	glm::ivec2 tiles = glm::ivec2(32, 16);
	glm::vec2 tilesD = glm::vec2(1.0) / glm::vec2(tiles);
	int size = pLightVsPos.size();

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, gl_gBuffer->gDepth);
	glUniform1i(light_uniDepthSampler, 0); //tex unit 0
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, gl_gBuffer->gNormal);
	glUniform1i(light_uniNormalSampler, 1); //tex unit 1
	glActiveTexture(GL_TEXTURE2);
	glBindTexture(GL_TEXTURE_2D, specularLobeShapes);
	glUniform1i(light_uniSpecLobeSampler, 2); //tex unit 2
	glActiveTexture(GL_TEXTURE3);
	glBindTexture(GL_TEXTURE_BUFFER, pLightBTextures[0]);
	glTexBuffer(GL_TEXTURE_BUFFER, GL_RGBA32F, pLightBuffers[0]);
	glUniform1i(light_uniPointLP, 3); //tex unit 3
	glUniform1i(light_uniVPLP, 3); //tex unit 3
	glActiveTexture(GL_TEXTURE4);
	glBindTexture(GL_TEXTURE_BUFFER, pLightBTextures[1]);
	glTexBuffer(GL_TEXTURE_BUFFER, GL_RGBA32F, pLightBuffers[1]);
	glUniform1i(light_uniPointLA, 4); //tex unit 4
	glUniform1i(light_uniVPLA, 4); //tex unit 4
	glActiveTexture(GL_TEXTURE5);
	glBindTexture(GL_TEXTURE_BUFFER, pLightBTextures[2]);
	glTexBuffer(GL_TEXTURE_BUFFER, GL_RGBA32F, pLightBuffers[2]);
	glUniform1i(light_uniPointLC, 5); //tex unit 5
	glActiveTexture(GL_TEXTURE6);
	glBindTexture(GL_TEXTURE_2D, gl_sBuffer->sDepth);
	glUniform1i(light_uniDLightMap, 6); //tex unit 6
	glUniform1f(light_uniProjA, projA);
	glUniform1f(light_uniProjB, projB);
	glUniform1i(light_uniDLight, dLights.size());
	glUniform4fv(light_uniDLightData, 2, glm::value_ptr(dLightVsNormalColour[0]));
	glUniformMatrix4fv(light_uniDLightSpace, 1, GL_FALSE, glm::value_ptr(l));
	glUniform1i(light_uniNumPointL, size);
	glUniform3fv(light_uniCornerBL, 1, glm::value_ptr(corners[2]));
	glUniform2f(light_uniFrustrum, (corners[3].x - corners[2].x), (corners[1].y - corners[2].y));
	glUniform2f(light_uniTileNum, (float)tiles.x, (float)tiles.y);
	glm::vec4 planes[4];

	//renders to LBuffers
	for (int i = 0; i < tiles.x; ++i)
	{
		for (int j = 0; j < tiles.y; ++j)
		{
			planes[0] = glm::vec4(viewFrustrum->m_tiledPlanes[i][j][0].m_normal, viewFrustrum->m_tiledPlanes[i][j][0].m_D);
			planes[1] = glm::vec4(viewFrustrum->m_tiledPlanes[i][j][1].m_normal, viewFrustrum->m_tiledPlanes[i][j][1].m_D);
			planes[2] = glm::vec4(viewFrustrum->m_tiledPlanes[i][j][2].m_normal, viewFrustrum->m_tiledPlanes[i][j][2].m_D);
			planes[3] = glm::vec4(viewFrustrum->m_tiledPlanes[i][j][3].m_normal, viewFrustrum->m_tiledPlanes[i][j][3].m_D);
			glUniform4f(light_uniTilePD, (float)i, (float)j, tilesD.x, tilesD.y);
			glUniform4fv(light_uniCullPlanes, 4, glm::value_ptr(planes[0]));
			drawScreenQuad();
		}
	}
	glBindTexture(GL_TEXTURE_BUFFER, 0);
}

//shading calcualtions aka. putting gbuffer and lbuffer together
void shadingActual(GLint targetFBO)
{
	glBindFramebuffer(GL_FRAMEBUFFER, targetFBO);
	glUseProgram(gl_finalShading);
	glDisable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, gl_gBuffer->gAlbedo);
	glUniform1i(fs_uniAlbedoSampler, 0); //tex unit 0
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, gl_lBuffer->diffuseAccumulation);
	glUniform1i(fs_uniDiffuseASampler, 1); //tex unit 1
	glActiveTexture(GL_TEXTURE2);
	glBindTexture(GL_TEXTURE_2D, gl_lBuffer->specularAccumulation);
	glUniform1i(fs_uniSpecularASampler, 2); //tex unit 2
	drawScreenQuad();
}

//applies anti-aliasing and reinhard tone mapping
void postProcessing(GLint targetFBO, GLint sourceColour, GLint sourceBloom, int width, int height)
{
	glBindFramebuffer(GL_FRAMEBUFFER, targetFBO);
	glViewport(0, 0, width, height);
	glUseProgram(gl_postProcess);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, sourceColour);
	glUniform1i(pp_uniSampler, 0); //tex unit 0
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, sourceBloom);
	glUniform1i(pp_uniBloom, 1); //tex unit 1
	glUniform2f(pp_uniTexelOffset, 1.0 / width, 1.0 / height);
	drawScreenQuad();
}

//downsamples an image
void downSamplePass(GLint sourceTexture, GLint targetFBO, int width, int height)
{
	glUseProgram(gl_downSample);
	glDisable(GL_DEPTH_TEST);

	glBindFramebuffer(GL_FRAMEBUFFER, targetFBO); //11x11
	glViewport(0, 0, width, height);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, sourceTexture);
	glUniform1i(dd_uniSampler, 0); //tex unit 0
	drawScreenQuad();
}

//two-pass 5x5 gaussian blurs an image and outputs to pingpongTwo
void gaussianBlurFivePX(GLint sourceTexture, BBuffer* pingpongOne, BBuffer* pingpongTwo, float xOffset, float yOffset)
{
	//bloom pass 5x5
	glBindFramebuffer(GL_FRAMEBUFFER, pingpongOne->bBuffer); //horizantal
	glViewport(0, 0, pingpongOne->m_width, pingpongOne->m_height);
	glUseProgram(gl_directionalBlur);
	glDisable(GL_DEPTH_TEST);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, sourceTexture);
	glUniform1i(db_uniTargetSampler, 0); //tex unit 0
	glUniform2f(db_uniTexelOffset, xOffset, yOffset);
	glUniform2f(db_uniDirection, 1.0, 0.0);
	drawScreenQuad();

	glBindFramebuffer(GL_FRAMEBUFFER, pingpongTwo->bBuffer); //vertical
	glDisable(GL_DEPTH_TEST);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, pingpongOne->bColour);
	glUniform1i(db_uniTargetSampler, 0); //tex unit 0
	glUniform2f(db_uniDirection, 0.0, 1.0);
	drawScreenQuad();
}

//activates bloom effect and final outputs to gl_bBuffer[0]
void bloomPass(GLint sourceTexture)
{
	//downsamples for bloom
	downSamplePass(sourceTexture, gl_bBuffer[3]->bBuffer, gl_bBuffer[3]->m_width, gl_bBuffer[3]->m_height); //11x11
	downSamplePass(gl_bBuffer[3]->bColour, gl_bBuffer[5]->bBuffer, gl_bBuffer[5]->m_width, gl_bBuffer[5]->m_height); //21x21
	downSamplePass(gl_bBuffer[5]->bColour, gl_bBuffer[7]->bBuffer, gl_bBuffer[7]->m_width, gl_bBuffer[7]->m_height); //42x42

																													 //bloom pass 5x5
	gaussianBlurFivePX(sourceTexture, gl_bBuffer[0], gl_bBuffer[1], 1.0 / gl_iWindowWidth, 1.0 / gl_iWindowHeight);
	//bloom pass 11x11
	gaussianBlurFivePX(gl_bBuffer[3]->bColour, gl_bBuffer[2], gl_bBuffer[3], 2.0 / gl_iWindowWidth, 2.0 / gl_iWindowHeight);
	//bloom pass 21x21
	gaussianBlurFivePX(gl_bBuffer[5]->bColour, gl_bBuffer[4], gl_bBuffer[5], 4.0 / gl_iWindowWidth, 4.0 / gl_iWindowHeight);
	//bloom pass 42x42
	gaussianBlurFivePX(gl_bBuffer[7]->bColour, gl_bBuffer[6], gl_bBuffer[7], 16.0 / gl_iWindowWidth, 16.0 / gl_iWindowHeight);

	//bright pass
	glBindFramebuffer(GL_FRAMEBUFFER, gl_bBuffer[0]->bBuffer); //horizantal buffer
	glDisable(GL_DEPTH_TEST);
	glViewport(0, 0, gl_iWindowWidth, gl_iWindowHeight);
	glUseProgram(gl_brightPass);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, gl_bBuffer[1]->bColour);
	glUniform1i(b_uniBloom, 0); //tex unit 0
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, gl_bBuffer[3]->bColour);
	glUniform1i(b_uniBloomTwo, 1); //tex unit 1
	glActiveTexture(GL_TEXTURE2);
	glBindTexture(GL_TEXTURE_2D, gl_bBuffer[5]->bColour);
	glUniform1i(b_uniBloomFour, 2); //tex unit 2
	glActiveTexture(GL_TEXTURE3);
	glBindTexture(GL_TEXTURE_2D, gl_bBuffer[7]->bColour);
	glUniform1i(b_uniBloomSixteen, 3); //tex unit 3
	drawScreenQuad();

	//bright pass blur
	gaussianBlurFivePX(gl_bBuffer[0]->bColour, gl_bBuffer[1], gl_bBuffer[0], 1.0 / gl_iWindowWidth, 1.0 / gl_iWindowHeight);
}

//final shading pass, reads from existing gbuffer and lbuffer to output to screen
void shadingPass()
{
	//shades
	shadingActual(gl_scBuffer->scBuffer);
	
	//applies bloom effect
	bloomPass(gl_scBuffer->exposureTarget);

	//post-processing pass
	postProcessing(0, gl_scBuffer->scColour, gl_bBuffer[0]->bColour, gl_iWindowWidth, gl_iWindowHeight);
}

//renders active scene
void renderScene()
{
	glm::mat4 v = cam->getViewMatrix();
	glm::mat4 p = cam->getProjMatrix();
	glm::mat4 l = glm::ortho(-20.0f, 20.0f, -20.0f, 20.0f, -20.0f, 20.0f); //directional light's orthogonal matrix

	geometryPass(v, p, gl_gBuffer->gBuffer);
	shadowPass(v, l, gl_sBuffer);
	lightingPass(v, l, gl_lBuffer->lBuffer);
	shadingPass();
}

//returns shader ID if successful, or else returns 0 if not
GLuint loadShader(GLenum shaderType, const std::string& shaderFile)
{
	std::ifstream ifs;

	//Loads Shader Source
	ifs.open(shaderFile);

	//checks if opened successfully
	if (!ifs)
	{
		std::cerr << "Cannot Open Shader File: \"" << shaderFile << "\"" << std::endl;
		return 0;
	}

	//copies shaderfile to source
	std::string source(std::istreambuf_iterator<char>(ifs), (std::istreambuf_iterator<char>()));

	ifs.close();

	//Creates Shader Object
	GLuint shader = glCreateShader(shaderType);

	//loads shader source for each shader object and compiles
	const GLchar* sources[] = { source.c_str() };
	glShaderSource(shader, 1, sources, NULL);
	glCompileShader(shader);

	//checks for compiler errors
	GLint compileStatus;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compileStatus);
	/*
	if (compileStatus != GL_TRUE)
	{
		GLint logLength;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);
		GLchar* infoLog = new GLchar[logLength];
		glGetShaderInfoLog(shader, logLength, NULL, infoLog);

#ifdef _WIN32
		OutputDebugString(infoLog);
#else
		std::cerr << infoLog << std::endl;
#endif
		delete infoLog;
		return 0;
	}
	*/
	GLint logLength;
	glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);
	GLchar* infoLog = new GLchar[logLength];
	glGetShaderInfoLog(shader, logLength, NULL, infoLog);
	std::cout << infoLog << std::endl;

	return shader;
}

//creates openGL shader program, returning 0 if link status failed
GLuint createShaderProgram(std::vector<GLuint> shaders)
{
	//Creates Shader Proram
	GLuint program = glCreateProgram();

	//Attaches all the appropriate shaders
	for (GLuint shader : shaders)
	{
		glAttachShader(program, shader);
	}

	glLinkProgram(program); //links program

	//Check Link Status
	GLint linkStatus;
	glGetProgramiv(program, GL_LINK_STATUS, &linkStatus);
	/*
	if (linkStatus != GL_TRUE)
	{
		GLint logLength;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);
		GLchar* infoLog = new GLchar[logLength];

		glGetProgramInfoLog(program, logLength, NULL, infoLog);

#ifdef _WIN32
		OutputDebugString(infoLog);
#else
		std::cerr << infoLog << std::endl;
#endif
		delete infoLog;
		return 0;
	}
	*/
	GLint logLength;
	glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);
	GLchar* infoLog = new GLchar[logLength];
	glGetProgramInfoLog(program, logLength, NULL, infoLog);
	std::cout << infoLog << "\n------------------" << std::endl;

	return program;
}

//standard 3D Camera
void initializeCtrl3DCamera(Camera *&userDefCam, unsigned int type, bool fly)
{
	if (!ctrlThreeDCam)
	{
		ctrlThreeDCam = true;
	}
	activeCameraType = type;
	switch (type)
	{
	case CTRL_UNOPTQUATCAM:
		userDefCam = new UnOptQuatCamera(fly);
		userDefCam->setupCamera(&x, &y, &z, &mX, &mY, &mZ, &gl_fAspectRatio);
		userDefCam->setViewPort(0, 0, gl_iWindowWidth, gl_iWindowHeight);
		break;
	case CTRL_OPTQUATCAM:
		//*userDefCam = new OptQuatCamera();
		break;
	case CTRL_FPSCAM:
		userDefCam = new FPSCamera(fly);
		userDefCam->setupCamera(&x, &y, &z, &mX, &mY, &mZ, &gl_fAspectRatio);
		userDefCam->setViewPort(0, 0, gl_iWindowWidth, gl_iWindowHeight);
		break;
	case CTRL_LOOKATCAM:
		//userDefCam = new LookAtCamera();
		break;
	case CTRL_ARCBALLCAM:
		//userDefCam = new ArcBallCamera();
		break;
	case CTRL_TWODCAM:
		//dont know what to do
		break;
	}
	viewFrustrum = new Frustrum(*userDefCam);
}
/*
//standard 2D Camera
void initializeCtrl2DCamera(Camera **userDefCam)
{
	if (!ctrlTwoDCam)
	{
		ctrlTwoDCam = true;
	}
	*userDefCam = new UnOptQuatCamera();
}
*/
void displayUpdate()
{
	cam->updateVP();

	renderScene();
	
	glutSwapBuffers();
}

void idle()
{
	updateTime();
	
	if (activeCameraType == CTRL_UNOPTQUATCAM)
	{
		if (CTRL_Ka && !CTRL_Kd)
		{
			mZ = 90 * gl_dSecondsElapsed;
		}
		else if (!CTRL_Ka && CTRL_Kd)
		{
			mZ = -90 * gl_dSecondsElapsed;;
		}
		else
		{
			mZ = 0;
		}
		cam->updateCameraRot();
	}
	else if (activeCameraType == CTRL_FPSCAM)
	{
		if (CTRL_Kw)
		{
			z = -3.5 * gl_dSecondsElapsed;
		}
		else if (CTRL_Ks)
		{
			z = 2.5 * gl_dSecondsElapsed;
		}
		else
		{
			z = 0;
		}
		if (CTRL_Ka)
		{
			x = 3 * gl_dSecondsElapsed;
		}
		else if (CTRL_Kd)
		{
			x = -3 * gl_dSecondsElapsed;
		}
		else
		{
			x = 0;
		}
		if (CTRL_KSPACE)
		{
			y = 3 * gl_dSecondsElapsed;
		}
		else if (CTRL_KSHIFT_IN)
		{
			y = -3 * gl_dSecondsElapsed;
		}
		else
		{
			y = 0;
		}
	}
	cam->updateCameraPos();

	glutPostRedisplay();
}

void mouseHandle(int x, int y)
{
	if (!CTRL_GAME_PAUSED) //if has change, gives camera radian input
	{
		x = gl_iCenter[0] - x;
		y = gl_iCenter[1] - y;
		mX = x;
		mY = y;
		if (x || y)
		{
			glutWarpPointer(gl_iCenter[0], gl_iCenter[1]);
		}
	}
	cam->updateCameraRot();
}

void mouseClick(int button, int state, int x, int y)
{

}

void keyboardHandle(unsigned char c, int x, int y)
{
	switch (c)
	{
	case 27: //ESC
		if (!CTRL_GAME_PAUSED)
		{
			pause = true;
			glutSetCursor(GLUT_CURSOR_INHERIT);
		}
		key[KESCAPE] = true;
		break;
	case 13: //Enter
		if (CTRL_GAME_PAUSED)
		{
			pause = false;
			glutSetCursor(GLUT_CURSOR_NONE);
			glutWarpPointer(gl_iCenter[0], gl_iCenter[1]);
		}
		key[KENTER] = true;
		break;
	case 'w':
		key[Kw] = true;
		break;
	case 'a':
		key[Ka] = true;
		break;
	case 's':
		key[Ks] = true;
		break;
	case 'd':
		key[Kd] = true;
		break;
	case ' ':
		key[KSPACE] = true;
		break;
	case 'f':
		key[Kf] = true;
		std::cout << gl_dSecondsElapsed << std::endl; //fps check
		break;
	}
	//cam->updateCameraRot();
	//key[c] = true;
}

void keyboardUp(unsigned char c, int x, int y)
{
	switch (c)
	{
	case 27:
		key[KESCAPE] = false;
		break;
	case 13:
		key[KENTER] = false;
		break;
	case 'd':
		key[Kd] = false;
		break;
	case 's':
		key[Ks] = false;
		break;
	case 'a':
		key[Ka] = false;
		break;
	case 'w':
		key[Kw] = false;
		break;
	case ' ':
		key[KSPACE] = false;
		break;
	case 'f':
		key[Kf] = false;
		break;
	}
}

void specialHandle(int c, int x, int y)
{
	int mod;
	mod = glutGetModifiers();
	if (mod == GLUT_ACTIVE_SHIFT)
	{
		key[KSHIFT_IN] = true;
	}
	else
	{
		key[KSHIFT_IN] = false;
	}
}

void specialUp(int c, int x, int y)
{
	int mod;
	mod = glutGetModifiers();
	if (mod == GLUT_ACTIVE_SHIFT)
	{
		key[KSHIFT_IN] = true;
	}
	else
	{
		key[KSHIFT_IN] = false;
	}
}

void resizeWindow(int w, int h)
{

}

int main(int argc, char *argv[])
{
	//setup
	initializeGL(argc, argv);
	initializeGLEW();
	gl_gBuffer = new GBuffer(&gl_iWindowWidth, &gl_iWindowHeight);
	gl_gBuffer->init();
	gl_lBuffer = new LBuffer(&gl_iWindowWidth, &gl_iWindowHeight);
	gl_lBuffer->init();
	gl_sBuffer = new SBuffer(1024);
	gl_sBuffer->init();
	gl_scBuffer = new SCBuffer(gl_iWindowWidth, gl_iWindowHeight);
	gl_scBuffer->init();
	gl_bBuffer[0] = new BBuffer(gl_iWindowWidth, gl_iWindowHeight); //5x1
	gl_bBuffer[0]->init();
	gl_bBuffer[1] = new BBuffer(gl_iWindowWidth, gl_iWindowHeight); //5x5
	gl_bBuffer[1]->init();
	gl_bBuffer[2] = new BBuffer(gl_iWindowWidth / 2, gl_iWindowHeight / 2); //11x1
	gl_bBuffer[2]->init();
	gl_bBuffer[3] = new BBuffer(gl_iWindowWidth / 2, gl_iWindowHeight / 2); //11x11
	gl_bBuffer[3]->init();
	gl_bBuffer[4] = new BBuffer(gl_iWindowWidth / 4, gl_iWindowHeight / 4); //21x1
	gl_bBuffer[4]->init();
	gl_bBuffer[5] = new BBuffer(gl_iWindowWidth / 4, gl_iWindowHeight / 4); //21x21
	gl_bBuffer[5]->init();
	gl_bBuffer[6] = new BBuffer(gl_iWindowWidth / 16, gl_iWindowHeight / 16); //42x1
	gl_bBuffer[6]->init();
	gl_bBuffer[7] = new BBuffer(gl_iWindowWidth / 16, gl_iWindowHeight / 16); //42x42
	gl_bBuffer[7]->init();
	glGenBuffers(3, pLightBuffers);
	glGenTextures(3, pLightBTextures);

	initializeCtrl3DCamera(cam, CTRL_FPSCAM, false);
	dLights.reserve(1);
	pLightVsPos.reserve(1024);
	pLightAttenuations.reserve(1024);
	pLightColour.reserve(1024);

	directionalLight dirL{ glm::normalize(glm::vec4(0.0f, -1.0f, 0.0f, 0.0f)), glm::normalize(glm::vec4(1.0f, 0.0f, 0.0f, 0.0f)), glm::vec4(1.0) };
	dLights.push_back(dirL);/*
	for (int i = 0; i < 32; ++i)
	{
		for (int j = 0; j < 16; ++j)
		{
			pointLight light{ glm::vec4(-80.0 + (i * 5), -170.0, -80.0 + (j * 10), 1.0), glm::vec4(1.0, 0.15, 0.15, 10.0), glm::vec4(i / 32.0, j / 16.0, 1.0, 1.0) };
			dynamicPLights.push_back(light);
			pLightWPos.push_back(glm::vec4(-80.0 + (i * 5), -170.0, -80.0 + (j * 10), 1.0));
			pLightVsPos.push_back(glm::vec4(0.0));
			pLightAttenuations.push_back(glm::vec4(1.0, 0.15, 0.15, 10.0));
			pLightColour.push_back(glm::vec4(i / 32.0, j / 16.0, 1.0, 1.0));
		}
	}*/
	
	glBindBuffer(GL_TEXTURE_BUFFER, pLightBuffers[0]);
	glBufferData(GL_TEXTURE_BUFFER, sizeof(glm::vec4) * pLightVsPos.size(), pLightVsPos.data(), GL_DYNAMIC_DRAW);
	glBindBuffer(GL_TEXTURE_BUFFER, 0);
	glBindTexture(GL_TEXTURE_BUFFER, pLightBTextures[0]);
	glTexBuffer(GL_TEXTURE_BUFFER, GL_RGBA32F, pLightBuffers[0]);
	glBindBuffer(GL_TEXTURE_BUFFER, pLightBuffers[1]);
	glBufferData(GL_TEXTURE_BUFFER, sizeof(glm::vec4) * pLightAttenuations.size(), pLightAttenuations.data(), GL_DYNAMIC_DRAW);
	glBindBuffer(GL_TEXTURE_BUFFER, 0);
	glBindTexture(GL_TEXTURE_BUFFER, pLightBTextures[1]);
	glTexBuffer(GL_TEXTURE_BUFFER, GL_RGBA32F, pLightBuffers[1]);
	glBindBuffer(GL_TEXTURE_BUFFER, pLightBuffers[2]);
	glBufferData(GL_TEXTURE_BUFFER, sizeof(glm::vec4) * pLightColour.size(), pLightColour.data(), GL_DYNAMIC_DRAW);
	glBindBuffer(GL_TEXTURE_BUFFER, 0);
	glBindTexture(GL_TEXTURE_BUFFER, pLightBTextures[2]);
	glTexBuffer(GL_TEXTURE_BUFFER, GL_RGBA32F, pLightBuffers[2]);
	glBindTexture(GL_TEXTURE_BUFFER, 0);

	/*
	pLightWPos.push_back(glm::vec3(-1.0, 1.0, -7.0));
	pLightVsPos.push_back(glm::vec3(0.0));
	pLightAttenuations.push_back(glm::vec2(0.0));
	pLightRadius.push_back(200.0);
	pLightColour.push_back(glm::vec3(0.7));*/

	//loads dsp shaders
	GLuint vertexShader = loadShader(GL_VERTEX_SHADER, "Shaders/Basic/Ctrl 3k TextureDiffuse.vert");
	GLuint fragmentShader = loadShader(GL_FRAGMENT_SHADER, "Shaders/Basic/Ctrl 3k TextureDiffuse.frag");

	std::vector<GLuint> shaders;
	shaders.push_back(vertexShader);
	shaders.push_back(fragmentShader);

	//creates dsp shader program
	gl_diffuseSP = createShaderProgram(shaders);
	assert(gl_diffuseSP);

	dsp_uniV = glGetUniformLocation(gl_diffuseSP, "V");
	dsp_uniP = glGetUniformLocation(gl_diffuseSP, "P");
	dsp_uniM = glGetUniformLocation(gl_diffuseSP, "M");
	dsp_uniWEyePos = glGetUniformLocation(gl_diffuseSP, "wEyePos");
	//light
	dsp_uniWLightPos = glGetUniformLocation(gl_diffuseSP, "wLightPos");
	dsp_uniLightColour = glGetUniformLocation(gl_diffuseSP, "lightColour");
	//ambient contribution
	dsp_uniAmbient = glGetUniformLocation(gl_diffuseSP, "ambient");
	//material
	dsp_uniMaterialEmissive = glGetUniformLocation(gl_diffuseSP, "materialEmissive");
	dsp_uniMaterialDiffuse = glGetUniformLocation(gl_diffuseSP, "materialDiffuse");
	dsp_uniMaterialSpecular = glGetUniformLocation(gl_diffuseSP, "materialSpecular");
	dsp_uniMaterialShininess = glGetUniformLocation(gl_diffuseSP, "materialShininess");
	dsp_uniMaterialSharpness = glGetUniformLocation(gl_diffuseSP, "materialSharpness");
	//samplers
	dsp_uniDiffuseSampler = glGetUniformLocation(gl_diffuseSP, "diffuseSampler");
	/*
	//loads dnsp shaders
	vertexShader = loadShader(GL_VERTEX_SHADER, "Shaders/Basic/Ctrl 3k TextureDiffuseNormal.vert");
	fragmentShader = loadShader(GL_FRAGMENT_SHADER, "Shaders/Basic/Ctrl 3k TextureDiffuseNormal.frag");

	shaders.clear();
	shaders.push_back(vertexShader);
	shaders.push_back(fragmentShader);

	//creates dnsp shader program
	gl_diNoSP = createShaderProgram(shaders);
	assert(gl_diNoSP);

	dnsp_uniMVP = glGetUniformLocation(gl_diNoSP, "MVP");
	dnsp_uniM = glGetUniformLocation(gl_diNoSP, "M");
	dnsp_uniWEyePos = glGetUniformLocation(gl_diNoSP, "wEyePos");
	//light
	dnsp_uniWLightPos = glGetUniformLocation(gl_diNoSP, "wLightPos");
	dnsp_uniLightColour = glGetUniformLocation(gl_diNoSP, "lightColour");
	//ambient contribution
	dnsp_uniAmbient = glGetUniformLocation(gl_diNoSP, "ambient");
	//material
	dnsp_uniMaterialEmissive = glGetUniformLocation(gl_diNoSP, "materialEmissive");
	dnsp_uniMaterialDiffuse = glGetUniformLocation(gl_diNoSP, "materialDiffuse");
	dnsp_uniMaterialSpecular = glGetUniformLocation(gl_diNoSP, "materialSpecular");
	dnsp_uniMaterialShininess = glGetUniformLocation(gl_diNoSP, "materialShininess");
	dnsp_uniMaterialSharpness = glGetUniformLocation(gl_diNoSP, "materialSharpness");
	//samplers
	dnsp_uniDiffuseSampler = glGetUniformLocation(gl_diNoSP, "diffuseSampler");
	dnsp_uniNormalSampler = glGetUniformLocation(gl_diNoSP, "normalSampler");
	*/
	//loads geometry pass shaders
	vertexShader = loadShader(GL_VERTEX_SHADER, "Shaders/Deferred/Ctrl 3k Geometry.vert");
	fragmentShader = loadShader(GL_FRAGMENT_SHADER, "Shaders/Deferred/Ctrl 3k Geometry.frag");

	shaders.clear();
	shaders.push_back(vertexShader);
	shaders.push_back(fragmentShader);

	//creates geometry pass shader program
	gl_geoPass = createShaderProgram(shaders);
	assert(gl_geoPass);

	geo_uniM = glGetUniformLocation(gl_geoPass, "M");
	geo_uniV = glGetUniformLocation(gl_geoPass, "V");
	geo_uniP = glGetUniformLocation(gl_geoPass, "P");
	geo_uniMatID = glGetUniformLocation(gl_geoPass, "matID");
	geo_uniDiffuseSampler = glGetUniformLocation(gl_geoPass, "diffuseSampler");
	geo_uniNormalSampler = glGetUniformLocation(gl_geoPass, "normalSampler");
	geo_uniDisplacementSampler = glGetUniformLocation(gl_geoPass, "displaceSampler");
	geo_uniParallax = glGetUniformLocation(gl_geoPass, "parallaxMap");

	//loads shadow pass shaders
	vertexShader = loadShader(GL_VERTEX_SHADER, "Shaders/Deferred/Ctrl 3k ShadowOrthogonal.vert");
	fragmentShader = loadShader(GL_FRAGMENT_SHADER, "Shaders/Deferred/Ctrl 3k ShadowOrthogonal.frag");

	shaders.clear();
	shaders.push_back(vertexShader);
	shaders.push_back(fragmentShader);

	//creates shadow pass shader program
	gl_shdwPass = createShaderProgram(shaders);
	assert(gl_shdwPass);

	shdw_uniM = glGetUniformLocation(gl_shdwPass, "M");
	shdw_uniV = glGetUniformLocation(gl_shdwPass, "V");
	shdw_uniL = glGetUniformLocation(gl_shdwPass, "L");

	//loads light pass shaders
	vertexShader = loadShader(GL_VERTEX_SHADER, "Shaders/Deferred/Ctrl 3k LightGeometry.vert");
	fragmentShader = loadShader(GL_FRAGMENT_SHADER, "Shaders/Deferred/Ctrl 3k LightGeometry.frag");

	shaders.clear();
	shaders.push_back(vertexShader);
	shaders.push_back(fragmentShader);

	//creates light pass shader program
	gl_lightPass = createShaderProgram(shaders);
	assert(gl_lightPass);

	light_uniCornerBL = glGetUniformLocation(gl_lightPass, "mainFrustrumCBL");
	light_uniFrustrum = glGetUniformLocation(gl_lightPass, "frustrumDimensions");
	light_uniTileNum = glGetUniformLocation(gl_lightPass, "numTiles");
	light_uniTilePD = glGetUniformLocation(gl_lightPass, "tilePosDimensions");
	light_uniVPLP = glGetUniformLocation(gl_lightPass, "pLightPosition");
	light_uniVPLA = glGetUniformLocation(gl_lightPass, "pLightAttenuation");
	light_uniProjA = glGetUniformLocation(gl_lightPass, "projectionConstantA");
	light_uniProjB = glGetUniformLocation(gl_lightPass, "projectionConstantB");
	light_uniPointLP = glGetUniformLocation(gl_lightPass, "pLightPos");
	light_uniPointLA = glGetUniformLocation(gl_lightPass, "pLightAtt");
	light_uniPointLC = glGetUniformLocation(gl_lightPass, "pLightColour");
	light_uniDLight = glGetUniformLocation(gl_lightPass, "dLight");
	light_uniDLightData = glGetUniformLocation(gl_lightPass, "dLightNC");
	light_uniDLightSpace = glGetUniformLocation(gl_lightPass, "dLightSpaceTrans");
	light_uniNumPointL = glGetUniformLocation(gl_lightPass, "numPLights");
	light_uniCullPlanes = glGetUniformLocation(gl_lightPass, "cullPlanes");
	light_uniSpecLobeSampler = glGetUniformLocation(gl_lightPass, "specularShape");
	light_uniDLightMap = glGetUniformLocation(gl_lightPass, "dLightMap");
	light_uniDepthSampler = glGetUniformLocation(gl_lightPass, "depthSampler");
	light_uniNormalSampler = glGetUniformLocation(gl_lightPass, "normalSampler");

	//loads render pass shaders
	vertexShader = loadShader(GL_VERTEX_SHADER, "Shaders/Deferred/Ctrl 3k FinalShading.vert");
	fragmentShader = loadShader(GL_FRAGMENT_SHADER, "Shaders/Deferred/Ctrl 3k FinalShading.frag");

	shaders.clear();
	shaders.push_back(vertexShader);
	shaders.push_back(fragmentShader);

	//creates render pass shader program
	gl_finalShading = createShaderProgram(shaders);
	assert(gl_finalShading);

	fs_uniAlbedoSampler = glGetUniformLocation(gl_finalShading, "albedoSampler");
	fs_uniDiffuseASampler = glGetUniformLocation(gl_finalShading, "diffuseAccumulation");
	fs_uniSpecularASampler = glGetUniformLocation(gl_finalShading, "specularAccumulation");

	//loads bloom pass shaders
	vertexShader = loadShader(GL_VERTEX_SHADER, "Shaders/Deferred/Ctrl 3k DirectionBlur.vert");
	fragmentShader = loadShader(GL_FRAGMENT_SHADER, "Shaders/Deferred/Ctrl 3k DirectionBlur.frag");

	shaders.clear();
	shaders.push_back(vertexShader);
	shaders.push_back(fragmentShader);

	//creates bloom pass shader program
	gl_directionalBlur = createShaderProgram(shaders);
	assert(gl_directionalBlur);

	db_uniTargetSampler = glGetUniformLocation(gl_directionalBlur, "targetTexture");
	db_uniDirection = glGetUniformLocation(gl_directionalBlur, "direction");
	db_uniTexelOffset = glGetUniformLocation(gl_directionalBlur, "texelOffset");

	//loads downSample pass shaders
	vertexShader = loadShader(GL_VERTEX_SHADER, "Shaders/Deferred/Ctrl 3k DownSample.vert");
	fragmentShader = loadShader(GL_FRAGMENT_SHADER, "Shaders/Deferred/Ctrl 3k DownSample.frag");

	shaders.clear();
	shaders.push_back(vertexShader);
	shaders.push_back(fragmentShader);

	//creates downSample pass shader program
	gl_downSample = createShaderProgram(shaders);
	assert(gl_downSample);

	dd_uniSampler = glGetUniformLocation(gl_downSample, "source");

	//loads bright pass pass shaders
	vertexShader = loadShader(GL_VERTEX_SHADER, "Shaders/Deferred/Ctrl 3k BrightPass.vert");
	fragmentShader = loadShader(GL_FRAGMENT_SHADER, "Shaders/Deferred/Ctrl 3k BrightPass.frag");

	shaders.clear();
	shaders.push_back(vertexShader);
	shaders.push_back(fragmentShader);

	//creates bright pass shader program
	gl_brightPass = createShaderProgram(shaders);
	assert(gl_brightPass);

	b_uniBloom = glGetUniformLocation(gl_brightPass, "bloom");
	b_uniBloomTwo = glGetUniformLocation(gl_brightPass, "bloomTwo");
	b_uniBloomFour = glGetUniformLocation(gl_brightPass, "bloomFour");
	b_uniBloomSixteen = glGetUniformLocation(gl_brightPass, "bloomSixteen");

	//loads postProcessing pass shaders
	vertexShader = loadShader(GL_VERTEX_SHADER, "Shaders/Deferred/Ctrl 3k PostProcess.vert");
	fragmentShader = loadShader(GL_FRAGMENT_SHADER, "Shaders/Deferred/Ctrl 3k PostProcess.frag");

	shaders.clear();
	shaders.push_back(vertexShader);
	shaders.push_back(fragmentShader);

	//creates postProcessing pass shader program
	gl_postProcess = createShaderProgram(shaders);
	assert(gl_postProcess);

	pp_uniSampler = glGetUniformLocation(gl_postProcess, "targetTexture");
	pp_uniBloom = glGetUniformLocation(gl_postProcess, "bloomTexture");
	pp_uniBloomTwo = glGetUniformLocation(gl_postProcess, "bloomTextureTwo");
	pp_uniBloomFour = glGetUniformLocation(gl_postProcess, "bloomTextureFour");
	pp_uniTexelOffset = glGetUniformLocation(gl_postProcess, "texelOffset");

	//load game data
	tempParallax = loadTexture("Resources/Textures/Doom_b.jpg");
	tempNormal = loadTexture("Resources/Textures/Doom_bN.jpg");
	tempDiffuse = loadTexture("Resources/Textures/Grid.jpg");

	emptyAlbedo = loadTexture("Resources/Textures/Material Library/emptyAlbedoMap.png", false);
	glBindTexture(GL_TEXTURE_2D, emptyAlbedo);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glBindTexture(GL_TEXTURE_2D, 0);

	emptyNormals = loadTexture("Resources/Textures/Material Library/emptyNormalMap.png", false);
	glBindTexture(GL_TEXTURE_2D, emptyNormals);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glBindTexture(GL_TEXTURE_2D, 0);

	specularLobeShapes = loadTexture("Resources/Textures/Material Library/specularLobeShape.png", false);
	glBindTexture(GL_TEXTURE_2D, specularLobeShapes);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glBindTexture(GL_TEXTURE_2D, 0);

	specularTints = loadTexture("Resources/Textures/Material Library/specularTint.png", false);
	glBindTexture(GL_TEXTURE_2D, specularTints);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glBindTexture(GL_TEXTURE_2D, 0);

	vo = loadVO("Resources/Models/plane.obj");
	spike = loadVO("Resources/Models/spike.obj");

	std::cout << GL_MAX_VERTEX_UNIFORM_VECTORS << " " << GL_MAX_VERTEX_ATTRIBS << std::endl;

	//game loop
	glutMainLoop();

	//clean up
	delete cam;
	cam = NULL;
	delete viewFrustrum;
	viewFrustrum = NULL;

	clearMaterialBuffer();
	clearTextureBuffer();
	clearVOBuffer();
	
	delete gl_gBuffer;
	gl_gBuffer = NULL;
	delete gl_lBuffer;
	gl_lBuffer = NULL;
	delete gl_sBuffer;
	gl_sBuffer = NULL;
	delete gl_scBuffer;
	gl_scBuffer = NULL;
	delete gl_bBuffer[0];
	gl_bBuffer[0] = NULL;
	delete gl_bBuffer[1];
	gl_bBuffer[1] = NULL;
	delete gl_bBuffer[2];
	gl_bBuffer[2] = NULL;
	delete gl_bBuffer[3];
	gl_bBuffer[3] = NULL;
	delete gl_bBuffer[4];
	gl_bBuffer[4] = NULL;
	delete gl_bBuffer[5];
	gl_bBuffer[5] = NULL;
	delete gl_bBuffer[6];
	gl_bBuffer[6] = NULL;
	delete gl_bBuffer[7];
	gl_bBuffer[7] = NULL;

	return 0;
}