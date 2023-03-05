#include "../include/spring.hpp"

Spring::Spring(glm::vec2 posA, glm::vec2 posB, float mass, float k):
    Beam(posA, posB, mass),
    m_k(k)
{}

const float Spring::getK(){
    return m_k;
}