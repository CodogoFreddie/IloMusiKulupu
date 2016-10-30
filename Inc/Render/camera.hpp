#pragma once

#include <Core/Math/Cartesian/CartThree.hpp>
#include <Core/idManager.hpp>
#include <Macros/generateGetAndSet.hpp>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace render {

class Camera{
private:
	core::math::cartesian::CartThree<> position_;
	core::math::cartesian::CartThree<> lookingAt_;
	core::ID scene_;

	glm::mat4 viewMatrix_;
	
	void recalculateViewMatrix();

public:
	Camera(){}

	GENERATE_GETTER(position)
	Camera& position(typeof(position_) position);

	GENERATE_GETTER(lookingAt)
	Camera& lookingAt(typeof(lookingAt_) lookingAt);

	GENERATE_GETTERS_AND_SETTERS(scene)

	GENERATE_GETTER(viewMatrix);
};

} //render
