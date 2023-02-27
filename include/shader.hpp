
#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h> // include glad to get all the required OpenGL headers

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
  
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
  
#define GL_VERTEX_SHADER_AS_STR "GL_VERTEX_SHADER\0"
#define GL_FRAGMENT_SHADER_AS_STR "GL_FRAGMENT_SHADER\0"

class Shader
{
public:
    // the program ID
    unsigned int ID;
  
    // constructor reads and builds the shader
    Shader(const char* vertexPath, const char* fragmentPath);

    // use/activate the shader
    void use();

    // utility uniform functions
    // & is passing by reference; you dont have to de-ref it like with * 
    void setUniform(const std::string &name, bool value) const;

    void setUniform(const std::string &name, int value) const;

    void setUniform(const std::string &name, float value) const;

    void setUniform(const std::string &name, glm::vec2 value) const;

    void setUniform(const std::string &name, glm::mat4 value) const;


private:
    void printShaderErrors(unsigned int shader, const char* type);

    void printProgramErrors(unsigned int programID);
};
  
#endif