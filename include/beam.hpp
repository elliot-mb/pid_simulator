#ifndef BEAM_H
#define BEAM_H

#include "drawing_visitor.hpp"
#include "point_mass.hpp"
#include "component.hpp"

#include <glm/glm.hpp>

class Beam : public Component
{
public:
    //set positions, work out length, work out mass
    Beam();
    Beam(glm::vec2 posA, glm::vec2 posB);
    Beam(glm::vec2 posA, glm::vec2 posB, float mass);
    
    const glm::vec2 getPosA(); 
    const glm::vec2 getPosB(); 
    // PointMass& getPointA();
    // PointMass& getPointB();

    //inherited
    void accept(DrawingVisitor& visitor);

    const glm::vec2 getPos(); //gets centre
    void            setPos(glm::vec4 pos); //pos.x, pos.y -> posA, pos.z, pos.w -> posB
    const float getMass();

private:
    const float m_length; //calculated in constructor

    PointMass m_pointA;
    PointMass m_pointB;
};

#endif
