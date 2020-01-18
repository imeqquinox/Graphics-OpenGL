#include "Lighting.h"



Lighting::Lighting()
{
}


Lighting::~Lighting()
{
}

//Spotlight for lamp
void Lighting::spotLight()
{
	GLfloat Light_Ambient[] = { 0.4f, 0.4f, 0.4f, 1.0f };
	GLfloat Light_Diffuse[] = { 1.0f, 0.0f, 0.0f, 1.0f };
	GLfloat Light_Position[] = { 0.0f, 2.0f, 0.0f, 1.0f };
	GLfloat spot_Direction[] = { 0.0f, -1.0f, 0.0f };

	glLightfv(GL_LIGHT1, GL_AMBIENT, Light_Ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Light_Diffuse);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 60.0f);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_Direction);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 5000.0);
	glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 1.0);
	glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.1);
	glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.1);
	glLightfv(GL_LIGHT1, GL_POSITION, Light_Position);
}

//Spotlight for tower 
void Lighting::spotLight2()
{
	GLfloat Light_Ambient2[] = { 0.4f, 0.4f, 0.4f, 1.0f };
	GLfloat Light_Diffuse2[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat Light_Position2[] = { 0.0f, 5.0f, 0.0f, 1.0f };
	GLfloat spot_Direction2[] = { 0.0f, -1.0f, 1.0f };

	glLightfv(GL_LIGHT2, GL_AMBIENT, Light_Ambient2);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, Light_Diffuse2);
	glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 40.0f);
	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, spot_Direction2);
	glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 10.0);
	glLightfv(GL_LIGHT2, GL_POSITION, Light_Position2);
}

//Directionlight 
void Lighting::directionalLight()
{
	GLfloat Light_Ambient1[] = { 0.4f, 0.4f, 0.4f, 1.0f };
	GLfloat Light_Diffuse1[] = { 0.8f, 0.3f, 0.2f, 1.0f };
	GLfloat Light_Position1[] = { 25.0f, 25.0f, 25.0f, 0.0f };
	GLfloat Light_Specular1[] = { 1.0, 1.0, 1.0, 1.0 };

	glLightfv(GL_LIGHT0, GL_AMBIENT, Light_Ambient1);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, Light_Diffuse1);
	glLightfv(GL_LIGHT0, GL_SPECULAR, Light_Specular1);
	glLightfv(GL_LIGHT0, GL_POSITION, Light_Position1);
}


