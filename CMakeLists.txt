cmake_minimum_required(VERSION 3.10)

# project name
project(GraphiqueEnv VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# option
option(USE_QT "Use QT provided implementation" ON)

# path
set(PATH_GLFW lib/glfw-3.3.4)
set(PATH_QT lib/qt5-build)
set(PATH_GLM lib/glm/glm-master)

# configure header file
configure_file(src/GraphiqueEnvConfig.h.in src/GraphiqueEnvConfig.h)

# I - add the librairies

# I.1 - GLM
add_subdirectory(${PATH_GLM})
list(APPEND EXTRA_LIBS ${PATH_GLM})
list(APPEND EXTRA_INCLUDES "${PROJECT_BINARY_DIR}/lib/glm/glm-master/glm")

# I.2 - QT OR GLFW
if(USE_QT)
    find_package(Qt5 COMPONENTS Widgets REQUIRED)
    list(APPEND EXTRA_LIBS Qt5::Widgets)
    list(APPEND EXTRA_INCLUDES "${PROJECT_BINARY_DIR}/lib/qt5-build/qtbase/include")
else()
    add_subdirectory(${PATH_GLFW})
    list(APPEND EXTRA_LIBS ${PATH_GLFW})
    list(APPEND EXTRA_INCLUDES "${PROJECT_BINARY_DIR}/lib/glfw-3.3.4/include")
endif()

# II - add the executable
add_executable(GraphiqueEnv src/main.cpp)

target_link_libraries(GraphiqueEnv PUBLIC ${EXTRA_LIBS})

# III - add the includes in the librairies
target_include_directories(GraphiqueEnv PUBLIC
    "${PROJECT_BINARY_DIR}"
    ${EXTRA_INCLUDES}
)





