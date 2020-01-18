#pragma once
#include "glut.h"
#include <gl/GL.h>
#include <gl/GLU.h>
#include "Input.h"
#include <stdio.h>
#include "Vector3.h"

class Camera
{
public:
	Camera();

	~Camera();

	void update();
	void calculateSinCos();
	void calculateForward();
	void calculateUp();
	void calculateLookAt();
	void calculateRight(); 

	void moveForward(float dt);
	void moveBackward(float dt);
	void moveRight(float dt); 
	void moveLeft(float dt);
	void moveUp(float dt);
	void moveDown(float dt);
	void reset(); 

	void lookUp_Down(float dt, float distance);
	void lookRight_Left(float dt, float distance);

	float getCamX(); 
	float getCamY();
	float getCamZ();
	void setCamX(float x);
	void setCamY(float y);
	void setCamZ(float z);
	float getLookatX();
	float getLookatY();
	float getLookatZ();
	float getUpX();
	float getUpY();
	float getUpZ();

protected: 
	//Camera speed movement
	float speed = 2.f;
	//Camera speed with mouse
	float speed2 = 4.f;

	Vector3 camPosition;
	Vector3 forward;
	Vector3 up;
	Vector3 LookAt;
	Vector3 right;

	float Yaw, Pitch, Roll;

	float cosR, cosP, cosY; //temp values for sin/cos from
	float sinR, sinP, sinY;

};

