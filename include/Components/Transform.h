//
// Created by samuel on 24/03/24.
//

#ifndef VFORGEMAIN_TRANSFORM_H
#define VFORGEMAIN_TRANSFORM_H

#include <glm/glm.hpp>
#include <Components/IComponent.h>

struct Transform : public IComponent
{
public:
    glm::vec3 position;
    glm::vec3 rotation;
};

#endif //VFORGEMAIN_TRANSFORM_H
