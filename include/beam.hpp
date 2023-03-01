#ifndef BEAM_H
#define BEAM_H

#include "point_mass.hpp"
#include "component.hpp"
#include "component_visitor.hpp"

#include <glm/glm.hpp>

class Beam : public Component
{
public:
    //set positions, work out length, work out mass
    Beam(glm::vec2 posA, glm::vec2 posB, float mass=1.0f);
    
    const glm::vec2 getPosA(); 
    // void            setPosA(glm::vec2 pos);
    const glm::vec2 getPosB(); 
    // void            setPosB(glm::vec2 pos);

    //inherited
    vector<glm::mat4>& acceptDraw(ComponentVisitor& componentVisitor);
    const vector<vector<unsigned int>>& acceptIndices(ComponentVisitor& componentVisitor);

    const glm::vec2 getPos(); //gets centre
    void            setPos(glm::vec4 pos); //pos.x, pos.y -> posA, pos.z, pos.w -> posB
    const float getMass();

private:
    const float m_length; //calculated in constructor

    PointMass m_pointA;
    PointMass m_pointB;
};

#endif
