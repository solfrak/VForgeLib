//
// Created by samuel on 25/03/24.
//

#ifndef VFORGEMAIN_OBJECT_H
#define VFORGEMAIN_OBJECT_H
#include <vector>
#include "Texture.h"
#include <Mesh.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
namespace vforge
{
    class Object
    {
    private:
        void LoadModel(std::string const &path);
        void ProcessNode(aiNode *node, const aiScene *scene);
        Mesh ProcessMesh(aiMesh *mesh, const aiScene *scene);
        std::vector<Texture> LoadMaterialTextures(aiMaterial *mat, aiTextureType type, TextureType textureType);
        unsigned int TextureFromFile(const char* path, const std::string &directory, bool gamma = false);
        std::string directory;
    public:
        std::vector<Texture> textures_loaded;
        std::vector<Mesh> meshes;

        Object(std::string const &path, bool gamma = false);
        void Draw(Shader &shader);

    };

}
#endif //VFORGEMAIN_OBJECT_H
