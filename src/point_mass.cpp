#include "../include/point_mass.hpp"
#include "../include/component.hpp"

#include <glm/glm.hpp>
#include <stdexcept>

using namespace std;

PointMass::PointMass(glm::vec2 pos, float mass=1.0f):
    m_mass(mass) //set const
{
    assert(mass >= 0.0f);
    m_pos = pos;
}

const PointMass PointMass::getFirstPoint(){
    return PointMass(m_pos, m_mass);
}
//always throws a runtime error if we want the second point of a point mass...
const PointMass PointMass::getSecondPoint(){
    throw logic_error("Error::PointMass::getSecondPoint()_not_allowed");
}

const PointMass PointMass::getMidpoint(){
    return getFirstPoint();
}

const float PointMass::getMass(){
    return m_mass;
}

const glm::vec2 PointMass::getFirstPos(){
    return m_pos;
}
const glm::vec2 PointMass::getSecondPos(){
    throw logic_error("Error::PointMass::getSecondPos()_not_allowed");
}

void PointMass::setFirstPos(glm::vec2 pos){
    m_pos = pos;
}

//always throws a runtime error if we want the second point of a point mass...
void PointMass::setSecondPos(glm::vec2 pos){
    throw logic_error("Error::PointMass::setSecondPos()_not_allowed");
}