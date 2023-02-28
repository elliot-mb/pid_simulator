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

    //all overriden
    const PointMass getMidpoint(); 
    const PointMass getFirstPoint();
    const PointMass getSecondPoint();

    void setFirstPos(glm::vec2 pos);
    void setSecondPos(glm::vec2 pos);

    const glm::vec2 getPos();
    const float     getMass();
    void            setPos(glm::vec2 pos);

private:

    glm::vec2 m_pos;
    const float m_mass;
};

#endif