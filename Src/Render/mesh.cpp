#include<Render/mesh.hpp>

using namespace render;

Mesh::Mesh()
{
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &ebo);

	glGenBuffers(3, vbos);

	positions_ = std::vector<
		core::math::cartesian::CartThree<>
		>(
				{
				{ 1.0f,  1.0f,  1.0f, },
				{-1.0f,  1.0f,  1.0f, },
				{ 1.0f, -1.0f,  1.0f, },
				{ 1.0f,  1.0f, -1.0f, },
				{-1.0f, -1.0f, -1.0f, },
				{ 1.0f, -1.0f, -1.0f, },
				{-1.0f,  1.0f, -1.0f, },
				{-1.0f, -1.0f,  1.0f, },
				}
		 );

	normals_ = std::vector<
		core::math::cartesian::CartThree<>
		>(
				{
				{ 1.0f,  1.0f,  1.0f, },
				{-1.0f,  1.0f,  1.0f, },
				{ 1.0f, -1.0f,  1.0f, },
				{ 1.0f,  1.0f, -1.0f, },
				{-1.0f, -1.0f, -1.0f, },
				{ 1.0f, -1.0f, -1.0f, },
				{-1.0f,  1.0f, -1.0f, },
				{-1.0f, -1.0f,  1.0f, },
				}
		 );

	colors_= std::vector<
		core::math::cartesian::CartThree<>
		>(
				{
				{ 1.0f,  1.0f,  1.0f, },
				{ 0.0f,  1.0f,  1.0f, },
				{ 1.0f,  0.0f,  1.0f, },
				{ 1.0f,  1.0f,  0.0f, },
				{ 0.0f,  0.0f,  0.0f, },
				{ 1.0f,  0.0f,  0.0f, },
				{ 0.0f,  1.0f,  0.0f, },
				{ 0.0f,  0.0f,  1.0f, },
				}
		 );

	faces_ = std::vector<Face>(
			{ 
			{ 0, 1, 6, },
			{ 0, 3, 6, },
			{ 0, 2, 5, },
			{ 0, 3, 5, },
			{ 0, 1, 7, },
			{ 0, 2, 7, },
			{ 4, 5, 2, },
			{ 4, 7, 2, },
			{ 4, 6, 1, },
			{ 4, 7, 1, },
			{ 4, 6, 3, },
			{ 4, 5, 3, },
			}
			);

};

Mesh& Mesh::loadFromFile(const std::string filename){
	filename_ = filename;

    Assimp::Importer importer;

	const aiScene* pScene = importer.ReadFile(
		filename.c_str(),
		aiProcess_Triangulate
		| aiProcess_GenSmoothNormals
		| aiProcess_FlipUVs
		| aiProcess_JoinIdenticalVertices
	);

	std::cout << "num of mats: " << pScene->mNumMaterials << std::endl;

	const auto materials = pScene->mMaterials;

    if (pScene) {
		positions_.clear();
		colors_.clear();
		normals_.clear();
		faces_.clear();
		
		int vertIndexOffset = 0;

		for(int meshI = 0; meshI < pScene->mNumMeshes; meshI++){
			const auto mesh = pScene->mMeshes[meshI];

			const auto vertN = mesh->mNumVertices;
			const auto materialI = mesh->mMaterialIndex;
			const auto material = materials[materialI];

			aiColor3D color (0.f,0.f,0.f);
			material->Get(AI_MATKEY_COLOR_DIFFUSE,color);

			const auto vertPoss = mesh->mVertices;
			const auto vertNors= mesh->mNormals;
			for(int vertI = 0; vertI < vertN; vertI++){
				const auto pos = vertPoss[vertI];
				positions_.push_back({pos.x, pos.y, pos.z,});

				const auto nor = vertNors[vertI];
				normals_.push_back({nor.x, nor.y, nor.z,});

				colors_.push_back({color.r, color.g, color.b,});
			}

			const auto faces = mesh->mFaces;
			const auto facesN = mesh->mNumFaces;
			for(int faceI = 0; faceI < facesN; faceI++){
				const auto face = faces[faceI];
				const auto points = face.mIndices;
				faces_.push_back({
						points[0] + vertIndexOffset,
						points[1] + vertIndexOffset,
						points[2] + vertIndexOffset,
						});
			}

			std::cout << mesh->HasFaces() << ','
				<< mesh->HasNormals() << ','
				<< mesh->HasPositions() << std::endl;

			vertIndexOffset += vertN;
		}
	}
	else {
		printf("Error parsing '%s': '%s'\n", filename.c_str(), importer.GetErrorString());
	}

	return *this;
}

void Mesh::loadPositions(){

	glBindBuffer(GL_ARRAY_BUFFER, vbos[0]);

	glBufferData(
			GL_ARRAY_BUFFER,
			sizeof(positions_[0].data()) * 3 * positions_.size(),
			positions_.data(),
			GL_STATIC_DRAW
			);

	GLint attributePosition = glGetAttribLocation(programToken_, "position");

	glEnableVertexAttribArray(attributePosition);
	glVertexAttribPointer(
			attributePosition,
			3,
			GL_FLOAT,
			GL_FALSE,
			0,
			0
			);
}

void Mesh::loadNormals(){

	glBindBuffer(GL_ARRAY_BUFFER, vbos[1]);

	glBufferData(
			GL_ARRAY_BUFFER,
			sizeof(normals_[0].data()) * 3 * normals_.size(),
			normals_.data(),
			GL_STATIC_DRAW
			);

	GLint attributeNormal = glGetAttribLocation(programToken_, "normal");

	glEnableVertexAttribArray(attributeNormal);
	glVertexAttribPointer(
			attributeNormal,
			3,
			GL_FLOAT,
			GL_FALSE,
			0,
			0
			);
}

void Mesh::loadColors(){
	glBindBuffer(GL_ARRAY_BUFFER, vbos[2]);
	glBufferData(
			GL_ARRAY_BUFFER,
			sizeof(colors_[0].data()) * 3 * colors_.size(),
			colors_.data(),
			GL_STATIC_DRAW
			);

	GLint attributePosition = glGetAttribLocation(programToken_, "color");

	glEnableVertexAttribArray(attributePosition);
	glVertexAttribPointer(
			attributePosition,
			3,
			GL_FLOAT,
			GL_FALSE,
			0,
			0
			);
}

void Mesh::loadFaces(){
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(
			GL_ELEMENT_ARRAY_BUFFER,
			sizeof(faces_[0]) * faces_.size(),
			faces_.data(),
			GL_STATIC_DRAW
			);
};

void Mesh::loadLights(){
	const auto currentSceneID = Engine::get().currentScene();
	auto currentScene = Engine::get().getScene(currentSceneID);

	GLint sunPosToken = glGetUniformLocation(programToken_, "sunPos");
	const auto sunPos = currentScene.sunPos();
	glUniform3f(sunPosToken, sunPos.x(), sunPos.y(), sunPos.z());

	GLint sunColToken = glGetUniformLocation(programToken_, "sunCol");
	const auto sunCol = currentScene.sunCol();
	glUniform3f(sunColToken, sunCol.x(), sunCol.y(), sunCol.z());

	GLint moonPosToken = glGetUniformLocation(programToken_, "moonPos");
	const auto moonPos = currentScene.moonPos();
	glUniform3f(moonPosToken, moonPos.x(), moonPos.y(), moonPos.z());

	GLint moonColToken = glGetUniformLocation(programToken_, "moonCol");
	const auto moonCol = currentScene.moonCol();
	glUniform3f(moonColToken, moonCol.x(), moonCol.y(), moonCol.z());

	GLint ambientColToken = glGetUniformLocation(programToken_, "ambientCol");
	const auto ambientCol = currentScene.ambientCol();
	glUniform3f(ambientColToken, ambientCol.x(), ambientCol.y(), ambientCol.z());
};

void Mesh::calculateMVP(){
	auto viewMatrix = Engine::get().getCamera( Engine::get().currentCamera() ).viewMatrix();
	auto projectionMatrix = Engine::get().projectionMatrix();

	modelMatrix = glm::rotate(glm::mat4(), glm::radians(rotation_.x()), glm::vec3(1,0,0));
	modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation_.y()), glm::vec3(0,1,0));
	modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation_.z()), glm::vec3(0,0,1));

	modelMatrix = glm::translate(
		modelMatrix,
		glm::vec3(
			position_.x(),
			position_.y(),
			position_.z()
		)
	);

	GLint modelMatToken = glGetUniformLocation(programToken_, "modelMat");

	glUniformMatrix4fv(
		modelMatToken,
		1,
		GL_FALSE,
		glm::value_ptr(modelMatrix)
	);

	mvpMatrix = projectionMatrix * viewMatrix * modelMatrix;
	GLint mvpToken = glGetUniformLocation(programToken_, "mvp");

	glUniformMatrix4fv(
		mvpToken,
		1,
		GL_FALSE,
		glm::value_ptr(mvpMatrix)
	);
}

void Mesh::render(){
	programToken_ = Engine::get().getProgram(program_).programToken();

	glUseProgram(programToken_);

	loadPositions();
	loadColors();
	loadNormals();
	loadFaces();

	loadLights();

	calculateMVP();

	glDrawElements(
			GL_TRIANGLES,
			faces_.size() * 3,
			GL_UNSIGNED_INT,
			0
			);
};

void Mesh::reset(){
	positions_.clear();
	colors_.clear();
	normals_.clear();
	faces_.clear();

	position_ = { 0, 0, 0, };
	rotation_ = { 0, 0, 0, };
	scale_ = { 0, 0, 0, };

	modelMatrix;
};
