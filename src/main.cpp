#include <iostream>

#include "GraphiqueEnvConfig.h"

#ifdef USE_QT
    #include <QApplication>
    #include "./window/mainwindow.h"
#else
    #include "./windowGLFW/mainwindow.h"
#endif

int main(int argc, char *argv[])
{
    if (argc < 3) {
        // report version
        std::cout << argv[0] << " Version " << GraphiqueEnv_VERSION_MAJOR << "." << GraphiqueEnv_VERSION_MINOR << std::endl;
        std::cout << "Usage: " << argv[0] << " number" << std::endl;
        std::cout << "enter ./GraphiqueEnv <version> <app>" << std::endl;
        return 1;
    }

#ifdef USE_QT
    QApplication app(argc, argv);
    MainWindow w;
    w.activate(std::stoi(argv[2]));
    w.show();
    return app.exec();
#else
    // init glfw :
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    try {
        MainWindow w;
        w.activate(std::stoi(argv[2]));
    } catch (const char* err) {
        std::cout << err << std::endl;
    }

#endif
    return 0;
}