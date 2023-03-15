#ifndef HELLOCUBES_H
#define HELLOCUBES_H

#include <vector>

#include "../basic_function/basic.h"

class SimpleCube {
    public:
        explicit SimpleCube(std::vector<GLfloat> &vect1, std::vector<GLfloat> &vect2, std::vector<GLfloat> &origin, GLfloat length);
        ~SimpleCube();

        std::vector<GLfloat> get_vertices();
        std::vector<GLuint> get_indices();

    private:
        std::vector<GLfloat> _vect_dir1;
        std::vector<GLfloat> _vect_dir2;
        std::vector<GLfloat> _cube_origin;

        std::vector<GLfloat> _vect_dir3;

        GLfloat _length;      
};

#endif