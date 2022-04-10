#include "besier_surface.h"

#include <iostream>

BesierSurface::BesierSurface(std::vector<std::vector<glm::vec3>>& checkpoints, size_t len_row, size_t len_column) : OpenglObject()
{
    _checkpoints = checkpoints;

    // create the 2 Besier curves with uniform nodal vector Ui+1 - Ui = cste (here = 1/(_checkpoint_size+degree))
    _generatrice = new BesierCurve(_checkpoints.size());
    _directrice  = new BesierCurve(_checkpoints[0].size());

    // calculate vertices
    GLfloat u_row;
    GLfloat v_column;
    glm::vec3 temp;
    for (size_t i=0; i<len_row; i++) {
        for (size_t j=0; j<len_column; j++) {
            v_column    = float(j) / float(len_column - 1);
        
            temp  = glm::vec3(0.f);

            u_row = float(i) / float(len_row - 1);

            for (size_t ui=0; ui<_checkpoints.size(); ui++)
                for (size_t vi=0; vi<_checkpoints[0].size(); vi++)
                    temp += Bernstein(ui, vi, u_row, v_column)*_checkpoints[ui][vi]; 

            _vertices.push_back(temp.x);
            _vertices.push_back(temp.y);
            _vertices.push_back(temp.z);
        }
    }


    // calculate indices
    for (size_t i=0; i<len_row-1; i++) {
        for (size_t j=0; j<len_column-1; j++) {
            _indices.push_back(i*len_column+j);
            _indices.push_back(i*len_column+j+1);
            _indices.push_back((i+1)*len_column+j+1);

            _indices.push_back(i*len_column+j);
            _indices.push_back((i+1)*len_column+j+1);
            _indices.push_back((i+1)*len_column+j);
        }
    }

    _figure = new SimpleTriangle(_vertices, _indices);
}

BesierSurface::~BesierSurface(){}

GLfloat BesierSurface::Bernstein(size_t i, size_t j, float u, float v)
{
    return (_generatrice->Bernstein(i, u) * _directrice->Bernstein(j, v));
}

void BesierSurface::draw(void)
{
    _figure->draw();
}