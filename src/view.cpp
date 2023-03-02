#include "../include/view.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <math.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <vector>
#include <iostream>

using namespace std;
using namespace glm;

#define PI 3.141592653589793

void View::m_generateCircle(unsigned int sides, vector<float> &vertices, vector<unsigned int> &indices){
    pushVec(vec3(0.0f, 0.0f, 0.0f), vertices); 

    float step = 2 * (PI / sides);
    for(unsigned int i = 0; i < sides; i++){
        pushVec(vec3(cos(step * i), sin(step * i), 0.0f), vertices);
        //starts at index 0, because the circle is what goes in vertices first
        indices.push_back(m_CIRCLE_OFFSET);
        indices.push_back(i + 1 + m_CIRCLE_OFFSET);
        indices.push_back(((i+1) % sides) + 1 + m_CIRCLE_OFFSET);
    }

    // showVec(m_vertices); cout << endl;
    // showVec(indices); cout << endl;
}

View::View():
    m_shader(Shader("./shader_vertex.glsl", "./shader_fragment.glsl"))
{
    glGenBuffers(1, &m_VBO);
    glGenVertexArrays(1, &m_VAO);
    glGenBuffers(1, &m_EBO);

    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBindVertexArray(m_VAO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);

    //pushes a circle to vertices array
    m_generateCircle(m_CIRCLE_RESOLUTION, m_vertices, m_circleIndices);

    glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(float), &m_vertices[0], GL_STATIC_DRAW);

    //position attribute in VBO
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0); //stride of three as every vec3 is a vertex
    glEnableVertexAttribArray(0);  
};

void View::startFrame(){
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    m_shader.use();
    glBindVertexArray(m_VAO);
}

void View::drawShape(const vector<unsigned int> &shapeIndices, mat4 &transform, const vec4 &colour){
    m_shader.setUniform("transform", transform);
    m_shader.setUniform("colour", colour);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, shapeIndices.size() * sizeof(float), &shapeIndices[0], GL_STATIC_DRAW); 
    glDrawElements(GL_TRIANGLES, shapeIndices.size(), GL_UNSIGNED_INT, 0);
}

const vector<unsigned int>& View::getSquare() {
    return m_SQUARE_INDICES;
}
const vector<unsigned int>& View::getCircle() {
    return m_circleIndices;
}
const vector<unsigned int>& View::getTriangle() {
    return m_TRIANGLE_INDICES;
}

const vector<float>& View::getVertices(){
    return m_vertices;
}

const unsigned int View::getVAO(){
    return m_VAO;
}

const vec4 View::getCircleColour(){ return vec4(m_DEFAULT_CIRCLE_COLOUR, 1.0f); }

const vec4 View::getSquareColour(){ return vec4(m_DEFAULT_SQUARE_COLOUR, 1.0f); }