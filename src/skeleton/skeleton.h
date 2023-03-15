#ifndef SKELETON_H
#define SKELETON_H

#include <stdlib.h>
#include <glad/glad.h>

#include<iostream>
#include<vector>

#include "../openglObject/openglObject.h"

#define MAX_BONE_INFLUENCE 2
#define MAX_BONES = 100 

struct joint {
    GLfloat x;
    GLfloat y;
    GLfloat z;
    struct joint **childs; // array of childs pointer
    size_t number_of_child; 
};

struct joint *newJoint(GLfloat x, GLfloat y, GLfloat z);

void getChildsNumbers(struct joint *j);

struct joint *getChildFromIndex(struct joint *mother, size_t index);

void changeJointPosition(struct joint j, GLfloat new_x, GLfloat new_y, GLfloat new_z);

void add_children(struct joint *mother, struct joint *child);

void add_childs(struct joint *mother, struct joint **childs, size_t number_of_childs);

class Skeleton : OpenglObject {
    public:
        explicit Skeleton(joint *j, std::vector<GLfloat> vertices, size_t nbr_vertices, char* shader_vertex_file, char* shader_pixel_file);
        ~Skeleton();

        void draw() override;
        
    private:
        struct joint *root;

        // vertices linked to the skeleton
        std::vector<GLfloat> _vertices;
        size_t _nbr_vertices;

        //bones indexes which will influence vertices
        int *m_BoneIDs[MAX_BONE_INFLUENCE];
        //weights from each bones
        float *m_Weights[MAX_BONE_INFLUENCE];

        // geometry object for the GPU
        // VAO
        GLuint _vao;
        // VBO
        GLuint _vbo;
        // normal buffer
        GLuint _nbo;
        // EBO (faces buffer object)
        GLuint _ebo;
        
        // shader 
        GLuint _vshader;
        GLuint _pshader;
        // program
        GLuint _program;

        char *shader_vertex_path;
        char *shader_pixel_path;

        void init_influence(void);
        void init(void);
}

#endif