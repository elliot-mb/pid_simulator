#ifndef UTILS_H
#define UTILS_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <math.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <vector>
#include <array>
#include <iostream>

using namespace std;

void pushVec(glm::vec3 v, vector<float> &vect);
void pushVec(glm::vec4 v, vector<float> &vect);

template <class T>
ostream& operator<<(ostream& out, const vector<T> vect){
    vector<T> vectOneLess = vect;
    vectOneLess.pop_back();
    out << "vector: [";
    for(const T& v : vectOneLess){
        out << v << ", ";
    }
    out << vect[vect.size() - 1];
    out << "]";
    return out;
}

#endif