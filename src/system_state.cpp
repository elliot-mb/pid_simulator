#include "../include/system_state.hpp"

SystemState::SystemState():
    m_components(vector<Component&>{})
{}

void SystemState::addComponent(PointMass& pointMass){
    m_components.push_back(pointMass);
}

void SystemState::addComponent(Beam& beam){
    m_components.push_back(beam);
}

const vector<Component&>& SystemState::getComponents(){
    return m_components;
}