#pragma once

#include <set>
#include <Core/idManager.hpp>

namespace render {

class Scene{
private:
	std::set<core::ID> meshes;

public:
	Scene(){}

	void addMesh(const core::ID id){
		meshes.insert(id);
	}

	void removeMesh(const core::ID id){
		meshes.erase(id);
	}
};

} //render
