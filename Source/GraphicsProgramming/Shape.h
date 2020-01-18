#ifndef _SHAPE_H
#define _SHAPE_H

#include "glut.h"
#include <gl/gl.h>
#include <gl/glu.h>
#include <math.h>

class Shape
{

public:
	void render1();
	void render2();
	void render3();
	void skybox();
	void cube();

	void createDisc(int resolution);
	void disc();
	void createSphere(int resoltion);

	void plane(int w, int h);

protected: 
	int m_resolution; 
	float *discVerts = NULL;
	float *discNorms = NULL;
	float *discTex = NULL;

	float *sphereVerts = NULL; 
	float *sphereNorms = NULL; 
	float *sphereTex = NULL; 
};
#endif 
