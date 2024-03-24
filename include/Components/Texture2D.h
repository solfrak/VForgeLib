//
// Created by samuel on 24/03/24.
//

#ifndef VFORGEMAIN_TEXTURE2D_H
#define VFORGEMAIN_TEXTURE2D_H

#include <Components/IComponent.h>

struct Texture2D : public IComponent
{
    const char* filename;
};
#endif //VFORGEMAIN_TEXTURE2D_H
