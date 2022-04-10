#version 330 core
layout (location = 0) in vec3 vPos;

void main(void)
{
	//gl_Position = gl_ModelViewProjectionMatrix(ici matrice diagonale) * gl_Vertex(deprecated)
	gl_Position		= vec4(vPos.x, vPos.y, vPos.z, 1.0);
}
