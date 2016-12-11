import "./poisson" for Poisson

var generator = Poisson.new()

var genFib = generator.create()

var running = true
var mesh
while(!genFib.isDone){
	var newMesh = genFib.call()

	if(newMesh){
		mesh = newMesh
	}
}

var acc = "#pragma once\n\n"

acc = acc + "#include \"../../../Render/mesh.hpp\"\n\n"

acc = acc + "namespace world {\n"
acc = acc + "namespace level {\n"
acc = acc + "namespace terrain {\n\n"

acc = acc + "const Mesh mesh;\n\n"

acc = acc + "mesh.positions(std::vector<core::math::cartesian::CartThree<>>({\n"

acc = acc + mesh.toString

acc = acc + "}));\n\n"

acc = acc + "} //namespace terrain\n"
acc = acc + "} //namespace level\n"
acc = acc + "} //namespace world\n"

