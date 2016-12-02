#include "./Render/engine.hpp"

int main() { 
	render::Engine& re = render::Engine::get();

	auto cameraID = re.createCamera();
	auto sceneID = re.createScene();
	auto meshID = re.createMesh();
	auto basicProgram = re.createProgram();

	re.getCamera(cameraID)
		.position({-4, -4, 2})
		.lookingAt({0,0,4})
		.scene(sceneID);

	re.currentCamera(cameraID);

	re.getProgram(basicProgram)
		.vertexFileName("Src/GLSL/vertexShader.glsl")
		.fragmentFileName("Src/GLSL/fragmentShader.glsl")
		.compile();

	re.getMesh(meshID)
		.loadFromFile("Blend/tree_01_0.obj")
		.program(basicProgram);

	re.getScene(sceneID)
		.addMesh(meshID);

	using namespace std::chrono;
	long now = duration_cast<milliseconds>(
		steady_clock::now().time_since_epoch()
	).count(); 
	long previousTime = now - 100;

	while(re.render(now - previousTime)){
		now = duration_cast<milliseconds>(
			steady_clock::now().time_since_epoch()
		).count(); 

		std::cout << std::endl;
	};

	return 0;
}
