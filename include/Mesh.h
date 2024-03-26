//
// Created by samuel on 25/03/24.
//

#ifndef VFORGEMAIN_MESH_H
#define VFORGEMAIN_MESH_H
#include <glm/glm.hpp>
#include <vector>
#include <Texture.h>
#include <Shader.h>


namespace vforge
{
#define MAX_BONE_INFLUENCE 4
    struct Vertex {
        // position
        glm::vec3 Position;
        // normal
        glm::vec3 Normal;
        // texCoords
        glm::vec2 TexCoords;
        // tangent
        glm::vec3 Tangent;
        // bitangent
        glm::vec3 Bitangent;
        //bone indexes which will influence this vertex
        int m_BoneIDs[MAX_BONE_INFLUENCE];
        //weights from each bone
        float m_Weights[MAX_BONE_INFLUENCE];
    };


    class Mesh
    {
    public:
        std::vector<Vertex> vertices;
        std::vector<Texture> textures;
        std::vector<unsigned int> indices;
        unsigned int VAO;

        Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);
        void Draw(Shader &shader);
    private:
        unsigned int VBO, EBO;

        void SetupMesh();
    };

}
#endif //VFORGEMAIN_MESH_H
