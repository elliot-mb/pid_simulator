#ifndef DISC_H
#define DISC_H

#include "component.hpp"

class Disc : public Component
{
public:
    Disc(glm::vec2 pos, float mass, float radius);

    void accept(DrawingVisitor& visitor);

    const glm::vec2 getPos();
    void            setPos(glm::vec4 pos);

    const float getMass();

    const float getTheta();
    void        setTheta(float theta);

    const float getRadius();

private:
    const float m_radius;

    glm::vec2 m_pos;
    const float m_mass;
    float m_theta; 

};

#endif