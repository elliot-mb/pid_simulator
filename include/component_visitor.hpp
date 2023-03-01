#ifndef COMPONENT_VISITOR_H
#define COMPONENT_VISITOR_H

#include <glm/glm.hpp>
#include <vector>

#include "point_mass.hpp"
#include "beam.hpp"

using namespace std;

class ComponentVisitor //interface
{
    //visit method for all concrete underlying component classes
public:
    //return all the transformations needed in a component
    virtual vector<glm::mat4>& visitDraw(PointMass& pointMass) = 0;
    virtual vector<glm::mat4>& visitDraw(Beam& beam) = 0;
     //return all the shapes needed in a component
    virtual const vector<vector<unsigned int>>& visitIndices(PointMass& pointMass) = 0;
    virtual const vector<vector<unsigned int>>& visitIndices(Beam& beam) = 0;

};

#endif