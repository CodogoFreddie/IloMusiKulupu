#pragma once

#include <map>
#include <chrono>

#define GLEW_STATIC
#include <GL/glew.h>

#include <SDL.h>
#include <SDL_opengl.h>

#include <Core/idManager.hpp>

#include "./mesh.hpp"
#include "./camera.hpp"
#include "./scene.hpp"
#include "./shader.hpp"
#include "./program.hpp"

namespace render {

class Engine {
private:
	std::map<core::ID, Mesh> meshs_;
	core::IDManager meshIDM;

	std::map<core::ID, Camera> cameras_;
	core::IDManager cameraIDM;

	std::map<core::ID, Program> programs_;
	core::IDManager programIDM;

	std::map<core::ID, Scene> scenes_;
	core::IDManager sceneIDM;

	core::ID currentCamera_;

	const int width;
	const int height;

	glm::mat4 projectionMatrix_;

	SDL_Window* window;
	SDL_GLContext context;
	SDL_Event windowEvent;

	Engine(int width_ = 1920 / 2, int height_ = 1080 / 2);
	~Engine();

public:

	static Engine& get(){
		static Engine instance;
		return instance;
	}

	const core::ID createMesh();
	Mesh& getMesh(const core::ID id);
	void eraseMesh(const core::ID id);

	const core::ID createScene();
	Scene& getScene(const core::ID id);
	void eraseScene(const core::ID id);

	const core::ID createCamera();
	Camera& getCamera(const core::ID id);
	void eraseCamera(const core::ID id);

	const core::ID createProgram();
	Program& getProgram(const core::ID id);
	void eraseProgram(const core::ID id);

	GENERATE_GETTERS_AND_SETTERS(currentCamera);

	Engine& setFieldOfView(const unsigned int);
	GENERATE_GETTER(projectionMatrix);

	bool render(long deltaTime);

};

} //render
