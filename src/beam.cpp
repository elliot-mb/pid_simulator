#include "../include/beam.hpp"

#include <glm/glm.hpp>

using namespace std;

Beam::Beam(glm::vec2 posA, glm::vec2 posB, float mass):m_length(glm::distance(posA, posB))
{
    PointMass m_pointA(posA, (float)mass/2);
    PointMass m_pointB(posB, (float)mass/2);
}

const glm::vec2 Beam::getPosA(){
    return m_pointA.getPos();
}
const glm::vec2 Beam::getPosB(){
    return m_pointB.getPos();
}

void Beam::acceptDraw(ComponentVisitor& componentVisitor){
    componentVisitor.visitDrawBeam(*this);
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