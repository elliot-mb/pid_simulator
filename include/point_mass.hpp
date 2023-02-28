#ifndef POINT_H
#define POINT_H

#include <glm/glm.hpp>
#include "component.hpp"

using namespace std;

class PointMass: public Component 
{
public:
    //throws exception if mass is negative
    PointMass(glm::vec2 pos, float mass=1.0f);


    //all implemented
    const PointMass getFirstPoint();
    const PointMass getSecondPoint();
    const PointMass getMidpoint(); 
    const glm::vec2 getFirstPos();
    const glm::vec2 getSecondPos();

    const float getMass();

    void setFirstPos(glm::vec2 pos);
    void setSecondPos(glm::vec2 pos);
    
private:

    glm::vec2 m_pos;
    const float m_mass;
};

#endif