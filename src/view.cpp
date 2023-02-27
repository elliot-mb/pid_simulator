#include "../include/view.hpp"
#include "../include/utils.hpp"
#include "../include/shader.hpp"

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
    pushVec(this->m_circleColour, vertices);

    float step = 2 * (PI / sides);
    for(int i = 0; i < sides; i++){
        pushVec(vec3(cos(step * i), sin(step * i), 0.0f), vertices);
        pushVec(this->m_circleColour, vertices);
        //starts at index 0, because the circle is what goes in vertices first
        indices.push_back(0);
        indices.push_back(i+1);
        indices.push_back(((i+1) % sides) + 1);
    }

    showVec(indices); cout << endl;
}

View::View():
    m_circleColour(vec3(1.0f, 1.0f, 1.0f)),
    m_squareColour(vec3(0.5f, 0.5f, 1.0f)),
    m_shader(Shader("./shader_vertex.glsl", "./shader_fragment.glsl")),
    m_circleResolution(10)
{
    glGenBuffers(1, &this->m_VBO);
    glGenVertexArrays(1, &this->m_VAO);
    glGenBuffers(1, &this->m_EBO);

    glBindBuffer(GL_ARRAY_BUFFER, this->m_VBO);
    glBindVertexArray(this->m_VAO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->m_EBO);

    vector<float> vertices = {};

    //pushes a circle of colour circlecolour
    this->m_generateCircle(this->m_circleResolution, vertices, this->m_circleIndices);

    //pushes a square of colour squarecolour 
    pushVec(vec3(-1.0f, -1.0f, 0.0f), vertices);     
    pushVec(this->m_squareColour, vertices);
    pushVec(vec3(-1.0f,  1.0f, 0.0f), vertices);
    pushVec(this->m_squareColour, vertices);
    pushVec(vec3( 1.0f,  1.0f, 0.0f), vertices);   
    pushVec(this->m_squareColour, vertices);
    pushVec(vec3( 1.0f, -1.0f, 0.0f), vertices);
    pushVec(this->m_squareColour, vertices);

    //square offset from circle verts
    const unsigned int CV = this->m_circleResolution + 1;

    this->m_squareIndices = {
        // unit square
        CV, CV + 1, CV + 2,
        CV, CV + 3, CV + 2
    };

    this->m_vertices = vertices;
    glBufferData(GL_ARRAY_BUFFER, this->m_vertices.size() * sizeof(float), &this->m_vertices[0], GL_STATIC_DRAW);

    //position attribute in VBO
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);  
    //colour attribute in VBO
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);  
};

void View::startFrame(){
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        this->m_shader.use();
        glBindVertexArray(m_VAO);
}

void View::drawShape(mat4 trans, vector<unsigned int> &indices){
    this->m_shader.setUniform("transform", trans);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(float), &indices[0], GL_STATIC_DRAW); 
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
}

vector<unsigned int>& View::getSquare() {
    return this->m_squareIndices;
}

vector<unsigned int>& View::getCircle() {
    return this->m_circleIndices;
}

vector<float>& View::getVertices(){
    return this->m_vertices;
}

unsigned int View::getVAO(){
    return this->m_VAO;
}