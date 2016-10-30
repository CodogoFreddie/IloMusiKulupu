#include<Render/shader.hpp>
#include <iostream>

using namespace render;

Shader::Shader(){
}

void Shader::compile(){

	if(type_ == VertexShader){
		shaderToken_ = glCreateShader(GL_VERTEX_SHADER);
	}
	else if (type_ == FragmentShader){
		shaderToken_ = glCreateShader(GL_FRAGMENT_SHADER);
	}

	glShaderSource(shaderToken_, 1, &source_, NULL);
	glCompileShader(shaderToken_);

	GLint status;
	glGetShaderiv(shaderToken_, GL_COMPILE_STATUS, &status);

	if(status == GL_TRUE){
		char buffer[512];
		glGetShaderInfoLog(shaderToken_, 512, NULL, buffer);

		std::cout << buffer << std::endl;
	}
}
