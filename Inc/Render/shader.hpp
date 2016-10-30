#pragma once

#include <Macros/generateGetAndSet.hpp>

#define GLEW_STATIC
#include <GL/glew.h>

#include <SDL.h>
#include <SDL_opengl.h>

namespace render {

enum ShaderType {
	VertexShader,
	FragmentShader,
};

class Shader {
private:
	const GLchar* source_;

	ShaderType type_;

	GLuint shaderToken_;
	
public:
	Shader();

	void compile();

	GLuint shaderToken(){
		return shaderToken_;
	}

	GENERATE_GETTERS_AND_SETTERS(source);
	GENERATE_GETTERS_AND_SETTERS(type);
};

} //render
