#include <iostream>
#include <cstring>

#include <glad/glad.h>

#include "openglObject.h"

OpenglObject::OpenglObject(){}

OpenglObject::~OpenglObject(){}

void OpenglObject::draw()
{
    // render
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

GLuint OpenglObject::loadShader(GLenum type, const char *filename)
{
    // 1 - the shader, shader data and log for error management
    GLuint shader; 
    GLint shader_compile_status = GL_TRUE;
    GLsizei logsize = 0;
    char *src = NULL;
    char *log = NULL;
    
    // 2 - Initialise the shader
    shader = glCreateShader(type);

    // 3 - bind the shader
    if ((src = LoadSource(filename)) == NULL) {
        glDeleteShader(shader);
        std::cout << "invalide shader" << std::endl;
        return -1;
    }
    glShaderSource(shader, 1, (const GLchar**)&src, NULL);


    /* 
        4.1 - compile the shader and
        free src memories
    */
    glCompileShader(shader);
    free(src); src=NULL;

    // 4.2 - verification of the shader's compilation
    glGetShaderiv(shader, GL_COMPILE_STATUS, &shader_compile_status);
    if (shader_compile_status != GL_TRUE) {
        std::cerr << "bad shader compilation" << std::endl;

        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logsize);
        log = (char *)malloc((logsize + 1)*sizeof(char));
 
        if (log == NULL) {
            std::cerr << "memory allocution problem" << std::endl;
            return -1;
        }
        memset(log, '\0', logsize+1);

        glGetShaderInfoLog(shader, logsize, &logsize, log);
        std::cerr << "err in shader compilation:" << std::endl
        << "\tfile: " << filename << std::endl
        << "\terr:" << log << std::endl;

        free(log);
        glDeleteShader(shader);  

        return -1;
    }
    return shader;
}

int OpenglObject::loadProgram(GLuint program)
{
    // 1 - the log for error management
    GLint program_linking_status = GL_TRUE;
    GLsizei logsize = 0;
    char *log = NULL;

    // 2 - linking
    glLinkProgram(program);

    // 3 - verification of the program linking
    glGetProgramiv(program, GL_LINK_STATUS, &program_linking_status);
    if (program_linking_status != GL_TRUE) {
        std::cerr << "bad program linking" << std::endl;

        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logsize);
        log = (char *)malloc((logsize + 1)*sizeof(char));

        if (log == NULL) {
            std::cerr << "memory allocution problem" << std::endl;
            return 0;
        }
        memset(log, '\0', logsize+1);

        glGetProgramInfoLog(program, logsize, &logsize, log);
        std::cerr << "err in program linking:" << std::endl
        << log << std::endl;

        free(log);
        
        return 0;
    }
    return 1;
}