#include "hellocubes.h"

SimpleCube::SimpleCube(std::vector<GLfloat> &vect1, std::vector<GLfloat> &vect2, std::vector<GLfloat> &origin, GLfloat length)
{
    // init geometry data
    _length = length;
    _vect_dir1  = vect1;
    _vect_dir2  = vect2;
    _cube_origin = origin;

    // init the 3rd dir vect by making a vector product between _vect_dir1 and _vect_dir2
    _vect_dir3 = cross_product(vect1, vect2);
}

SimpleCube::~SimpleCube() {}

std::vector<GLfloat> SimpleCube::get_vertices()
{

    std::vector<GLfloat> vertices = {};

    for (int i=0; i<3; i++)
    {
        _vect_dir1[i] *= _length;
        _vect_dir2[i] *= _length;
        _vect_dir3[i] *= _length; 
    }

    // [0; 2]
    for (int i=0; i<3; i++) 
        vertices.push_back(_cube_origin[i]); 

    // [3; 5] 
    for (int i=0; i<3; i++)
        vertices.push_back(_cube_origin[i] + _vect_dir1[i]);

    // [6; 8]
    for (int i=0; i<3; i++)
        vertices.push_back(_cube_origin[i] + _vect_dir2[i]);

    // [9; 11]
    for (int i=0; i<3; i++)
        vertices.push_back(_cube_origin[i] + _vect_dir3[i]);

    // [12; 14]
    for (int i=0; i<3; i++)
        vertices.push_back(vertices[i+3] + _vect_dir2[i]);

    // [15; 17]
    for (int i=0; i<3; i++)
        vertices.push_back(vertices[i+9] + _vect_dir2[i]);

    // [18; 20]
    for (int i=0; i<3; i++)
        vertices.push_back(vertices[i+3] + _vect_dir3[i]);

    // [21; 23]
    for (int i=0; i<3; i++)
        vertices.push_back(vertices[i+18] + _vect_dir2[i]);

    return vertices;
}

std::vector<GLuint> SimpleCube::get_indices()
{
    std::vector<GLuint> indices = {
        0, 1, 2,
        1, 4, 2,
        0, 1, 3,
        1, 7, 3,
        0, 2, 3,
        2, 5, 3,
        4, 1, 7,
        7, 6, 1,
        2, 4, 5,
        4, 7, 5,
        3, 5, 6,
        5, 7, 6
    };
    return indices;
}


