#include "../include/beam.hpp"
#include "../include/point_mass.hpp"

#include <glm/glm.hpp>

using namespace std;

Beam::Beam(glm::vec2 posA, glm::vec2 posB, float mass=1.0f):m_pointA(PointMass(posA, (float)mass/2)),m_pointB(PointMass(posB, (float)mass/2)){
    //uniform beam
}

const PointMass Beam::getFirstPoint(){
    return m_pointA;
}
//always throws a runtime error if we want the second point of a point mass...
const PointMass Beam::getSecondPoint(){
    return m_pointB;
}

const PointMass Beam::getMidpoint(){
    const glm::vec2 posA = m_pointA.getFirstPos();
    const glm::vec2 posB = m_pointB.getFirstPos();
    const float    massA = m_pointA.getMass();
    const float    massB = m_pointB.getMass();
    return Point(0.5f * (posA + posB), massA + massB);
}

const float Beam::getMass(){
    return m_pointA.getMass() + m_pointB.getMass();
}

void Beam::setFirstPos(glm::vec2 pos){
    m_pointA = Point(pos, m_pointA.getMass());
}

//always throws a runtime error if we want the second point of a point mass...
void Beam::setSecondPos(glm::vec2 pos){
    m_pointB = Point(pos, m_pointB.getMass());
}
