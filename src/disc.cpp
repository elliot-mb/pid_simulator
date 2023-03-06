#include "../include/disc.hpp"

Disc::Disc(glm::vec2 pos, float mass, float radius):
    m_radius(radius),
    m_pos(pos),
    m_mass(mass),
    m_theta(0)
{}

void Disc::accept(DrawingVisitor& visitor){
    visitor.visit(*this);
}

const glm::vec2 Disc::getPos(){
    return m_pos;
}

void Disc::setPos(glm::vec4 pos){
    assert(pos.z == 0 && pos.w == 0);

    m_pos = glm::vec2(pos.x, pos.y);
}

const float Disc::getMass(){
    return m_mass;
}

const float Disc::getTheta(){
    return m_theta;
}
void Disc::setTheta(float theta){
    m_theta = theta;
}

const float Disc::getRadius(){
    return m_radius;
}