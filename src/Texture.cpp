//
// Created by samuel on 22/03/24.
//
#define STB_IMAGE_IMPLEMENTATION
#include "Texture.h"
#include "glad/glad.h"
#include <stb/stb_image.h>
#include <iostream>
namespace vforge
{
    Texture::Texture(const char *path) {
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture); // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
        // set the texture wrapping parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        // set texture filtering parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


        stbi_set_flip_vertically_on_load(true);
        unsigned char *data = stbi_load(path, &width, &height, &nrChannels, 0);

        switch (nrChannels) {
            case 3:
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
                glGenerateMipmap(GL_TEXTURE_2D);
                break;
            case 4:
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
                glGenerateMipmap(GL_TEXTURE_2D);
                break;
            default:
                std::cout << "Failed to load texture " << path << std::endl;
                break;
        }

        stbi_image_free(data);
    }

    unsigned int Texture::Get() {
        return texture;
    }



}


