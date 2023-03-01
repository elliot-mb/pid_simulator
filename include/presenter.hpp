#ifndef PRESENTER_H
#define PRESENTER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <math.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <vector>

/*
This class transforms representations of components as collections of points, or single points and radii, to shapes and matrix transformations.

These shapes and matrix transformations are then used by the view to render shapes

.: Idea :.
Use the visitor pattern, creating an interface DrawingVisitor, which Presenter implements, that has a visit method for every concrete subclass of Component;
- Point mass
- Beam
- Disc
- Motor
- Spring
- Slider
These visit methods will create the respective transformation matrices for the view drawing pipeline; primitive shape + transformation = proper visual representation
*/

class Presenter {
public:


private:


};

#endif