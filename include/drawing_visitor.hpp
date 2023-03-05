#ifndef COMPONENT_VISITOR_H
#define COMPONENT_VISITOR_H

#include <glm/glm.hpp>
#include <vector>

using namespace std;

class PointMass;
class Beam;
class Spring;

class DrawingVisitor //interface
{
    //visit method for all concrete underlying component classes
public:
    //modify the state of the caller (adds transformations)
    virtual void visit(PointMass& pointMass) = 0;
    virtual void visit(Beam& beam) = 0;
    virtual void visit(Spring& beam) = 0;

};

#endif