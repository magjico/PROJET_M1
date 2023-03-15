#ifndef LIGHTNING_SOURCES_H
#define LIGHTNING_SOURCES_H

#include <vector>
#include <glad/glad.h>

class LightningSource {
    public:
        explicit LightningSource(GLuint VBO);
        ~LightningSource();

        void init();
    protected:
    private:
        GLuint _lightVAO;
        GLuint _lightVBO;
}

#endif