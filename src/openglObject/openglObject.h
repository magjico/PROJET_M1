#ifndef OPENGLOBJECT_H
#define OPENGLOBJECT_H

#include <vector>
#include <glad/glad.h>

#include "../basic_function/basic.h"

class OpenglObject {
    public :
        explicit OpenglObject();
        virtual ~OpenglObject();

        virtual void draw();

    protected:
        GLuint loadShader(GLenum type, const char *filename);
        int loadProgram(GLuint program);

};

#endif