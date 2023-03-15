#include <iostream>

#include "basic.h"

char* LoadSource(const char *filename)
{
    char *src = NULL;
    FILE *fp  = NULL;
    size_t size;
    
    /* ouverture du fichier */
    fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "impossible d'ouvrir le fichier %s\n", filename);
        return NULL;
    }

    /* On récupère la longueur du fichier */
    fseek(fp, 0, SEEK_END);
    size = ftell(fp);

    /* On se replace au début du fichier */
    rewind(fp);

    /* On alloue la mémoire pour src */
    src = (char *)malloc((size+1)*sizeof(char));
    if(src == NULL) {
        fclose(fp);
        fprintf(stderr, "erreur d'allocution de la memoire\n");
        return NULL;
    }

    /* Lecture du fichier et écriture de src */
    for(size_t i=0; i<size; i++)
        src[i] = fgetc(fp);
    src[size] = '\0';

    /* fermeture du fichier */
    fclose(fp);

    return src;
}

// Crossed-product 
std::vector<GLfloat> cross_product(std::vector<GLfloat> &vect1, std::vector<GLfloat> &vect2)
{
    std::vector<GLfloat> crossed_vect = {};

    if (vect1.size() != 3 || vect2.size() != 3) {
        std::cerr << "try to do a cross-product with vector of size not equal at 3" << std::endl;
        exit(1);
    }

    crossed_vect.push_back(GLfloat(vect1.at(1) * vect2.at(2) - vect2.at(1) * vect2.at(2)));
    crossed_vect.push_back(GLfloat(vect1.at(2) * vect2.at(0) - vect2.at(2) * vect1.at(0)));
    crossed_vect.push_back(GLfloat(vect1.at(0) * vect2.at(1) - vect2.at(0) * vect1.at(1)));
    
    return crossed_vect;
}