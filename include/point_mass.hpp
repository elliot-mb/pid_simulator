#ifndef POINT_H
#define POINT_H

#include <glm/glm.hpp>
#include "component.hpp"
#include "component_visitor.hpp"

using namespace std;

class PointMass: public Component 
{
public:
    //throws exception if mass is negative
    PointMass(glm::vec2 pos, float mass=1.0f);

    //inherited
    vector<glm::mat4>& acceptDraw(ComponentVisitor& componentVisitor);
    const vector<vector<unsigned int>>& acceptIndices(ComponentVisitor& componentVisitor);

    const glm::vec2 getPos();
    void            setPos(glm::vec4 pos);

    const float getMass();

    
private:

    glm::vec2 m_pos;
    const float m_mass;
};

#endif