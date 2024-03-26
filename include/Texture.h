//
// Created by samuel on 22/03/24.
//

#ifndef VFORGEMAIN_TEXTURE_H
#define VFORGEMAIN_TEXTURE_H
#include <string>

namespace vforge
{
    enum TextureType
    {
        DIFFUSE,
        SPECULAR,
        NORMAL,
        HEIGHT
    };
//    class Texture
//    {
//    private:
//        unsigned int texture;
//        int width, height, nrChannels;
//        TextureType type;
//    public:
//        Texture(const char *path);
//        unsigned int Get();
//        TextureType GetType() const
//        {
//            return type;
//        }
//    };
    struct Texture {
        unsigned int id;
        TextureType type;
        std::string path;
    };
}
#endif //VFORGEMAIN_TEXTURE_H
