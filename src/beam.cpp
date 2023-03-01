#include "../include/beam.hpp"
#include "../include/point_mass.hpp"
#include "../include/component.hpp"

#include <glm/glm.hpp>

using namespace std;

Beam::Beam(glm::vec2 posA, glm::vec2 posB, float mass=1.0f):
    m_pointA(PointMass(posA, (float)mass/2)),
    m_pointB(PointMass(posB, (float)mass/2)),
    m_length(glm::distance(posA, posB))
{
    //uniform beam
}

const glm::vec2 Beam::getPosA(){
    return m_pointA.getPos();
}
const glm::vec2 Beam::getPosB(){
    return m_pointB.getPos();
}

vector<glm::mat4>& Beam::acceptDraw(ComponentVisitor& componentVisitor){
        return componentVisitor.visitDraw(*this);
}

const vector<vector<unsigned int>>& Beam::acceptIndices(ComponentVisitor& componentVisitor){
    return componentVisitor.visitIndices(*this);
}

const glm::vec2 Beam::getPos(){
    const glm::vec2 posA = m_pointA.getPos();
    const glm::vec2 posB = m_pointB.getPos();
    const float    massA = m_pointA.getMass();
    const float    massB = m_pointB.getMass();
    return 0.5f * (posA + posB);
}

const float Beam::getMass(){
    return m_pointA.getMass() + m_pointB.getMass();
}

void Beam::setPos(glm::vec4 pos){
    m_pointA.setPos(glm::vec4(pos.x, pos.y, 0.0f, 0.0f));
    m_pointB.setPos(glm::vec4(pos.z, pos.w, 0.0f, 0.0f));
}