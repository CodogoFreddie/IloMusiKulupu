#include "./Render/engine.hpp"

int main() { 
	render::Engine& re = render::Engine::get();

	auto cameraID = re.createCamera();
	auto sceneID = re.createScene();
	auto meshID = re.createMesh();
	auto basicProgram = re.createProgram();

	re.getCamera(cameraID)
		.position({-7, -5, 5})
		.lookingAt({0,0,0})
		.scene(sceneID);

	re.currentCamera(cameraID);

	re.getProgram(basicProgram)
		.vertexFileName("Src/GLSL/vertexShader.glsl")
		.fragmentFileName("Src/GLSL/fragmentShader.glsl")
		.compile();

	re.getMesh(meshID)
		.program(basicProgram);

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
