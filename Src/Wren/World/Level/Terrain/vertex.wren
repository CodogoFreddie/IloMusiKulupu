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
		var zD = _z - v.z

		return ( (xD * xD) + (yD * yD) + (zD * zD)).sqrt
	}

	distance(v, n){
		if(n == 3){
			return distance(v)
		}
		if(n == 2){
			var xD = _x - v.x
			var yD = _y - v.y

			return ( (xD * xD) + (yD * yD) ).sqrt
		}
		if(n == 1){
			var xD = _x - v.x

			return xD.abs
		}
	}

	toString {
		/*return "" + x.toString + "    \t" + y.toString + "    \t" + z.toString*/
		return "{" + x.toString + "," + y.toString + "," + z.toString + "},"
	}

}
