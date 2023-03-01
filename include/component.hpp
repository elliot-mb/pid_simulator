#ifndef COMPONENT_H
#define COMPONENT_H

#include "component_visitor.hpp"

#include <glm/glm.hpp>

//upper-most physical object class
//interface; does not get instantiated
class Component
{
public:
    
    //visitor pattern
    virtual vector<glm::mat4>& acceptDraw(ComponentVisitor& componentVisitor) = 0;
    virtual const vector<vector<unsigned int>>& acceptIndices(ComponentVisitor& componentVisitor) = 0;

    virtual const glm::vec2 getPos() = 0;
    virtual void            setPos(glm::vec4 pos) = 0; 

    virtual const float getMass() = 0;
};

#endif