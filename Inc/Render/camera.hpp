#pragma once

#include <Core/Math/Cartesian/CartThree.hpp>
#include <Core/idManager.hpp>
#include <Macros/generateGetAndSet.hpp>

namespace render {

class Camera{
private:
	core::math::cartesian::CartThree<> position_;
	core::math::cartesian::CartThree<> lookingAt_;
	core::ID scene_;

public:
	Camera(){}

	GENERATE_GETTERS_AND_SETTERS(position)
	GENERATE_GETTERS_AND_SETTERS(lookingAt)
	GENERATE_GETTERS_AND_SETTERS(scene)

};


} //render
