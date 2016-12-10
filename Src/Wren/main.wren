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

System.print(mesh.toString)
