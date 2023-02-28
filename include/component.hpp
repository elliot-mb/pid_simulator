#ifndef COMPONENT_H
#define COMPONENT_H

#include "point_mass.hpp"

#include <glm/glm.hpp>

//upper-most physical object class
//interface; does not get instantiated
class Component
{
public:

    virtual const PointMass getFirstPoint() = 0;
    virtual const PointMass getSecondPoint() = 0; //overloadable (throw an error on all objects which inherit from point mass)
    virtual const PointMass getMidpoint() = 0; 

    virtual void setFirstPos(glm::vec2 pos) = 0; //overloadable
    virtual void setSecondPos(glm::vec2 pos) = 0; //overloadable (throw an error on all objects which inherit from point mass)

};

#endif