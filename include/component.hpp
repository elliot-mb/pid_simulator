#ifndef COMPONENT_H
#define COMPONENT_H

#include "point_mass.hpp"

#include <glm/glm.hpp>

//upper-most physical object class
//interface; does not get instantiated
class Component
{
public:

    const PointMass getFirstPoint();
    const PointMass getSecondPoint(); //overloadable (throw an error on all objects which inherit from point mass)
    const PointMass getMidpoint(); 


    const glm::vec2 getFirstPos();
    const glm::vec2 getSecondPos();

    void setFirstPos(glm::vec2 pos); //overloadable
    void setSecondPos(glm::vec2 pos); //overloadable (throw an error on all objects which inherit from point mass)

    virtual const float getMass();

};

#endif