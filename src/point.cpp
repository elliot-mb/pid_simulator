#include "../include/point.hpp"

#include <glm/glm.hpp>

using namespace std;

Point::Point(glm::vec2 pos, float mass=1.0f):
    m_mass(mass) //set const
{
    m_pos = pos;
}

const glm::vec2 Point::getPos(){
    return m_pos;
}

const float Point::getMass(){
    return m_mass;
}

void Point::setPos(glm::vec2 pos){
    m_pos = pos;
}