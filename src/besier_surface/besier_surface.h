#ifndef BESIERSURFACE_H
#define BESIERSURFACE_H

#include "../besier_curves/besier_curves.h"
#include "../hello_triangles/hellotriangles.h"

class BesierSurface : public OpenglObject {
    public:
        explicit BesierSurface(std::vector<std::vector<glm::vec3>>& checkpoints, size_t degree_gen, size_t degree_dir);
        ~BesierSurface();

        void draw(void) override;
    protected:
    private:
        BesierCurve *_generatrice;
        BesierCurve *_directrice;

        // checkpoint for besier 
        std::vector<std::vector<glm::vec3>> _checkpoints;

        // geometry objects
        std::vector<GLfloat> _vertices;
        std::vector<GLuint>  _indices;

        SimpleTriangle *_figure;

        float Bernstein(size_t i, size_t j, float u, float v);
        //void init(void);
};

#endif