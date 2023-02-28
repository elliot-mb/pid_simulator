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

/*
This class transforms representations of components as collections of points, or single points and radii, to shapes and matrix transformations.

These shapes and matrix transformations are then used by the view to render shapes
*/

class Presenter {
public:
    // initialises presenter with collection of shapes
    Presenter(Shape shapes[]);

    void setShapes(Shape shapes[]);

private:

    //reference to shapes passed at initialisation or set by setShapes
    
};

#endif