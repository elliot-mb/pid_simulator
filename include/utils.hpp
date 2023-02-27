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

void pushVec(vec3 v, vector<float> &vect);
void pushVec(vec4 v, vector<float> &vect);

template <class T>
void showVec(vector<T> vect){
    cout << "vector:";
    for(const T& v : vect){
        cout << v << ", ";
    }
}