#ifndef BESIERCURVES_H
#define BESIERCURVES_H

#include <vector>
#include <glm/glm.hpp>
#include <glad/glad.h>

class BesierCurve {
    public :
        explicit BesierCurve(size_t checkpoint_size);
        ~BesierCurve();

        //std::vector<GLfloat> _nodalvector;

        bool verifpoly(void);
        float Bernstein(size_t i, float u);
    protected :
    private :
        size_t _checkpoints_size;
        size_t *pascal_line;
        
        void pascalLine(void);
};

#endif