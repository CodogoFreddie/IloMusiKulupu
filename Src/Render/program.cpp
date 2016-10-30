#include<Render/program.hpp>

#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>

using namespace render;

Program::Program(){

};

void Program::compile(){
	programToken_ = glCreateProgram();

	GLint status;

	std::ifstream vertFileStream(vertexFileName_);
	std::string vertexSourceStdString(
		(std::istreambuf_iterator<char>(vertFileStream)),
		std::istreambuf_iterator<char>()
	);

	auto vertexSource = vertexSourceStdString.c_str();

	vertexToken_ = glCreateShader(GL_VERTEX_SHADER);

	glShaderSource(vertexToken_, 1, &vertexSource, NULL);
	glCompileShader(vertexToken_);
	glGetShaderiv(vertexToken_, GL_COMPILE_STATUS, &status);

	if(status != GL_TRUE){
		char buffer[512];
		glGetShaderInfoLog(vertexToken_, 512, NULL, buffer);
	
		std::cout << "===ERROR===" << std::endl
			<< vertexFileName_ << std::endl
			<< vertexSource << std::endl;

	}

	std::ifstream fragFileStream(fragmentFileName_);
	std::string fragmentSourceStdString(
		(std::istreambuf_iterator<char>(fragFileStream)),
		std::istreambuf_iterator<char>()
	);

	auto fragmentSource = fragmentSourceStdString.c_str();

	fragmentToken_ = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(fragmentToken_, 1, &fragmentSource, NULL);
	glCompileShader(fragmentToken_);
	glGetShaderiv(fragmentToken_, GL_COMPILE_STATUS, &status);

	if(status != GL_TRUE){
		char buffer[512];
		glGetShaderInfoLog(fragmentToken_, 512, NULL, buffer);
	
		std::cout << "===ERROR===" << std::endl
			<< fragmentFileName_ << std::endl
			<< fragmentSource << std::endl;
	}

	glAttachShader(programToken_, fragmentToken_);
	glAttachShader(programToken_, vertexToken_);

	glBindFragDataLocation(programToken_, 0, "outColor");

	glLinkProgram(programToken_);

	glGetProgramiv(programToken_, GL_LINK_STATUS, &status);

	if(status != GL_TRUE){
		char buffer[512];
		glGetProgramInfoLog(programToken_, 512, NULL, buffer);
	
		std::cerr << "===ERROR===" << std::endl
			<< vertexFileName_ << std::endl
			<< vertexSource << std::endl

			<< fragmentFileName_ << std::endl
			<< fragmentSource << std::endl

			<< buffer << std::endl;
	}

};
