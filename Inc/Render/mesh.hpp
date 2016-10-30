#pragma once

#include <vector>
#include <cassert>
#include <Core/Math/Cartesian/CartTwo.hpp>
#include <Core/Math/Cartesian/CartThree.hpp>
#include <Macros/generateGetAndSet.hpp>
#include <Core/idManager.hpp>

#define GLEW_STATIC
#include <GL/glew.h>

#include <SDL.h>
#include <SDL_opengl.h>

namespace render{
class Mesh;
}

#include "./engine.hpp"

namespace render {

typedef struct Face{
	std::size_t first;
	std::size_t second;
	std::size_t third;
} Face;

class Mesh{
private:
	std::vector<
		core::math::cartesian::CartTwo<>
	> positions_;

	std::vector<
		core::math::cartesian::CartThree<>
	> colors_;

	std::vector<
		core::math::cartesian::CartThree<>
	> normals_;

	std::vector<
		Face
	> faces_;

	core::ID program_;
	GLuint programToken_;

	GLuint vbos[3];
	GLuint vaos[3];

	void loadPositions();
	void loadColors();

public:
	Mesh();

	GENERATE_GETTERS_AND_SETTERS(positions);
	GENERATE_GETTERS_AND_SETTERS(colors);
	GENERATE_GETTERS_AND_SETTERS(normals);
	GENERATE_GETTERS_AND_SETTERS(faces);
	GENERATE_GETTERS_AND_SETTERS(program);

	void reset();

	//std::size_t addVertex(
		//core::math::cartesian::CartThree<> position,
		//core::math::cartesian::CartThree<> color,
		//core::math::cartesian::CartThree<> normal
	//);

	//std::size_t addFace(Face f);

	void render();

};
} //render
