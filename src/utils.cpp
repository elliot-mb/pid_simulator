#include "../include/utils.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <math.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <vector>
#include <array>
#include <iostream>

using namespace glm;
using namespace std;

void pushVec(vec3 v, vector<float> &vect){
    vect.push_back(v.x); vect.push_back(v.y); vect.push_back(v.z);
}

void pushVec(vec4 v, vector<float> &vect){
    vect.push_back(v.x); vect.push_back(v.y); vect.push_back(v.z); vect.push_back(v.w);
}
