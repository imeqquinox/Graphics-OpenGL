// Scene class. Configures a basic 3D scene.
// Interfaces with the Input class to handle user input
// Calculates and outputs Frames Per Second (FPS) rendered.
// Important functions are the constructor (initialising the scene), 
// update (for process user input and updating scene objects) and render (renders scene).
#ifndef _SCENE_H
#define _SCENE_H

// Include GLUT, openGL, input.
#include "glut.h"
#include <gl/GL.h>
#include <gl/GLU.h>
#include "Input.h"
#include <stdio.h>
// Further includes should go here:
#include "SOIL.h"
#include <vector>
#include "Camera.h"
#include "Shape.h"
#include "Model.h"
#include "Lighting.h"
#include "Shadow.h"

class Scene{

public:
	Scene(Input *in);
	// Main render function
	void render();
	// Update function receives delta time from parent (used for frame independent updating).
	void update(float dt);
	// Resizes the OpenGL output based on new window size.
	void resize(int w, int h);

protected:
	// Renders text (x, y positions, RGB colour of text, string of text to be rendered)
	void displayText(float x, float y, float r, float g, float b, char* string);
	// A function to collate all text output in a single location
	void renderTextOutput();
	void calculateFPS();

	// draw primitive functions

	// For access to user input.
	Input* input;

	//Cameras
	Camera camera1; 
	Camera camera2;
	Camera camera3;
	Camera camera4;
	Camera currentCam;

	//Shape 
	Shape shape;

	//Models
	Model tower; 
	Model Lamp; 
	Model wall; 
	Model wall1;
	Model wall2; 

	//Light 
	Lighting light; 
	
	//Shadow
	Shadow shadow; 

	// For Window and frustum calculation.
	int width, height;
	float fov, nearPlane, farPlane;

	// For FPS counter and mouse coordinate output.
	int frame = 0, time, timebase = 0;
	char fps[40];
	char mouseText[40];
	char cameraKeys[40] = "Main Camera: N, Reset: P";

	//Varibles
	float rotation; 
	float speed = 5;

	//Used for main camera looking with mouse
	float distanceX, distanceY;

	//Bools for switchs
	bool pressed = false; 
	bool lightPressed = false; 
	bool night = false; 
	bool camera1True = true; 
	bool camera2True;
	bool camera3True;
	bool camera4True; 

	//Textures
	GLuint shield; 
	GLuint gravel;
	GLuint skybox;
	GLuint crate;
	GLuint floor;
	GLuint window;

	//Light position for shadows
	float lightPosition[4] = { 25.0f, 25.0f, 25.0f, 0.0f }; 
	
};

#endif