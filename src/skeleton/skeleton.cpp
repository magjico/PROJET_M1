#include "skeleton.h"

/*-----------------------------------------------------------------------------------------------------------------------*/
/* - JOINT - */
struct joint *newJoint(GLfloat x, GLfloat y, GLfloat z)
{
    struct joint *newJoint = (struct joint *)malloc(sizeof(struct joint));
    newJoint->x = x;
    newJoint->y = y;
    newJoint->z = z;
    newJoint->childs = NULL;
    newJoint->number_of_child = 0;
    return newJoint;
}

void getChildsNumbers(struct joint *j)
{
    return j->number_of_child;
}

struct joint *getChildFromIndex(struct joint *mother, size_t index)
{
    return mother->childs[index];
}

void changeJointPosition(struct joint j, GLfloat new_x, GLfloat new_y, GLfloat new_z)
{
    j->x = new_x;
    j->y = new_y;
    j->z = new_z;
}

void add_children(struct joint *mother, struct joint *child)
{
    mother->number_of_child++;
    mother->childs = (struct **joint)realloc(mother->childs, mother->number_of_child * sizeof(struct *joint));
    mother->childs[mother->number_of_child] = child;
}

void add_childs(struct joint *mother, struct joint **childs, size_t number_of_childs)
{
    mother->childs = (struct **joint)realloc(mother->childs, (mother->number_of_child + number_of_childs) * sizeof(struct *joint));
    for (size_t i=0; i<number_of_childs; i++)
        mother->number_of_child[mother->number_of_child + i] = childs[i];
    mother->number_of_child += number_of_childs;
}

/*-----------------------------------------------------------------------------------------------------------------------*/
/* - Skeleton - */
Skeleton::Skeleton(joint *j, std::vector<GLfloat> vertices, size_t nbr_vertices, char* shader_vertex_file, char* shader_pixel_file)
{
    root = j;
    _vertices = vertices;
    _nbr_vertices = nbr_vertices;

    shader_vertex_path  = shader_vertex_file;
    shader_pixel_path   = shader_pixel_file;

    init();
}

Skeleton::~Skeleton()
{
    glDeleteShader(_vshader);
    glDeleteShader(_pshader);

    glDeleteVertexArrays(1, &_vao);
    glDeleteBuffers(1, &_vbo);
    glDeleteBuffers(1, &_ebo);
    glDeleteBuffers(1, &_nbo);
    glDeleteProgram(_program);
}

void Skeleton::draw()
{
    OpenglObject::draw();

    // draw the triangle
    glUseProgram(_program);
    glBindVertexArray(_vao);

    //glDrawArrays(GL_TRIANGLES, 0, 3);
    glDrawElements(GL_TRIANGLES, _indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

void Skeleton::init_influence()
{
    for (size_t i=0; i<_nbr_vertices; i++)
    {
    
    }
}

void Skeleton::init()
{
    // 2.1 - Initialise GPU geometric data
    glGenBuffers(1, &_vbo);
    glGenBuffers(1, &_ebo);
    //glGenBuffers(1, &_nbo);
    glGenVertexArrays(1, &_vao);

    // 2.2 - Initialize program data
    _program = glCreateProgram();

    /*
        3 - configure the interpretation of openGL and 
        the method of sending it to the graphics card
    */

    // 3.1 - bind the buffers (glBindX)
    // 3.2 - make copies of the data previously defined into the buffers memories (glBufferData)
    glBindVertexArray(_vao);

    glBindBuffer(GL_ARRAY_BUFFER, _vbo);
    glBufferData(GL_ARRAY_BUFFER, _vertices.size()*sizeof(GLfloat), _vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, _indices.size()*sizeof(GLfloat), _indices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    /* ------------- Skeleton ------------- */
    // ids
    glEnableVertexAttribArray(1);
    glVertexAttribIPointer(1, MAX_BONE_INFLUENCE, GL_INT, _vertices.size()*MAX_BONE_INFLUENCE*sizeof(GLint), (void *)m_BoneIDs);

    // weights
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, MAX_BONE_INFLUENCE, GL_FLOAT, _vertices.size()*MAX_BONE_INFLUENCE*sizeof(GLfloat), (void *)m_Weights);
    /* ------------------------------------ */

    // 3.3 - unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    // 4 - bind the shaders
    _vshader = loadShader(GL_VERTEX_SHADER,  shader_vertex_path);
    if (_vshader == -1)
        throw "bad vertex shader load";
    _pshader = loadShader(GL_FRAGMENT_SHADER, shader_pixel_path);
    if(_pshader == -1)
        throw "bad fragment shader load";
    
    // 5.1 - bind the shaders to our program
    glAttachShader(_program, _vshader);
    glAttachShader(_program, _pshader);

    // 5.2 - program linking
    if (! loadProgram(_program)){
        glDeleteProgram(_program);
        throw "bad program load";
    }
    
    // 6 - Use the program (make it actif)
    glUseProgram(_program);
    glBindVertexArray(_vao); 
}

