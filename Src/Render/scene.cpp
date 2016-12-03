#include<Render/scene.hpp>

using namespace render;


Scene& Scene::sunPos(const core::math::cartesian::CartThree<>& x){
	sunPos_ = x.normalize();
	return (*this);
};

Scene& Scene::moonPos(const core::math::cartesian::CartThree<>& x){
	moonPos_ = x.normalize();
	return (*this);
};
