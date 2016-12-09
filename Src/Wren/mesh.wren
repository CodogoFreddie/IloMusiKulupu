import "./vertex" for Vertex
import "random" for Random

class Mesh { 
	verts { _verts }
	openVerts { _openVerts }

	construct new(){
		_rando = Random.new()
		_verts = [ 
			Vertex.new()
		]

		_openVerts = [
			Vertex.new()
		]
	}

	add(vert){
		_verts.insert(-1, vert)
		_openVerts.insert(-1, vert)
	}

	placeVert(tries, distance){
		var activeVert = openVerts[0]
		
		var placementIsSuccess = false
		for(i in 0...tries){
			var testVert = Vertex.new(
				_rando.float(activeVert.x - distance, activeVert.x + distance),
				_rando.float(activeVert.y - distance, activeVert.y + distance),
				_rando.float(activeVert.z - distance, activeVert.z + distance)
			)

			if(vertexIsValid(testVert, distance)){
				placementIsSuccess = true
				break
			}
		}

		if(placementIsSuccess){
			System.print("what?")
		} else {
			_openVerts.removeAt(0)
		}

	}

	vertexIsValid(vert, distance){
		for(existingVert in _verts){

		}
	}

	toString {
		return "anus"
	}
}
