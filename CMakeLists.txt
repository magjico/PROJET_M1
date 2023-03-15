cmake_minimum_required(VERSION 3.14)

# project name
project(GraphiqueEnv VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS ON)

find_package(OpenGL REQUIRED)

# options
option(USE_QT "Use QT provided implementation" OFF)

# path
set(PATH_GLFW   "${CMAKE_SOURCE_DIR}/lib/glfw-3.3.4")
set(PATH_QT     "${CMAKE_SOURCE_DIR}/lib/qt5-build")
set(PATH_GLAD   "${CMAKE_SOURCE_DIR}/lib/glad")
set(PATH_ASSIMP "${CMAKE_SOURCE_DIR}/lib/assimp")

# configure header file
configure_file(src/GraphiqueEnvConfig.h.in src/GraphiqueEnvConfig.h)

# I - add the librairies
if(USE_QT)
    find_package(Qt5 COMPONENTS Widgets OpenGL Gui REQUIRED)
    list(APPEND EXTRA_LIBS Qt5::OpenGL)
    list(APPEND EXTRA_LIBS Qt5::Widgets)
    list(APPEND EXTRA_LIBS Qt5::Gui)
else()
    add_subdirectory(${PATH_GLAD})

    list(APPEND EXTRA_LIBS glad)

    # GLFW
    add_subdirectory(${PATH_GLFW})
    
    list(APPEND EXTRA_LIBS glfw)

    set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
    set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
    set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
endif()

# ASSIMP
# add_subdirectory(${PATH_ASSIMP})
# list(APPEND EXTRA_LIBS assimp)

FILE(GLOB_RECURSE
    folder_source
    ${CMAKE_SOURCE_DIR}/src/*.cpp
)

FILE(GLOB_RECURSE
    folder_header
    ${CMAKE_SOURCE_DIR}/src/*.h
)

include_directories(
    ${CMAKE_SOURCE_DIR}/src
    ${PROJECT_BINARY_DIR}/lib/glm/glm-master/glm
)

SOURCE_GROUP("Source File" FILES ${folder_source})
SOURCE_GROUP("Header File" FILES ${folder_header})

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(GraphiqueEnv
    ${folder_source}
    ${glad_source}
    ${folder_header}
    ${glad_header})

target_link_libraries(GraphiqueEnv ${EXTRA_LIBS} ${OPENGL_LIBRARIES})