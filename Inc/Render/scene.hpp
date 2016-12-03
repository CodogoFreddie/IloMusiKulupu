#pragma once

#include <set>
#include <Core/idManager.hpp>
#include <Core/Math/Cartesian/CartThree.hpp>
#include <Macros/generateGetAndSet.hpp>

namespace render {

class Scene{
private:
	std::set<core::ID> meshes_;

	core::math::cartesian::CartThree<> sunPos_ = { 0.0, 0.5, 0.70710678118654, };
	core::math::cartesian::CartThree<> sunCol_ = { 1.0, 1.0, 1.0, };
	core::math::cartesian::CartThree<> moonPos_ = { 0.5, 0.0, 0.70710678118654, };
	core::math::cartesian::CartThree<> moonCol_ = { 0.3, 0.4, 0.5, };
	core::math::cartesian::CartThree<> ambientCol_ = { 0.1, 0.1, 0.1, };

public:
	Scene(){}

	GENERATE_GETTER(sunPos);
	GENERATE_GETTERS_AND_SETTERS(sunCol);
	GENERATE_GETTER(moonPos);
	GENERATE_GETTERS_AND_SETTERS(moonCol);
	GENERATE_GETTERS_AND_SETTERS(ambientCol);

	Scene& sunPos(const core::math::cartesian::CartThree<>& x);
	Scene& moonPos(const core::math::cartesian::CartThree<>& x);

	GENERATE_GETTER(meshes);

	void addMesh(const core::ID id){
		meshes_.insert(id);
	}

	void removeMesh(const core::ID id){
		meshes_.erase(id);
	}
};

} //render
