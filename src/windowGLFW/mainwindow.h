#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// #include "../openglObject/openglObject.h"
// #include "../hello_triangles/hellotriangles.h"
#include "../besier_surface/besier_surface.h"
#include "../hello_cubes/hellocubes.h"

#include <GLFW/glfw3.h>

class MainWindow {
    public :
        explicit MainWindow();
        ~MainWindow();

        int activate(unsigned int numdemo);
        void draw(OpenglObject* obj);
        
    private :
        GLFWwindow* window;
        int width;
        int height;
};

#endif