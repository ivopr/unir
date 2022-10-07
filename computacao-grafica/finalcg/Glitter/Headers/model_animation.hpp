#pragma once
#ifndef MODEL_H
#define MODEL_H

#include <glad/glad.h> 
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
// Desabilita algumas warnings que estão acontecendo na biblioteca stb_image
// após sua compilação, as habilita para o resto do código
#include <stb_image.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "mesh.hpp"
#include "shader.hpp"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>
#include "assimp-glm-helpers.hpp"
#include "animdata.hpp"

class Model {
public:
	std::vector<Texture> textures_loaded;
	std::vector<Mesh> meshes;
	std::string directory;
	bool gammaCorrection;

	Model(std::string const& path, bool gamma = false);
	void Draw(Shader& shader);
	std::map<std::string, BoneInfo> GetOffsetMatMap() const;
	int GetBoneCount() const;

private:
	std::map<std::string, BoneInfo> m_OffsetMatMap;
	int m_BoneCount = 0;

	void loadModel(std::string const& path);
	void processNode(aiNode* node, const aiScene* scene);
	void SetVertexBoneDataToDefault(Vertex& vertex);
	Mesh processMesh(aiMesh* mesh, const aiScene* scene);
	void SetVertexBoneData(Vertex& vertex, int boneID, float weight);
	void ExtractBoneWeightForVertices(std::vector<Vertex>& vertices, aiMesh* mesh);
	unsigned int TextureFromFile(const char* path, const std::string& directory);
	std::vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName);
};

#endif