import "./mesh" for Mesh
import "./vertex" for Vertex

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
		_bounds = 10
		_tries = 10
		_distance = 2

		_mesh = Mesh.new()
	}

	create(){
		return Fiber.new {
			while(_mesh.openVerts.count != 0){
				_mesh.placeVert(_tries, _distance)

				Fiber.yield(_mesh)
			}
		}
	}

}
