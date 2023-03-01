#include "../include/point_mass.hpp"

#include <glm/glm.hpp>
#include <stdexcept>

using namespace std;

PointMass::PointMass(glm::vec2 pos, float mass=1.0f):
    m_mass(mass) //set const
{
    assert(mass >= 0.0f);
    m_pos = pos;
}

vector<glm::mat4>& PointMass::acceptDraw(ComponentVisitor& componentVisitor){
    return componentVisitor.visitDraw(*this);
}

const vector<vector<unsigned int>>& PointMass::acceptIndices(ComponentVisitor& componentVisitor){
    return componentVisitor.visitIndices(*this);
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