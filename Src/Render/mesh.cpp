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
			{ 1.0f,  1.0f,},// Vertex 2 (X, Y)
			{ 1.0f, -1.0f,},// Vertex 1 (X, Y)
			{-1.0f, -1.0f,},// Vertex 3 (X, Y)
			{ 1.0f,  1.0f,},// Vertex 2 (X, Y)
			{-1.0f,  1.0f,},// Vertex 1 (X, Y)
			{-1.0f, -1.0f,},// Vertex 3 (X, Y)
		}
	 );

	colors_= std::vector<
		core::math::cartesian::CartThree<>
	>(
		{
			{ 1.0f, 0.0f, 0.0f, },
			{ 0.0f, 1.0f, 0.0f, },
			{ 0.0f, 0.0f, 1.0f, },
			{ 1.0f, 0.0f, 0.0f, },
			{ 0.0f, 1.0f, 0.0f, },
			{ 0.0f, 0.0f, 1.0f, },
		}
	 );
};

void Mesh::loadPositions(){

	glBindBuffer(GL_ARRAY_BUFFER, vbos[0]);

	glBufferData(
		GL_ARRAY_BUFFER,
		sizeof(positions_[0].data()) * 3 * positions_.size(),
		positions_.data(),
		GL_STATIC_DRAW
	);

	GLint attributePosition = glGetAttribLocation(programToken_, "position");

	glEnableVertexAttribArray(attributePosition);
	glVertexAttribPointer(
		attributePosition,
		2,
		GL_FLOAT,
		GL_FALSE,
		0,
		0
	);
}

void Mesh::loadColors(){
	glBindBuffer(GL_ARRAY_BUFFER, vbos[1]);
	glBufferData(
		GL_ARRAY_BUFFER,
		sizeof(colors_[0].data()) * 3 * colors_.size(),
		colors_.data(),
		GL_STATIC_DRAW
	);

	GLint attributePosition = glGetAttribLocation(programToken_, "color");

	glEnableVertexAttribArray(attributePosition);
	glVertexAttribPointer(
		attributePosition,
		3,
		GL_FLOAT,
		GL_FALSE,
		0,
		0
	);
}

void Mesh::render(){
	auto& engine = Engine::get();
	programToken_ = engine.getProgram(program_).programToken();

	glUseProgram(programToken_);

	loadPositions();
	loadColors();

	glDrawArrays(GL_TRIANGLES, 0, 6);
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

