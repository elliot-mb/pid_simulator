#ifndef COMPONENT_H
#define COMPONENT_H

#include "point_mass.hpp"

#include <glm/glm.hpp>

//upper-most physical object class
//interface; does not get instantiated
class Component
{
public:


    virtual const glm::vec2 getPos() = 0;
    virtual void            setPos(glm::vec4 pos) = 0; 

    virtual const float getMass() = 0;
};

#endif