#include <iostream>

#include "GraphiqueEnvConfig.h.in"

#ifdef USE_GLFW
#   include <GLFW/glfw3.h>
#endif

const double inputValue = std::stod(argv[1]);

int main(int argc, char *argv[])
{
    if (argc < 2) {
        // report version
        std::cout << argv[0] << " Version " << GraphiqueEnv_VERSION_MAJOR << "." << GraphiqueEnv_VERSION_MINOR << std::endl;
        std::cout << "Usage: " << argv[0] << " number" << std::endl;
        return 1;
    }
    std::cout << "Hello Compilation\n";
    return 0;
}