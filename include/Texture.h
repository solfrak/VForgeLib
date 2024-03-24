//
// Created by samuel on 22/03/24.
//

#ifndef VFORGEMAIN_TEXTURE_H
#define VFORGEMAIN_TEXTURE_H

namespace vforge
{
    class Texture
    {
    private:
        unsigned int texture;
        int width, height, nrChannels;
    public:
        Texture(const char *path);
        unsigned int Get();
    };
}
#endif //VFORGEMAIN_TEXTURE_H
