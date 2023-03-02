#ifndef COMPONENT_VISITOR_H
#define COMPONENT_VISITOR_H

#include <glm/glm.hpp>
#include <vector>

// #include "component.hpp"

using namespace std;

class Component;

class ComponentVisitor //interface
{
    //visit method for all concrete underlying component classes
public:
    //modify the state of the caller (adds transformations)
    virtual void visitDrawPoint(Component& pointMass) = 0;
    virtual void visitDrawBeam(Component& beam) = 0;

};

#endif