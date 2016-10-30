#pragma once

#include <string>

#include <Macros/generateGetAndSet.hpp>

#define GLEW_STATIC
#include <GL/glew.h>

#include <SDL.h>
#include <SDL_opengl.h>

#include "./shader.hpp"

namespace render {

class Program {
private:
	std::string vertexFileName_;
	GLuint vertexToken_;

	std::string fragmentFileName_;
	GLuint fragmentToken_;

	GLuint programToken_;
public: 
	Program();

	void compile();

	GENERATE_GETTERS_AND_SETTERS(programToken);
	GENERATE_GETTERS_AND_SETTERS(vertexFileName);
	GENERATE_GETTERS_AND_SETTERS(fragmentFileName);

};

} //render
