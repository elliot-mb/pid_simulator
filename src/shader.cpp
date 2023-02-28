#include "../include/shader.hpp"

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

    // constructor reads and builds the shader
Shader::Shader(const char* vertexPath, const char* fragmentPath){
    // 1. retrieve the vertex/fragment source code from filePath
    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;
    vShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    try 
    {
        // open files
        vShaderFile.open(vertexPath);
        fShaderFile.open(fragmentPath);
        std::stringstream vShaderStream, fShaderStream;
        // read file's buffer contents into streams
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();		
        // close file handlers
        vShaderFile.close();
        fShaderFile.close();
        // convert stream into string
        vertexCode   = vShaderStream.str();
        fragmentCode = fShaderStream.str();		
    }
    catch(std::ifstream::failure &e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
    }
    const char* vShaderCode = vertexCode.c_str();
    const char* fShaderCode = fragmentCode.c_str();

    unsigned int vertex, fragment;

    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCode, NULL);
    glCompileShader(vertex);
    this->printShaderErrors(vertex, GL_VERTEX_SHADER_AS_STR);
    
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCode, NULL);
    glCompileShader(fragment);
    this->printShaderErrors(fragment, GL_FRAGMENT_SHADER_AS_STR);

    ID = glCreateProgram();
    glAttachShader(ID, vertex);
    glAttachShader(ID, fragment);
    glLinkProgram(ID);
    this->printProgramErrors(ID);

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

// use/activate the shader
void Shader::use()
{
    glUseProgram(ID);
}
// utility uniform functions
// & is passing by reference; you dont have to de-ref it like with * 
void Shader::setUniform(const std::string &name, bool value) const
{         
    glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value); 
}

void Shader::setUniform(const std::string &name, int value) const
{ 
    glUniform1i(glGetUniformLocation(ID, name.c_str()), value); 
}
void Shader::setUniform(const std::string &name, float value) const
{ 
    glUniform1f(glGetUniformLocation(ID, name.c_str()), value); 
} 
void Shader::setUniform(const std::string &name, glm::vec2 value) const
{
    glUniform2f(glGetUniformLocation(ID, name.c_str()), value.x, value.y);
}
void Shader::setUniform(const std::string &name, glm::vec4 value) const 
{
    glUniform4f(glGetUniformLocation(ID, name.c_str()), value.x, value.y, value.z, value.w);
}
void Shader::setUniform(const std::string &name, glm::mat4 value) const 
{
    glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
}


void Shader::printShaderErrors(unsigned int shader, const char* type){
    int success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::" << type << "::COMPILATION_FAILED\n" << infoLog << std::endl;
    };
}

void Shader::printProgramErrors(unsigned int programID){
    int success;
    char infoLog[512];
    glGetProgramiv(programID, GL_LINK_STATUS, &success);
    if(!success)
    {
        glGetProgramInfoLog(programID, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
}
