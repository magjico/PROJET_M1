#version 430 core

layout(location = 0) in vec3 pos;
layout(location = 1) in vec4 boneIds;
layout(location = 2) in vec4 weights;

const int MAX_BONES = 100;          // max number of bones
const int MAX_BONES_INFLUENCE = 2;  // max number of bones able to influence a single vertex

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;
uniform mat4 bones[MAX_BONES];

void main()
{
    vec4 totalposition = vec4(0.0f);
    for(int i=0; i<MAX_BONES_INFLUENCE; i++)
    {
        if(boneIds[i]==-1)
            continue;
        if(boneIds[i] >= MAX_BONES)
        {
            totalposition = vec4(pos,1.0f);
            break;
        }
        vec4 localPosition = bones[[boneIds[i]]] * vec4(pos,1.0f);
        totalposition += localPosition * weights[i];
    }

    gl_Position = projection * view * model * totalposition;
}