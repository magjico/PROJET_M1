#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// #include "../openglObject/openglObject.h"
// #include "../hello_triangles/hellotriangles.h"
#include "../besier_surface/besier_surface.h"
#include "../hello_cubes/hellocubes.h"

#include <GLFW/glfw3.h>

class MainWindow {
    public :
        explicit MainWindow(float *amb);
        ~MainWindow();

        int activate(unsigned int numdemo);
        void draw(OpenglObject* obj);
        void MainWindow::draw(OpenglObject* obj, float *lightcolor, float *objcolor);
        
    private :
        GLFWwindow* window;
        int width;
        int height;
        float *ambiant;
};

#endif