#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

#define GLEW_STATIC
#include <GL/glew.h>
#ifdef _WIN32
#include <GL/wglew.h>
#endif

#include <GL/freeglut.h>

#include <SOIL.h>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/quaternion.hpp>

#include <Classes/semantics.h>

#include <Classes/3D/Basic Structs.h>
#include <Classes/Additional Math/Additional Operations.h>

#include <Classes/Render/Camera.h>
#include <Classes/Render/Frustrum.h>
#include <Classes/Render/UnOptQuatCamera.h>
#include <Classes/Render/FPSCamera.h>

#include <Classes/3D/TriMesh.h>
#include <Classes/Render/Material.h>
#include <Classes/3D/Basic Geometry.h>
#include <Classes/3D/VisualObject.h>

#include <Classes/3D/MeshLoader.h>
#include <Classes/Linker/DataBlock.h>
#include <Classes/Linker/PrimitiveObjectLoader.h>

#include <Classes/Render/GBuffer.h>
#include <Classes/Render/LBuffer.h>
#include <Classes/Render/SBuffer.h>
#include <Classes/Render/BBuffer.h>
#include <Classes/Render/SCBuffer.h>

#include <mainFile.h>