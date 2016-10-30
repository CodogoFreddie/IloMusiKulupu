#include<Render/mesh.hpp>

using namespace render;

Mesh::Mesh(){
	glGenVertexArrays(3, vaos);
	glBindVertexArray(vaos[0]);

	glGenBuffers(3, vbos);
	
	positions_ = std::vector<
		core::math::cartesian::CartTwo<>
	>(
		{
			{ 0.0f,  0.5f,},// Vertex 1 (X, Y)
			{ 0.5f, -0.5f,},// Vertex 2 (X, Y)
			{-0.5f, -0.5f,},// Vertex 3 (X, Y)
		}
	 );
};

void Mesh::loadPositions(){
}

void Mesh::render(){
	auto& engine = Engine::get();
	auto programToken_ = engine.getProgram(program_).programToken();

    GLfloat vertices[] = {
         0.0f,  0.5f,
         0.5f, -0.5f,
        -0.5f, -0.5f
    };

	glBindBuffer(GL_ARRAY_BUFFER, vbos[0]);
	glBufferData(
		GL_ARRAY_BUFFER,
		sizeof(vertices),
		vertices,
		GL_STATIC_DRAW
	);

	glUseProgram(programToken_);

	GLint posAttrib = glGetAttribLocation(programToken_, "position");

	glEnableVertexAttribArray(posAttrib);
	glVertexAttribPointer(
		posAttrib,
		2,
		GL_FLOAT,
		GL_FALSE,
		0,
		0
	);

	glDrawArrays(GL_TRIANGLES, 0, 3);
};

void Mesh::reset(){
	positions_.clear();
	colors_.clear();
	normals_.clear();
	faces_.clear();
};

//std::size_t Mesh::addVertex(
//core::math::cartesian::CartThree<> position,
//core::math::cartesian::CartThree<> color,
//core::math::cartesian::CartThree<> normal
//){
//positions_.push_back(position);
//colors_.push_back(color);
//normals_.push_back(normal);

//assert(positions_.size() == colors_.size() &&
//positions_.size() == normals_.size());

//return positions_.size();
//};

//std::size_t Mesh::addFace(Face f){
//faces_.push_back(f);
//return faces_.size();
//};

