import "./vertex" for Vertex

class Mesh { 
	verts { _verts }
	openVerts { _openVerts }

	construct new(){
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

	closeVert(i){
		_openVerts.removeAt(i)
	}

	toString {
		var acc = "#x\ty\tz\n"
		for(vert in _verts){
			acc = acc + vert.toString + "\n"
		}

		return acc
	}
}
