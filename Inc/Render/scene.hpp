#pragma once

#include <set>
#include <Core/idManager.hpp>
#include <Core/Math/Cartesian/CartThree.hpp>
#include <Macros/generateGetAndSet.hpp>

namespace render {

class Scene{
private:
	std::set<core::ID> meshes_;

	core::math::cartesian::CartThree<> sunPos_ = { 0.0, 0.0, 1.0, };
	core::math::cartesian::CartThree<> sunCol_;
	core::math::cartesian::CartThree<> moonPos_;
	core::math::cartesian::CartThree<> moonCol_;
	core::math::cartesian::CartThree<> ambientCol_;

public:
	Scene(){}

	GENERATE_GETTERS_AND_SETTERS(sunPos);
	GENERATE_GETTERS_AND_SETTERS(sunCol);
	GENERATE_GETTERS_AND_SETTERS(moonPos);
	GENERATE_GETTERS_AND_SETTERS(moonCol);
	GENERATE_GETTERS_AND_SETTERS(ambientCol);

	GENERATE_GETTER(meshes);

	void addMesh(const core::ID id){
		meshes_.insert(id);
	}

	void removeMesh(const core::ID id){
		meshes_.erase(id);
	}
};

} //render
