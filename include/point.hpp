#ifndef POINT_H
#define POINT_H

#include "./shader.hpp"

#include <glm/glm.hpp>

using namespace std;

class Point
{
public:
    Point(glm::vec2 pos, float mass=1.0f);

    const glm::vec2 getPos();
    const float     getMass();
    void            setPos(glm::vec2 pos);

private:
    glm::vec2 m_pos;
    const float m_mass;
};

#endif