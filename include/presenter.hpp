#ifndef PRESENTER_H
#define PRESENTER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <math.h>

#include "shape.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <vector>

class Presenter {
public:
    // initialises presenter with collection of shapes
    Presenter(Shape shapes[]);

    void setShapes(Shape shapes[]);

private:

    //reference to shapes passed at initialisation or set by setShapes
    Shape m_shapes[];
};

#endif