#ifndef  reportErrors(s) _Report(_LINE_,(s))
#define reportErrors(s) _Report(_LINE_,(s))
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>
#include <iostream>
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtx/transform.hpp"
#include <glm/gtc/type_ptr.hpp>

void _ReportError(int ln, const std::string str) {
    GLuint err = glGetError();//error report
    if (!err) return;
    const GLubyte* glerr = gluErrorString(err);
    printf("******************************************\n%d: %s: GLError %d: %s\n", ln, str.c_str(), err, glerr);//error print out
}


#endif

