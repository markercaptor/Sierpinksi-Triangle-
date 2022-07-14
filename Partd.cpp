//Matthew Buehring
//COSC 4328
//10/17/2021
//Dr.King


#define GLEW_STATIC
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
#include "objectdrawing.h"

objectdrawing item;//objectes for each gasket
objectdrawing second;
objectdrawing third;
objectdrawing fourth;
objectdrawing fifth;
objectdrawing sixth;
objectdrawing seventh;

glm::mat4 Projection = glm::mat4(1);         // Use a projection matrix
glm::mat4 View = glm::mat4(1);//view Matrix
glm::mat4 Scales = glm::mat4(1);//scaling matrix
glm::mat4 Sca2 = glm::mat4(1);//scale matrix
glm::mat4 Sca3 = glm::mat4(1);//scale matrix
glm::mat4 Sca4 = glm::mat4(1);//scale matrix
glm::mat4 Sca5 = glm::mat4(1);//scale matrix
glm::mat4 Sca6 = glm::mat4(1);//scale matrix
glm::mat4 Sca7 = glm::mat4(1);//scale matrix
glm::mat4 rotation = glm::rotate(glm::mat4(1.0f), 0.0f, glm::vec3(0.0, 0.0, 0.0));//rotation matricies
glm::mat4 rotation2 = glm::rotate(glm::mat4(1.0f), 0.0f, glm::vec3(0.0, 0.0, 0.0));
glm::mat4 rotation3 = glm::rotate(glm::mat4(1.0f), 0.0f, glm::vec3(0.0, 0.0, 0.0));
glm::mat4 rotation4 = glm::rotate(glm::mat4(1.0f), 0.0f, glm::vec3(0.0, 0.0, 0.0));
glm::mat4 rotation5 = glm::rotate(glm::mat4(1.0f), 0.0f, glm::vec3(0.0, 0.0, 0.0));
glm::mat4 rotation6 = glm::rotate(glm::mat4(1.0f), 0.0f, glm::vec3(0.0, 0.0, 0.0));
glm::mat4 rotation7 = glm::rotate(glm::mat4(1.0f), 0.0f, glm::vec3(0.0, 0.0, 0.0));

void glfwErrorCB(int error, const char* description)//allows for an error check to take place
{
    fputs(description, stderr);
}

void keyboardCB(GLFWwindow* window, int key, int scancode, int action, int mods) //allows for the use of the keyboard for interactive functions
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)//closes window
        glfwSetWindowShouldClose(window, GL_TRUE);

    if (key == GLFW_KEY_T && action == GLFW_PRESS)//toggles translation 
    {
        item.toggletranslation();
    }

    if (key == GLFW_KEY_1 && action == GLFW_PRESS)//camera 1
    {      
         Projection = glm::perspective(glm::radians<float>(60.0f), 16.0f / 9.0f, 0.00001f, 100.0f);         // Use a projection matrix
         View = glm::lookAt(glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
         

    }

    if (key == GLFW_KEY_2 && action == GLFW_PRESS)//camera 2
    {
        Projection = glm::perspective(glm::radians<float>(60.0f), 16.0f / 9.0f, 0.1f, 100.0f);         // Use a projection matrix
        View = glm::lookAt(glm::vec3(0.0f, 0.0f, -3.0f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f));
                                     //Location          //point of interest          //Camera Up
    }

    if (key == GLFW_KEY_3 && action == GLFW_PRESS)//camera 3
    {
        Projection = glm::perspective(glm::radians<float>(60.0f), 16.0f / 9.0f, 0.01f, 100.0f);         // Use a projection matrix
        View = glm::lookAt(glm::vec3(0.0f, 0.0f, -8.0f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f));
                             //Location                  //point of interest          //Camera Up
    }

    if (key == GLFW_KEY_4 && action == GLFW_PRESS)//camera 4
    {
        Projection = glm::perspective(glm::radians<float>(60.0f), 16.0f / 9.0f, 0.00001f, 100.0f);         // Use a projection matrix
        View = glm::lookAt(glm::vec3(10.0f, 0.0f, -2.0f), glm::vec3(10.0f, 0.0f, -1.0f), glm::vec3(0.0f, 05.0f, 0.0f));
                           //Location                   //point of interest          //Camera Up
    }

    if (key == GLFW_KEY_5 && action == GLFW_PRESS)//camera 5
    {
        Projection = glm::perspective(glm::radians<float>(60.0f), 16.0f / 9.0f, 0.00001f, 100.0f);         // Use a projection matrix
        View = glm::lookAt(glm::vec3(10.0f, 0.0f, -10.0f), glm::vec3(10.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f));
                            //Location                  //point of interest          //Camera Up
    }

    if (key == GLFW_KEY_6 && action == GLFW_PRESS)//camera 6
    {
        Projection = glm::perspective(glm::radians<float>(60.0f), 16.0f / 9.0f, 0.00001f, 100.0f);         // Use a projection matrix
        View = glm::lookAt(glm::vec3(10.0f, 4.0f, -2.0f), glm::vec3(10.0f, .0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f));
                          //Location                     //point of interest          //Camera Up
    }

    if (key == GLFW_KEY_S && action == GLFW_PRESS)
    {
        item.togglefill();//calls to toggle each new gasket
        second.togglefill();
        third.togglefill();
        fourth.togglefill();
        fifth.togglefill();
        sixth.togglefill();
        seventh.togglefill();
    }

    if (key == GLFW_KEY_W && action == GLFW_PRESS)
    {
        item.togglewire();//calls to toggle each new gasket
        second.togglewire();
        third.togglewire();
        fourth.togglewire();
        fifth.togglewire();
        sixth.togglewire();
        seventh.togglewire();
    }

}




int main() {
    glfwWindowHint(GLFW_SAMPLES, 8); // 8x antialiasing
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL
    GLFWwindow* window;
    double mousex;
    double mousey;
    float angle = 0;

   

    Sca2 = glm::scale(glm::vec3(0.3, 0.3, 0.3));
    Sca3 = glm::scale(glm::vec3(0.5, 0.5, 0.5));
    Sca4 = glm::scale(glm::vec3(0.15, 0.15, 0.15));
    Sca5 = glm::scale(glm::vec3(0.6, 0.6, 0.6));
    Sca6 = glm::scale(glm::vec3(1.5, 1.5, 1.5));
    Sca7 = glm::scale(glm::vec3(1.2, 1.2, 1.2));
   

    
        
    glfwSetErrorCallback(glfwErrorCB);//checks the callback
    if (!glfwInit())
        exit(EXIT_FAILURE);

  
    window = glfwCreateWindow(3840, 2160, "COSC 4328 HW 3", NULL, NULL);
    if (!window)
    {
        glfwTerminate();//terminate the program
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;
    glewInit();  // start GL context and O/S window using the GLFW helper library

    std::cout << "Running OpenGL Version " << glGetString(GL_VERSION)
        << " using " << glGetString(GL_RENDERER) << "\n";
 

   
   
    item.initialize(glm::vec3(0.0,0.2,0.0));//calls initlaize function
    second.initialize(glm::vec3(0.0, 0.2, -0.15 ));
    third.initialize(glm::vec3(1.0, 0.2, 0.0));
    fourth.initialize(glm::vec3(-1.0, 0.2, 0.0)); 
    fifth.initialize(glm::vec3(0.0, 0.2, 3.0));
    sixth.initialize(glm::vec3(10.0, 0.2, 0.0));
    seventh.initialize(glm::vec3(11.0, 0.2, 0.0));

    
    bool draw = true;//sets draw
    float secondangle = 0;
    glfwSetKeyCallback(window, keyboardCB);//key call back
    glfwSetMouseButtonCallback(window, GLFW_MOUSE_BUTTON_LEFT);//allows for mouse button click


    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        
        glfwGetCursorPos(window, &mousex, &mousey);//mouse movement


        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//clear background
       
        rotation = glm::rotate(glm::mat4(1.0f), angle, glm::vec3(0.0, 1.0, 0.0));//different rotations per gasket
        rotation2 = glm::rotate(glm::mat4(1.0f), angle, glm::vec3(0.5, 1.0, 0.5));
        rotation3 = glm::rotate(glm::mat4(1.0f), angle, glm::vec3(1.0, 0.0, 0.0));
        rotation4 = glm::rotate(glm::mat4(1.0f), angle, glm::vec3(1.0, 0.0, 1.0));
        rotation5 = glm::rotate(glm::mat4(1.0f), angle, glm::vec3(1.0, 1.0, 1.0));
        rotation6 = glm::rotate(glm::mat4(1.0f), angle, glm::vec3(1.0, 0.0, 0.0));
        rotation7 = glm::rotate(glm::mat4(1.0f), angle, glm::vec3(0.01, 0.01, 0.01));
            item.Draw(Projection,View,Scales,rotation);//draws the world
            angle += 0.001;//this set controls the the angle measure so that the rotation operates
            if (angle > 360)
            {
                angle = 0;
            }
            secondangle += 0.001;//this set controls the the angle measure so that the rotation operates
            if (secondangle > 0.001)
            {
               secondangle = 0;
            }
            second.Draw(Projection,View,Sca2,rotation2);//Draw calls for each gasket

            third.Draw(Projection, View, Sca3, rotation3);
          
            fourth.Draw(Projection, View, Sca4, rotation4);

            fifth.Draw(Projection, View, Sca5, rotation5);

            sixth.Draw(Projection, View, Sca6, rotation6);

            seventh.Draw(Projection, View, Sca7, rotation7);

            glfwSwapBuffers(window);
       
        glfwPollEvents();
    }

}