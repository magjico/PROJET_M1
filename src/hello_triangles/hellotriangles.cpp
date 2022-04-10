#include <iostream>
#include <string.h>

#include "hellotriangles.h"

const char * shader_vertex_file   = "./shader/hello_triangle_vshader.vert";
const char * shader_pixel_file    = "./shader/hello_triangle_pshader.frag";

SimpleTriangle::SimpleTriangle(std::vector<GLfloat>& vertices, std::vector<GLuint>& indices) : OpenglObject()
{
    // 1.1 - Initialise geometric data
    _vertices = vertices;
    _indices  = indices;

    init();
}

SimpleTriangle::SimpleTriangle() : OpenglObject()
{

    std::cout << "DEMO SimpleTriangle" << std::endl;

    // 1.1 - Initialise geometric data
    _vertices = {
         0.5f,  0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        -0.5f,  0.5f, 0.0f
    };

    _indices = {
        0, 1, 3,
        1, 2, 3
    };
    
    init();
}

SimpleTriangle::~SimpleTriangle()
{
    glDeleteVertexArrays(1, &_vao);
    glDeleteBuffers(1, &_vbo);
    glDeleteBuffers(1, &_ebo);
    glDeleteBuffers(1, &_nbo);
    glDeleteProgram(_program);
}

void SimpleTriangle::draw(void)
{
    OpenglObject::draw();

    // draw the triangle
    glUseProgram(_program);
    glBindVertexArray(_vao);
    //glDrawArrays(GL_TRIANGLES, 0, 3);
    glDrawElements(GL_TRIANGLES, _indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

void SimpleTriangle::init(void)
{
    // 2.1 - Initialise GPU geometric data
    glGenBuffers(1, &_vbo);
    glGenBuffers(1, &_ebo);
    //glGenBuffers(1, &_nbo);
    glGenVertexArrays(1, &_vao);

    // 2.2 - Initialize program data
    _program = glCreateProgram();

    /*
        3 - configure the interpretation of openGL and 
        the method of sending it to the graphics card
    */

    // 3.1 - bind the buffers (glBindX)
    // 3.2 - make copies of the data previously defined into the buffers memories (glBufferData)
    glBindVertexArray(_vao);

    glBindBuffer(GL_ARRAY_BUFFER, _vbo);
    glBufferData(GL_ARRAY_BUFFER, _vertices.size()*sizeof(GLfloat), _vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, _indices.size()*sizeof(GLfloat), _indices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // 3.3 - unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);


    // 4 - bind the shaders
    _vshader = loadShader(GL_VERTEX_SHADER,  shader_vertex_file);
    if (_vshader == -1)
        throw "bad vertex shader load";
    _pshader = loadShader(GL_FRAGMENT_SHADER, shader_pixel_file);
    if(_pshader == -1)
        throw "bad fragment shader load";
    
    // 5.1 - bind the shaders to our program
    glAttachShader(_program, _vshader);
    glAttachShader(_program, _pshader);

    // 5.2 - program linking
    if (! loadProgram(_program)){
        glDeleteProgram(_program);
        throw "bad program load";
    }
    
    // 5.3 - We can now delete the shader if we don't modify them anymore
    glDeleteShader(_vshader);
    glDeleteShader(_pshader);
    
    // 6 - Use the program (make it actif)
    glUseProgram(_program);
    glBindVertexArray(_vao); 
}