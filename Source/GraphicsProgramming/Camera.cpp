#include "Camera.h"

//Declaring camera varibles 
Camera::Camera()
{ 
	camPosition.x = 0;
	camPosition.y = 5;
	camPosition.z = 5;
	Yaw = 0;
	Pitch = 0; 
	Roll = 0; 
	up.y = 1;
}

Camera::~Camera()
{
}

void Camera::update()
{
}

void Camera::calculateSinCos()
{
	cosY = cosf(Yaw*3.1415 / 180);
	cosP = cosf(Pitch*3.1415 / 180);
	cosR = cosf(Roll*3.1415 / 180);
	sinY = sinf(Yaw*3.1415 / 180);
	sinP = sinf(Pitch*3.1415 / 180);
	sinR = sinf(Roll*3.1415 / 180);
}

void Camera::calculateForward()
{
	forward.x = sinY * cosP;
	forward.y = sinP;
	forward.z = cosP * -cosY;
}

void Camera::calculateUp()
{
	up.x = -cosY * sinR - sinY * sinP * cosR;
	up.y = cosP * cosR;
	up.z = -sinY * sinR - sinP * cosR * -cosY;
}

void Camera::calculateLookAt()
{
	LookAt.x = forward.x + camPosition.x;
	LookAt.y = forward.y + camPosition.y;
	LookAt.z = forward.z + camPosition.z;
}

void Camera::calculateRight()
{
	right = forward.cross(up);
}

//Calls functions only when input is detected to save resources 
void Camera::moveForward(float dt)
{
	calculateSinCos();
	calculateForward();
	Vector3 temp = forward;
	temp.scale(speed * dt);
	camPosition += temp;
}

void Camera::moveBackward(float dt)
{
	calculateSinCos();
	calculateForward();
	Vector3 temp = forward;
	temp.scale(speed * dt);
	camPosition -= temp;
}

void Camera::moveRight(float dt)
{
	calculateSinCos();
	calculateForward();
	calculateRight();
	Vector3 temp = right;
	temp.scale(speed * dt);
	camPosition += temp; 
}

void Camera::moveLeft(float dt)
{
	calculateSinCos();
	calculateForward();
	calculateRight();
	Vector3 temp = right;
	temp.scale(speed * dt);
	camPosition -= temp;
}

void Camera::moveUp(float dt)
{
	camPosition.y += speed * dt;
}

void Camera::moveDown(float dt)
{
	camPosition.y -= speed * dt;
}

//Resets camera to a default position
void Camera::reset()
{
	camPosition.x = 0; 
	camPosition.y = 0;
	camPosition.z = 6;

	Yaw = 0; 
	Pitch = 0; 
	Roll = 0; 
}


void Camera::lookUp_Down(float dt, float distance)
{
	Pitch -= distance * speed2 * dt;
}

void Camera::lookRight_Left(float dt, float distance)
{
	Yaw += distance * speed2 * dt;
}


float Camera::getCamX()
{
	return camPosition.getX(); 
}

float Camera::getCamY()
{
	return camPosition.getY();
}

float Camera::getCamZ()
{
	return camPosition.getZ();
}

void Camera::setCamX(float x)
{
	this->camPosition.setX(x);
}

void Camera::setCamY(float y)
{
	this->camPosition.setY(y);
}

void Camera::setCamZ(float z)
{
	this->camPosition.setZ(z);
}

float Camera::getLookatX()
{
	calculateSinCos();
	calculateForward();
	calculateLookAt();
	return LookAt.getX();
}

float Camera::getLookatY()
{
	calculateSinCos();
	calculateForward();
	calculateLookAt();
	return LookAt.getY();
}

float Camera::getLookatZ()
{
	calculateSinCos();
	calculateForward();
	calculateLookAt();
	return LookAt.getZ();
}

float Camera::getUpX()
{
	calculateSinCos();
	calculateUp();
	return up.getX();
}

float Camera::getUpY()
{
	calculateSinCos();
	calculateUp();
	return up.getY();
}

float Camera::getUpZ()
{
	calculateSinCos();
	calculateUp();
	return up.getZ();
}