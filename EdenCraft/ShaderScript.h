#pragma once

#include <string>

#pragma warning(push)
#pragma warning(disable : 4505)
#include "GL\glew.h"
#include "GL\freeglut.h"
#pragma warning(pop)

class ShaderScript
{
public:
	ShaderScript();
	~ShaderScript();

	void loadVertexShader(std::string vsScript);
	void loadFragmentShader(std::string fsScript);
	
	void loadVertexShaderFromFile(std::string vsFile);
	void loadFragmentShaderFromFile(std::string fsFile);

	void generate();
	void activate();

private:
	GLuint program;
};
