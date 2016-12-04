#include<Render/engine.hpp>

using namespace render;

Engine::Engine(int width_, int height_):
		width(width_),
		height(height_),
		projectionMatrix_(
			glm::perspective(glm::radians(90.0f),
			(float)width_ / (float)height_,
			0.01f,
			1000.0f)
		)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Init(SDL_INIT_VIDEO);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 8);

	window = SDL_CreateWindow(
		"OpenGL",
		0,
		0,
		width,
		height,
		SDL_WINDOW_OPENGL
	);


	context = SDL_GL_CreateContext(window);
	SDL_GL_MakeCurrent(window, context);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);  
	glEnable(GL_MULTISAMPLE);
	
	glewExperimental = GL_TRUE;

	glewInit();
};

Engine::~Engine(){
	SDL_GL_DeleteContext(context);
	SDL_Quit();
};

bool Engine::render(long deltaTime){
	if (SDL_PollEvent(&windowEvent)){
		if (windowEvent.type == SDL_QUIT){
			return false;
		}
	}

	// Clear the screen to black
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	for(auto meshID : scenes_[currentScene()].meshes()){
		meshs_[meshID].render();
	}

	SDL_GL_SwapWindow(window);

	return true;
};

const core::ID Engine::createMesh(){
	core::ID id = meshIDM.vend();
	Mesh mesh;

	meshs_[id] = mesh;

	return id;
}

Mesh& Engine::getMesh(const core::ID id){
	return meshs_[id];
}

void Engine::eraseMesh(const core::ID id){
	meshs_.erase(id);
}

const core::ID Engine::createScene(){
	core::ID id = sceneIDM.vend();
	Scene scene;

	scenes_[id] = scene;

	return id;
}

Scene& Engine::getScene(const core::ID id){
	return scenes_[id];
}

void Engine::eraseScene(const core::ID id){
	scenes_.erase(id);
}

const core::ID Engine::createCamera(){
	core::ID id = cameraIDM.vend();
	Camera camera;

	cameras_[id] = camera;

	return id;
}

Camera& Engine::getCamera(const core::ID id){
	return cameras_[id];
}

void Engine::eraseCamera(const core::ID id){
	cameras_.erase(id);
}

const core::ID Engine::createProgram(){
	core::ID id = programIDM.vend();
	Program program;

	programs_[id] = program;

	return id;
}

Program& Engine::getProgram(const core::ID id){
	return programs_[id];
}

void Engine::eraseProgram(const core::ID id){
	programs_.erase(id);
}
