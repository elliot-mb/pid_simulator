/* ,; Notes ;,

GLSL

A shader has the following structure:
- version
- inputs
- outputs 
- uniforms
- void main function (entrypoint)

Vectors 

vec3 v = { 0.1f, 1.0f, 0.2f }; v.x => 0.1f, v.z => 0.2f
vec4 vSwizzled = v.xzxx; vSwizzled => { 0.1f, 0.2f, 0.1f, 0.1f }

// ';       ;' */

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <math.h>

#include "../include/shader.hpp"
#include "../include/view.hpp"
#include "../include/utils.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>

#define IS_CIRCLE 1.0f
#define IS_NOT_CIRCLE 0.0f

using namespace std;

// Hello Triangle

//in this part of the tutorial we dont use the geometry shader 
// const char *vertexShaderSource = "#version 330 core\n"
//     "layout (location = 0) in vec3 aPos;\n"
//     "layout (location = 1) in vec3 aColor;\n"
//     "out vec3 ourColor;\n"
//     "void main()\n"
//     "{\n"
//     "   gl_Position = vec4(aPos, 1.0);\n"
//     "   ourColor = aColor;"
//     "}\0";

// const char *fragmentShaderSource = "#version 330 core\n"
//     "out vec4 FragColor;\n"
//     "in vec3 ourColor;\n"
//     "void main()\n"
//     "{\n"
//     "    FragColor = vec4(ourColor, 1.0);\n"
//     "}\0"; 

float getViewportRatio(unsigned int width, unsigned int height){
    return width > height ? (float)height / width : (float)width / height;
}


//Hello Window

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    // unsigned int size = min(width, height);
    // unsigned int diff = width > height ? width - height : height - width;
    // glViewport(width > height ? diff/2 : 0, height > width ? diff/2 : 0, size, size);
    float viewportRatio = getViewportRatio(width, height);
    unsigned int maxDimension = std::max(width, height);
    unsigned int xOffset = (unsigned int) round(((1 - viewportRatio) / -2) * height);
    unsigned int yOffset = (unsigned int) round(((1 - viewportRatio) / -2) * width);
    cout << ((1 - viewportRatio) / -2) * height << "," << ((1 - viewportRatio) / -2) * width << endl;
    glViewport(height > width ? xOffset : 0, width > height ? yOffset : 0, maxDimension, maxDimension);
    // glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
    
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

int main(){

    //Hello Window

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); //3.3 is the version we will use
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 800, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window); //sets context on our current thread

    //initialise glad to map to the opengl functions on our specific operating system
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }    

    //tell opengl the size of the rendering window
    glViewport(0, 0, 800, 800); //lower left corner, width, height

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);  

    // Shader ourShader("./shader_vertex.glsl", "./shader_fragment.glsl");

    // //Compile-time error checking

    // //Hello Triangle
    // float vertices[] = {
    //     //// triangle
    //     //point              colours                  
    //     -0.5f, -0.5f, 0.0f,     0.5f, 0.5f, 0.5f,     
    //     0.5f,  -0.5f, 0.0f,     0.5f, 0.5f, 0.5f,     
    //     0.0f,   0.5f, 0.0f,     0.5f, 0.5f, 0.5f,

    //     //// unit square
    //     -1.0f, -1.0f, 0.0f,     0.5f, 0.5f, 0.5f,
    //     -1.0f,  1.0f, 0.0f,     0.5f, 0.5f, 0.5f,
    //      1.0f,  1.0f, 0.0f,     0.5f, 0.5f, 0.5f,
    //      1.0f, -1.0f, 0.0f,     0.5f, 0.5f, 0.5f,
    //     // -0.5f, -0.5f, 0.0f,     1.0f, 0.5f, 0.5f,     
    //     // 0.5f,  -0.5f, 0.0f,     0.5f, 1.0f, 0.5f,     
    //     // 0.0f,   0.5f, 0.0f,     0.5f, 0.5f, 1.0f
    // };

    // unsigned int indicesTriangle[] = {
    //     // triangle
    //     0, 1, 2,
    // };

    // unsigned int indicesSquare[] = {
    //     // unit square
    //     3, 4, 5,
    //     3, 6, 5
    // };

    // unsigned int EBO, VBO, VAO;
    // glGenBuffers(1, &EBO);
    // glGenBuffers(1, &VBO); //...becomes the address? 
    // //we need to bind the buffer 
    // glGenVertexArrays(1, &VAO);
    // glBindVertexArray(VAO);

    // glBindBuffer(GL_ARRAY_BUFFER, VBO);
    // //configuring the above bound buffer 
    // //copies defined data into the buf
    // glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); //if we're updating something a lot, do we use stream-draw?

    // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

    // //position attribute in VBO
    // glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    // glEnableVertexAttribArray(0);  
    // //colour attribute in VBO
    // glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    // glEnableVertexAttribArray(1);  

    View view = View();

    showVec(view.getCircle()); cout << endl;
    showVec(view.getSquare()); cout << endl;
    showVec(view.getVertices()); cout << endl;

    while(!glfwWindowShouldClose(window))
    {
        processInput(window);

        view.startFrame();

        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        float viewportRatio = getViewportRatio(width, height);

        mat4 transViewport = glm::scale(mat4(1.0f), glm::vec3(viewportRatio));

        view.drawShape(transViewport, view.getSquare());
        view.drawShape(transViewport, view.getCircle());

        // glBindVertexArray(VAO);

        // float timeValue = glfwGetTime();

        
        // glm::mat4 trans = glm::mat4(1.0f);
        // trans = glm::scale(trans, glm::vec3(viewportRatio));

        // ourShader.use();
        // ourShader.setUniform("transform", trans);

        // glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicesSquare), indicesSquare, GL_STATIC_DRAW); 

        // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        // trans = glm::mat4(1.0f);
        // trans = glm::scale(trans, glm::vec3(viewportRatio));
        // trans = glm::translate(trans, glm::vec3(0.5f, -0.5f, 0.0f));
        // trans = glm::rotate(trans, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));

        // ourShader.setUniform("transform", trans);

        // //bind triangle EBO
        // glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicesTriangle), indicesTriangle, GL_STATIC_DRAW); 

        // //element buffer object so we only draw distinct verts
        // //glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        // glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);

        // trans = glm::mat4(1.0f);
        // trans = glm::scale(trans, glm::vec3(viewportRatio));
        // trans = glm::translate(trans, glm::vec3(-0.5f, 0.5f, 0.0f));
        // trans = glm::scale(trans, sin((float)glfwGetTime()) * glm::vec3(2.0f, 1.0f, 1.0f));

        // ourShader.setUniform("transform", trans);

        // //bind triangle EBO
        // glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicesSquare), indicesSquare, GL_STATIC_DRAW); 

        // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        // // vertices[0] += 0.001f;
        // // glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STREAM_DRAW);

        glfwSwapBuffers(window); // a little render queue of length 2 called a double buffer
        glfwPollEvents();    
    }

    glfwTerminate();
    return 0;
}