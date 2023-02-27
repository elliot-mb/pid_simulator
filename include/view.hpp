#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <math.h>

#include "./shader.hpp"

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

    void drawShape(mat4 trans, vector<unsigned int> &indices);

    vector<unsigned int>& getSquare();
    vector<unsigned int>& getCircle();
    vector<float>&        getVertices();
    unsigned int          getVAO();

private:
    void m_generateCircle(unsigned int sides, vector<float> &vertices, vector<unsigned int> &indices);

    vector<float> m_vertices;

    //all our shapes (index into vertices)
    vector<unsigned int> m_circleIndices; //circle (constructor populates vertices[] and this algorithmicly) 10 triangles
    vector<unsigned int> m_squareIndices; // two triangles

    const vec3 m_circleColour;
    const vec3 m_squareColour;
    const unsigned int m_circleResolution;

    unsigned int m_VAO, m_VBO, m_EBO;

    Shader m_shader;
};