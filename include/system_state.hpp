#ifndef SYSTEM_STATE_H
#define SYSTEM_STATE_H

#include "component.hpp"
#include "component_visitor.hpp"
#include "point_mass.hpp"
#include "beam.hpp"

#include <vector>
#include <glm/glm.hpp>

using namespace std;

class SystemState
{
public:
    SystemState();

    void addComponent(PointMass& pointMass);
    void addComponent(Beam& beam);
    const vector<Component>& getComponents(); //gets the reference to our components vector

private:
    
    vector<Component> m_components;

};

#endif