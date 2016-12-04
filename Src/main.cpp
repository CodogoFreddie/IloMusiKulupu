#include "./Render/engine.hpp"

int main() { 
	render::Engine& re = render::Engine::get();

	auto cameraID = re.createCamera();
	auto sceneID = re.createScene();
	auto meshID = re.createMesh();
	auto basicProgram = re.createProgram();

	re.getCamera(cameraID)
		.position({ 5.0, 5.0, 2.0, })
		.lookingAt({ 0.0, 0.0, 4.0, })
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
		.sunPos({ 1.0, 4.0, 9.0, })
		.sunCol({ 0.5, 0.5, 0.5, })

		.moonPos({ 9.0, 4.0, 1.0, })
		.moonCol({ 0.1, 0.2, 0.3, })

		.ambientCol({ 0.0, 0.0, 0.0, })

		.addMesh(meshID);

	using namespace std::chrono;
	long now = duration_cast<milliseconds>(
			steady_clock::now().time_since_epoch()
			).count(); 
	long previousTime = now - 100;

	float i = 0;

	while(re.render(now - previousTime)){
		now = duration_cast<milliseconds>(
			steady_clock::now().time_since_epoch()
		).count(); 

		re.getMesh(meshID)
			.rotation( {
				0.0,
				0.0,
				i,
			} );

		i += 1.0;
	};

	return 0;
}
