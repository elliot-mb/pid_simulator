#include "../include/system_state.hpp"

#include <iostream>

SystemState::SystemState():
    m_components(vector<Component*>{})
{}

// SystemState::~SystemState(){
//     std::cout << "DESTROYING SYSTEM STATE" << std::endl;
//     // for(unsigned int i = 0; i < m_components.size(); i++){
//     //     delete m_components.at(i);
//     //     i++;
//     // }
//     // delete &m_components;
// }

void SystemState::addComponent(Component& component){
    m_components.push_back(&component);
}

const vector<Component*>& SystemState::getComponents(){
    return m_components;
}