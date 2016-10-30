#include<Render/camera.hpp>

using namespace render;

void Camera::recalculateViewMatrix(){
	viewMatrix_ = glm::lookAt(
		position_.glmify(),
		lookingAt_.glmify(),
		glm::vec3(0.0, 0.0, 1.0)
	);
};

Camera& Camera::position(typeof(position_) position){
	position_ = position;
	
	recalculateViewMatrix();

	return *this;
};

Camera& Camera::lookingAt(typeof(lookingAt_) lookingAt){
	lookingAt_ = lookingAt;

	recalculateViewMatrix();

	return *this;
};
