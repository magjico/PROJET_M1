#include <iostream>

#include "GraphiqueEnvConfig.h"

#ifdef USE_QT
    #include <QtWidgets>
#else
    #include <GLFW/glfw3.h>
#endif

int main(int argc, char *argv[])
{
    if (argc < 2) {
        // report version
        std::cout << argv[0] << " Version " << GraphiqueEnv_VERSION_MAJOR << "." << GraphiqueEnv_VERSION_MINOR << std::endl;
        std::cout << "Usage: " << argv[0] << " number" << std::endl;
        return 1;
    }
    std::cout << "Hello Window" << std::endl;
#ifdef USE_QT
    QApplication app(argc, argv);
    // Recuperer la taille de l'ecran.
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();
    // Building de l'ecran
    QWidget window;
    window.resize(width, height);
    window.show();
    window.setWindowTitle(
        QApplication::translate("toplevel", "Top-level widget")
    );
    return app.exec();
#else
#endif
    return 0;
}