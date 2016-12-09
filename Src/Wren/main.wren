import "./poisson" for Poisson

var generator = Poisson.new()

var genFib = generator.create()

while(!genFib.isDone){
	var mesh = genFib.call()

	System.print(mesh.toString)
}
