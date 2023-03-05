#ifndef SLIDER_H
#define SLIDER_H

#include "beam.hpp"

class Slider : public Beam
{
public:
    Slider(glm::vec2 posA, glm::vec2 posB, float mass);

    void accept(DrawingVisitor& visitor);
};

#endif