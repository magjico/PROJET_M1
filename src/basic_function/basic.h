#ifndef BASIC_H
#define BASIC_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <glad/glad.h>

char* LoadSource(const char *filename);
std::vector<GLfloat> cross_product(std::vector<GLfloat> &vect1, std::vector<GLfloat> &vect2);
char* assign_string(char *string);

#endif