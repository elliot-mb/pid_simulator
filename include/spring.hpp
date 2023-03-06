#ifndef SPRING_H
#define SPRING_H

#include "drawing_visitor.hpp"
#include "beam.hpp"

class Spring : public Beam
{
public: 

    Spring(glm::vec2 posA, glm::vec2 posB, float mass, float k);

    void accept(DrawingVisitor & visitor);

    const float getK();
    const float getCurrentLength();

private:

    const float m_k; //spring constant 
};

#endif