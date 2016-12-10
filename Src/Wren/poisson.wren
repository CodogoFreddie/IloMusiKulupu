import "random" for Random

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
		_bounds = 40
		_tries = 30
		_distance = 2

		_rando = Random.new()
		_mesh = Mesh.new()
	}

	placeVert(){
		var activeIndex = _rando.int(0, _mesh.openVerts.count)
		var activeVert = _mesh.openVerts[activeIndex]
		var testVert = Vertex.new()
		
		var placementIsSuccess = false
		for(i in 0..._tries){
			testVert = Vertex.new(
				_rando.float(activeVert.x - _distance, activeVert.x + _distance),
				_rando.float(activeVert.y - _distance, activeVert.y + _distance),
				_rando.float(activeVert.z - _distance, activeVert.z + _distance)
			)

			if(vertexIsValid(testVert)){
				placementIsSuccess = true
				break
			}
		}

		if(placementIsSuccess){
			_mesh.add(testVert)
		} else {
			_mesh.closeVert(activeIndex)
		}

	}

	vertexIsValid(vert){
		if(vert.x.abs > _bounds ||
			vert.y.abs > _bounds ||
			vert.z.abs > _bounds){
			return false
		}

		var tooClose = false

		for(otherVert in  _mesh.verts){
			if(vert.distance(otherVert) < _distance){
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
