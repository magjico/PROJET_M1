#include "lightning_sources.h"

LightningSource::LightningSource(GLuint VBO)
{
    _lightVBO = VBO;
}

LightningSource::~LightningSource()
{
    glDeleteVertexArrays(1, &_lightVAO);
}

void LightningSource::init()
{
    glGenVertexArrays(1, &_lightVAO);
    glBindVertexArray(_lightVAO);

    glBindBuffer(GL_ARRAY_BUFFER, _lightVBO);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}