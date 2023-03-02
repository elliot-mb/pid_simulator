#ifndef PRESENTER_H
#define PRESENTER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <math.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "component_visitor.hpp"
#include "system_state.hpp"
#include "view.hpp"

#include <iostream>
#include <vector>

/*
This class transforms representations of Components to shapes, matrix transformations and colour that View can render.

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

class Presenter : public ComponentVisitor {
public:

    Presenter();
    ~Presenter();

    //inherited from ComponentVisitor
    void visitDrawPoint(Component& pointMass);
    void visitDrawBeam(Component& beam);
    void visitIndicesPoint(Component& pointMass);
    void visitIndicesBeam(Component& beam);

    SystemState& getSystemState();
    View& getView();

    void setViewportTransform(float viewportRatio);

    void drawView();
    void clearBuffers();

private:

    SystemState m_systemState;
    View m_view;

    //written to then cleared every frame
    vector<glm::mat4> m_transformBuffer; //contains transformations
    vector<vector<unsigned int>> m_indexBuffer; //contains shapes (specifically shape vertex indices)
    vector<glm::vec3> m_colourBuffer; 

    glm::mat4 m_viewportTransform;
};

#endif