#ifndef SIMPLETRIANGLE_H
#define SIMPLETRIANGLE_H

#define GL_GLEXT_PROTOTYPES

#include <vector>

#include "../openglObject/openglObject.h"

class SimpleTriangle : public OpenglObject {
    public:
        explicit SimpleTriangle(std::vector<GLfloat>& vertices, std::vector<GLuint>& indices, char* shader_vertex_file, char* shader_pixel_file);
        explicit SimpleTriangle();
        ~SimpleTriangle() override;

        void draw() override;
    private:
        // geometry object 
        std::vector<GLfloat> _vertices;
        std::vector<GLuint>   _indices;

        // geometry object for the GPU
        // VAO
        GLuint _vao;
        // VBO
        GLuint _vbo;
        // normal buffer
        GLuint _nbo;
        // EBO (faces buffer object)
        GLuint _ebo;
        
        // shader 
        GLuint _vshader;
        GLuint _pshader;
        // program
        GLuint _program;

        char *shader_vertex_path;
        char *shader_pixel_path;

        void init(void);
};

#endif