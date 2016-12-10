import "./mesh" for Mesh

class Vertex {
	x { _x }
	y { _y }
	z { _z }

	live { _live }

	construct new() {
		_x = 0
		_y = 0
		_z = 0

		_live = true
	}
	
	construct new(x, y, z) {
		_x = x
		_y = y
		_z = z

		_live = true
	}

	distance(v){
		var xD = _x - v.x
		var yD = _y - v.y
		/*var zD = _z - v.z*/
		var zD = 0

		return ( (xD * xD) + (yD * yD) + (zD * zD)).sqrt
	}

	toString {
		return "" + x.toString + "\t" + y.toString + "\t" + z.toString
	}
			
}
