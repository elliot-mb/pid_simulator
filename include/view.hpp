#ifndef VIEW_H
#define VIEW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <math.h>

#include "utils.hpp"
#include "shader.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <vector>
#include <array>
#include <iostream>

using namespace std;
using namespace glm;

// contains all the opengl rendering guts 

class View{
public:

    // initialises VBO, VAO, and EBO (swapped out to render different shapes)
    View();

    void startFrame();

    void drawShape(const vector<unsigned int> &shapeIndices, mat4 &transform, const vec4 &colour);

    const vector<unsigned int>& getSquare();
    const vector<unsigned int>& getCircle();
    const vector<unsigned int>& getTriangle();
    const vector<float>&        getVertices();
    const unsigned int          getVAO();
    const vec4                  getCircleColour();
    const vec4                  getSquareColour();

private:
    void m_generateCircle(unsigned int sides, vector<float> &vertices, vector<unsigned int> &indices);

    vector<float> m_vertices = {
        //triangle (equalteral, centered on origin)
        -0.86603, -0.5, 0.0,
         0.86603, -0.5, 0.0,
         0.0,      1.0, 0.0,
        //square
        -1.0, -1.0, 0.0, 
         1.0, -1.0, 0.0,
         1.0,  1.0, 0.0,
        -1.0,  1.0, 0.0
    };
    //all our shapes (index into vertices)
    const vector<unsigned int> m_TRIANGLE_INDICES = {
        0, 1, 2
    };
    const vector<unsigned int> m_SQUARE_INDICES = {
        3, 4, 5,
        3, 6, 5
    }; 
    const unsigned int m_CIRCLE_RESOLUTION = 20;
    const unsigned int m_CIRCLE_OFFSET = 7;
    //generated in constructor (not const)
    vector<unsigned int> m_circleIndices; 

    const vec3 m_DEFAULT_CIRCLE_COLOUR = vec3(1.0f, 1.0f, 1.0f);
    const vec3 m_DEFAULT_SQUARE_COLOUR = vec3(0.5f, 0.5f, 1.0f);

    unsigned int m_VAO, m_VBO, m_EBO;

    Shader m_shader;
};

#endif