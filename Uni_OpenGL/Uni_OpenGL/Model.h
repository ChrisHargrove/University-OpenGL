#pragma once

#include "Mesh.h"
#include "ASSIMP\Importer.hpp"
#include "ASSIMP\scene.h"
#include "ASSIMP\postprocess.h"
#include <GLM\glm.hpp>

class Model
{
public:
    Model(std::string FileName, std::string shader);
    ~Model();

    void Render(std::string shader = "");

    std::vector<glm::vec3> GetVertices();
    std::vector<unsigned int> GetIndices();

private:
    std::string _Shader;
    std::string _Directory;
    std::vector<Mesh> _Meshes;
    std::vector<MeshTexture> _Textures;
    
    void LoadModel(std::string FileName);
    void ProcessNode(aiNode* node, const aiScene* scene);
    Mesh ProcessMesh(aiMesh* mesh, const aiScene* scene);

    std::vector<MeshTexture> LoadMaterialTextures(aiMaterial* material, aiTextureType type, std::string typeName);
    unsigned int TextureFromFile(std::string FileName);
};

