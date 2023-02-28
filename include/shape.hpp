#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace std;
using namespace glm;

class Shape //base class for all shapes
{
    
public:

    Shape();

    vec2 getPosA(); //getters
    vec2 getPosB();

private:
    vec2 m_posA; 
    vec2 m_posB; //points like circles, point masses and motors have m_posB = m_posA
    
};

#endif