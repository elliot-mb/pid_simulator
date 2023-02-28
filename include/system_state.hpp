#ifndef SYSTEM_STATE_H
#define SYSTEM_STATE_H

#include "component.hpp"
#include "point_mass.hpp"

#include <vector>

using namespace std;

class SystemState
{
public:
    SystemState();

    //add a new component to the system
    void addComponent();

private:
    
    vector<Component> components;

};

#endif