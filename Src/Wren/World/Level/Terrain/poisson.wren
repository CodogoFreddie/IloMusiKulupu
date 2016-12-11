import "random" for Random

import "./mesh" for Mesh
import "./vertex" for Vertex
import "./grid" for Grid

class Poisson {
	bounds=(x) {
		_bounds = x
	}
	tries=(n) {
		_tries = n
	}
	distance=(d){
		_distance = d
	}

	construct new(){
		_bounds = 50
		_tries = 20
		_distance = 2

		_rando = Random.new()
		_mesh = Mesh.new()
		_grid = Grid.new(_bounds, _distance)

		_grid[0, 0] = 0
	}

	static run(){
		var generator = Poisson.new()

		var genFib = generator.create()
		var mesh
		while(!genFib.isDone){
			var newMesh = genFib.call()

			if(newMesh){
				mesh = newMesh
			}
		}

		return mesh
	}

	static runAndPrint(){
		var mesh = Poisson.run()	
	}

	placeVert(){
		var activeIndex = _rando.int(0, _mesh.openVerts.count)
		var activeVert = _mesh.openVerts[activeIndex]
		var testVert = Vertex.new()

		var placementIsSuccess = false
		for(i in 0..._tries){
			var phi = _rando.float(0, 2 * Num.pi)
				var costheta = _rando.float(-1,1)
				var u = 1 + _rando.float(0,1).sqrt
				var theta = costheta.acos
				var r = _distance * u

				testVert = Vertex.new(
						activeVert.x + ( r * theta.sin * phi.cos ),
						activeVert.y + ( r * theta.sin * phi.sin ),
						activeVert.z + ( r * theta.cos )
						)

				if(vertexIsValid(testVert)){
					placementIsSuccess = true
						break
				}
		}

		if(placementIsSuccess){
			_mesh.add(testVert)
				_grid[testVert.x, testVert.y] = _mesh.verts.count - 1

		} else {
			_mesh.closeVert(activeIndex)
		}

	}

	vertexIsValid(vert){
		if( vert.x.abs > _bounds ||
			vert.y.abs > _bounds ||
			vert.z.abs > _bounds ){
			return false
		}

		var tooClose = false
		var searchIndexs = _grid.getNeighbourhood(vert.x, vert.y)

		for(searchIndex in searchIndexs){
			var otherVert = _mesh.verts[searchIndex]
				if(vert.distance(otherVert, 2) < _distance){
					tooClose = true
						break
				}
		}

		return !tooClose
	}

	create(){
		return Fiber.new {
			while(_mesh.openVerts.count != 0){
				var startingVertsN = _mesh.verts.count

				while(startingVertsN == _mesh.verts.count &&
					_mesh.openVerts.count > 0){
					placeVert()
				}
				Fiber.yield(_mesh)
			}
		}
	}

}
