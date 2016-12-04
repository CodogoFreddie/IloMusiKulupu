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

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <assimp/Importer.hpp>      // C++ importer interface
#include <assimp/scene.h>           // Output data structure
#include <assimp/postprocess.h>     // Post processing flags

namespace render{
class Mesh;
class Engine;
}

#include "./engine.hpp"

namespace render {

typedef struct Face{
	GLuint first;
	GLuint second;
	GLuint third;
} Face;

typedef core::math::cartesian::CartThree<GLfloat> point;

class Mesh{
private:
	std::vector<
		core::math::cartesian::CartThree<>
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
	GLuint vao;
	GLuint ebo;

	point position_;
	point rotation_;
	point scale_ = { 1.0, 1.0, 1.0, };

	glm::mat4 modelMatrix;
	glm::mat4 mvpMatrix;

	std::string filename_;

	void loadPositions();
	void loadColors();
	void loadFaces();
	void loadNormals();

	void loadLights();

	void calculateMVP();

public:
	Mesh();

	Mesh& loadFromFile(const std::string filename);

	GENERATE_GETTERS_AND_SETTERS(positions);
	GENERATE_GETTERS_AND_SETTERS(colors);
	GENERATE_GETTERS_AND_SETTERS(normals);
	GENERATE_GETTERS_AND_SETTERS(faces);
	GENERATE_GETTERS_AND_SETTERS(program);

	GENERATE_GETTERS_AND_SETTERS(position);
	GENERATE_GETTERS_AND_SETTERS(rotation);
	GENERATE_GETTERS_AND_SETTERS(scale);

	Mesh& reset();

	Mesh& addVertex(
		core::math::cartesian::CartThree<> position,
		core::math::cartesian::CartThree<> color,
		core::math::cartesian::CartThree<> normal
	);

	Mesh& addFace(Face f);

	void render();

};
} //render
