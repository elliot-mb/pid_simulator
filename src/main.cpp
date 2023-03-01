#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <math.h>

#include "../include/shader.hpp"
#include "../include/view.hpp"
#include "../include/utils.hpp"
#include "../include/presenter.hpp"
#include "../include/system_state.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>

#define IS_CIRCLE 1.0f
#define IS_NOT_CIRCLE 0.0f

using namespace std;

float getViewportRatio(unsigned int width, unsigned int height){
    return width > height ? (float)height / width : (float)width / height;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    float viewportRatio = getViewportRatio(width, height);
    unsigned int maxDimension = std::max(width, height);
    unsigned int xOffset = (unsigned int) round(((1 - viewportRatio) / -2) * height);
    unsigned int yOffset = (unsigned int) round(((1 - viewportRatio) / -2) * width);
    glViewport(height > width ? xOffset : 0, width > height ? yOffset : 0, maxDimension, maxDimension);
}

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

int main(){

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); //3.3 is the version we will use
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(900, 600, "LearnOpenGL", NULL, NULL);
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
    glViewport(0, 0, 900, 600); //lower left corner, width, height

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);  


    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    framebuffer_size_callback(window, width, height);

    Presenter presenter = Presenter();
    SystemState systemState = presenter.getSystemState();
    
    PointMass pm = PointMass(glm::vec2(0.0f));
    Beam b = Beam(glm::vec2(0.0f), glm::vec2(1.0f));
    systemState.addComponent(pm);
    systemState.addComponent(b);

    // cout << view.getSquare() << endl;

    while(!glfwWindowShouldClose(window))
    {
        processInput(window);   

        glfwGetFramebufferSize(window, &width, &height);
        float viewportRatio = getViewportRatio(width, height);

        presenter.drawView();

        // //transformations 
        // mat4 transViewport = glm::scale(mat4(1.0f), glm::vec3(viewportRatio));
        // mat4 trans = glm::translate(transViewport, vec3(0.5f, 0.0f, 0.0f));
        // trans = glm::rotate(trans, (float)glfwGetTime(), vec3(0.0f, 0.0f, 1.0f));

        // //shape drawing 
        // view.drawShape(view.getSquare(), transViewport, vec4(1.0f, 0.5f, 1.0f, 1.0f));
        // view.drawShape(view.getCircle(), trans, vec4(0.0f, 1.0f, 1.0f, 1.0f));

        // //more transformations
        // mat4 transLeft = glm::translate(transViewport, vec3(-1.0f, 0.0f, 0.0f));
        // transLeft = glm::scale(transLeft, vec3(0.5f));
        // transLeft = glm::rotate(transLeft, (float)glfwGetTime() * -2, vec3(0.0f, 0.0f, 1.0f));

        // //more shape drawing
        // view.drawShape(view.getCircle(), transLeft, vec4(1.0f, 1.0f, 1.0f, 1.0f));
        // mat4 transLeftSquash = glm::scale(transLeft, vec3(0.1f, 1.0f, 1.0f));
        // view.drawShape(view.getTriangle(), transLeft, view.getSquareColour());

        glfwSwapBuffers(window);
        glfwPollEvents();    
    }

    glfwTerminate();
    return 0;
}