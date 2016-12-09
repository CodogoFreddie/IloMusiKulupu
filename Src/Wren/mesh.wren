import "./vertex" for Vertex

class Mesh { 
	verts { _verts }

	construct new(){
		_verts = [ 
			Vertex.new()
		]
	}
}
