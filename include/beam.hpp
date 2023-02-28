#ifndef BEAM_H
#define BEAM_H

#include <glm/glm.hpp>

#include "component.hpp"
#include "point_mass.hpp"

//is a Component, contains two PointMass es
class Beam: public Component
{
public:
    // a Beam of mass 1 should have 0.5f, 0.5f point masses respectively 
    Beam(glm::vec2 posA, glm::vec2 posB, float mass=1.0f);

    virtual const PointMass getMidpoint(); 
    virtual const PointMass getFirstPoint();
    virtual const PointMass getSecondPoint();
    virtual const glm::vec2 getFirstPos();
    virtual const glm::vec2 getSecondPos();

    virtual void setFirstPos(glm::vec2 pos);
    virtual void setSecondPos(glm::vec2 pos);

    virtual const float getMass();

private:

    PointMass &m_pointA;
    PointMass &m_pointB; 
    // no mass prop., mass is encoded as the sum of the two pointmasses

};

#endif