#pragma once

//window-related
void updateCenter();
void updateTime();

//textureBuffer functions
int loadTextureObject(std::string filePath);
int findTexture(std::string name);
void clearTextureBuffer();

//materialBuffer functions
int loadMaterial(std::string &name, Material *&mat);
int findMaterial(std::string name);
void clearMaterialBuffer();

//viusalObjectBuffer functions
int loadVO(std::string filePath);
int findVO(std::string name);
void clearVOBuffer();

//GLUT callback functions
void mouseHandle(int x, int y);
void mouseClick(int button, int state, int x, int y);
void idle();
void displayUpdate();
void keyboardHandle(unsigned char c, int x, int y);
void keyboardUp(unsigned char c, int x, int y);
void specialHandle(int key, int x, int y); //for special keys like shift
void specialUp(int key, int x, int y);
void resizeWindow(int w, int h);