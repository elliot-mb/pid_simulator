#ifndef POINT_H
#define POINT_H

#include <glm/glm.hpp>
#include "component.hpp"

using namespace std;

class PointMass: public Component //component is abstract
{
public:
    //throws exception if mass is negative
    PointMass(glm::vec2 pos, float mass=1.0f);

    //all implemented
    virtual const PointMass getFirstPoint();
    virtual const PointMass getSecondPoint();
    virtual const PointMass getMidpoint(); 
    virtual const glm::vec2 getFirstPos();
    virtual const glm::vec2 getSecondPos();

    virtual const float getMass();

    virtual void setFirstPos(glm::vec2 pos);
    virtual void setSecondPos(glm::vec2 pos);

private:

    glm::vec2 m_pos;
    const float m_mass;
};

#endif