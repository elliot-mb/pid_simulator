#include "../include/slider.hpp"

Slider::Slider(glm::vec2 posA, glm::vec2 posB, float mass):
    Beam(posA, posB, mass)
{}

void Slider::accept(DrawingVisitor& visitor){
    visitor.visit(*this);
    visitor.visit(m_pointA);
    visitor.visit(m_pointB);
}