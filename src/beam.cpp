#include "../include/beam.hpp"

#include <glm/glm.hpp>

using namespace std;

Beam::Beam():
    m_length(0),
    m_pointA(PointMass(glm::vec2(0.0f), 0.5f)),
    m_pointB(PointMass(glm::vec2(0.0f), 0.5f))
{}

Beam::Beam(glm::vec2 posA, glm::vec2 posB):
    m_length(glm::distance(posA, posB)),
    m_pointA(PointMass(posA, 0.5f)),
    m_pointB(PointMass(posB, 0.5f))
{}

Beam::Beam(glm::vec2 posA, glm::vec2 posB, float mass):
    m_length(glm::distance(posA, posB)),
    m_pointA(PointMass(posA, mass/2)),
    m_pointB(PointMass(posB, mass/2))
{}

const glm::vec2 Beam::getPosA(){
    return m_pointA.getPos();
}
const glm::vec2 Beam::getPosB(){
    return m_pointB.getPos();
}

// PointMass& Beam::getPointA(){
//     return m_pointA;
// }

// PointMass& Beam::getPointB(){
//     return m_pointB;
// }

void Beam::accept(DrawingVisitor& visitor){
    visitor.visit(*this);
    visitor.visit(m_pointA); //all subcomponents calls can be completed through visitation
    visitor.visit(m_pointB);
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