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

void SystemState::addComponent(PointMass& pointMass){
    m_components.push_back(&pointMass);
}
void SystemState::addComponent(Beam& beam){
    m_components.push_back(&beam);
}
void SystemState::addComponent(Spring& spring){
    m_components.push_back(&spring);
}
void SystemState::addComponent(Slider& slider){
    m_components.push_back(&slider);
}

const vector<Component*>& SystemState::getComponents(){
    return m_components;
}