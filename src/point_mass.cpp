#include "../include/point_mass.hpp"

#include <glm/glm.hpp>
#include <stdexcept>

using namespace std;

PointMass::PointMass():m_pos(glm::vec2(0.0f, 0.0f)), m_mass(1.0f){}

PointMass::PointMass(glm::vec2 pos, float mass):
    m_mass(mass) //set const
{
    assert(mass >= 0.0f);
    m_pos = pos;
}

void PointMass::acceptDraw(ComponentVisitor& componentVisitor){
    componentVisitor.visitDrawPoint(*this);
}

const glm::vec2 PointMass::getPos(){
    return m_pos;
}
void PointMass::setPos(glm::vec4 pos){
    assert(pos.z == 0.0f && pos.w == 0.0f); //checks we dont use it incorrectly
    m_pos = glm::vec2(pos.x, pos.y); //discards other two elements
}

const float PointMass::getMass(){
    return m_mass;
}