#include "../include/spring.hpp"

Spring::Spring(glm::vec2 posA, glm::vec2 posB, float mass, float k):
    Beam(posA, posB, mass),
    m_k(k)
{}

void Spring::accept(DrawingVisitor& visitor){
    visitor.visit(m_pointA);
    visitor.visit(m_pointB);
    visitor.visit(*this);
}

const float Spring::getK(){
    return m_k;
}

const float Spring::getCurrentLength(){
    return glm::distance(this->getPosA(), this->getPosB());
}