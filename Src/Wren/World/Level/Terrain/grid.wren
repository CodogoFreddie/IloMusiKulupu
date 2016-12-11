class Grid {
	bounds { _bounds }
	distance { _distance }

	twoTooOne(x, y){
		var x_ = x.floor + bounds
		var y_ = y.floor + bounds 

		return (y_ * bounds * 2) + ( x_ + y_ )
	}

	[x, y] {
		return _internal[this.twoTooOne(x, y)]
	}

	[x, y]=(val) {
		_internal[this.twoTooOne(x, y)] = val
	}

	construct new(bounds, distance){
		_bounds = bounds
		_distance = distance.ceil
		_internal = {}
	}

	toString {
		var acc = ""
		for(x in (-bounds)..(bounds)){
			for(y in (-bounds)..(bounds)){
				acc = acc + this[x, y].toString + "\t"
			}
			acc = acc + "\n"
		}
	}

	getNeighbourhood(x, y){
		var retVals = []
		var searchDistance = _distance * 2

		var minX = (-_bounds < x - searchDistance) ?
			x - searchDistance :
			-_bounds
		var minY = (-_bounds < y - searchDistance) ?
			y - searchDistance :
			-_bounds
		var maxX = (_bounds > x + searchDistance) ?
			x + searchDistance :
			_bounds
		var maxY = (_bounds > y + searchDistance) ?
			y + searchDistance :
			_bounds

		for(x_ in minX..maxX){
			for(y_ in minY..maxY){
				if(this[x_, y_]){
					retVals.insert(-1, this[x_, y_])
				}
			}
		}

		return retVals
	}
}
