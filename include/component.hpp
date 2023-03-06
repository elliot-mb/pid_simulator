#ifndef COMPONENT_H
#define COMPONENT_H

#include <glm/glm.hpp>
#include <vector>

#include "drawing_visitor.hpp"

using namespace std;

//upper-most physical object class
//interface; does not get instantiated
class Component
{
public:
    virtual ~Component() {}

    //visitor pattern
    virtual void accept(DrawingVisitor& visitor) = 0;

    virtual const glm::vec2 getPos() = 0;
    virtual void            setPos(glm::vec4 pos) = 0; 

    virtual const float getMass() = 0;

// private:

//     glm::vec2 m_pos;
//     glm::vec2 m_vel;
//     glm::vec2 m_acc;
//     const float m_mass;

};

#endif