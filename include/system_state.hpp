#ifndef SYSTEM_STATE_H
#define SYSTEM_STATE_H

#include "component.hpp"
#include "point_mass.hpp"
#include "beam.hpp"
#include "spring.hpp"
#include "slider.hpp"
#include "disc.hpp"

#include <vector>
#include <glm/glm.hpp>

using namespace std;

class SystemState
{
public:
    SystemState();

    void addComponent(Component& component); 

    const vector<Component*>& getComponents(); //gets the reference to our components vector

private:
    
    vector<Component*> m_components;

};

#endif