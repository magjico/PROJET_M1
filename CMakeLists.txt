cmake_minimum_required(VERSION 3.10)

# project name
project(GraphiqueEnv VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# option
option(USE_GLFW "Use GLFW provided implementation" ON)

# path
set(PATH_GLFW Libs/glfw-3.3.4)

# configure header file
configure_file(src/GraphiqueEnvConfig.h.in src/GraphiqueEnvConfig.h)

# add the librairies
if(USE_GLFW)
    add_subdirectory(${PATH_GLFW})
    list(APPEND EXTRA_LIBS ${PATH_GLFW})
    list(APPEND EXTRA_INCLUDES "${PROJECT_BINARY_DIR}/Libs/glfw-3.3.4/include")
endif()

# add the executable
add_executable(GraphiqueEnv src/main.cpp)

target_link_libraries(GraphiqueEnv PUBLIC ${EXTRA_LIBS})

# add the includes in the librairies
target_include_directories(GraphiqueEnv PUBLIC
    "${PROJECT_BINARY_DIR}"
    ${EXTRA_INCLUDES}
)





