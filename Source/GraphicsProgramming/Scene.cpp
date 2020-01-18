#include "Scene.h"

Scene::Scene(Input *in)
{
	// Store pointer for input class
	input = in;

	//OpenGL settings
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.39f, 0.58f, 93.0f, 1.0f);			// Cornflour Blue Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glClearStencil(0);									// Clear stencil buffer
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations

	// Other OpenGL / render setting should be applied here.
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_COLOR_MATERIAL);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	// Initialise variables
	camera2.setCamX(-10);
	camera2.setCamY(15);
	camera2.setCamZ(10);

	camera3.setCamX(35); 
	camera3.setCamY(15);
	camera3.setCamZ(-10);

	camera4.setCamX(65);
	camera4.setCamY(15);
	camera4.setCamZ(-40);

	//Texture loading 
	shield = SOIL_load_OGL_texture
	(
		"gfx/shield.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	//Testing if the texture works 
	if (shield == 0)
	{
		MessageBox(NULL, "Texture failed to load", "Failure", MB_OK);
	}

	gravel = SOIL_load_OGL_texture
	(
		"gfx/gravel.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	floor = SOIL_load_OGL_texture
	(
		"gfx/floor.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	skybox = SOIL_load_OGL_texture
	(
		"gfx/skybox.jpg",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	crate = SOIL_load_OGL_texture
	(
		"gfx/crate.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	window = SOIL_load_OGL_texture
	(
		"gfx/transparentCrate.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);
	
	//Model loading 
	Lamp.load("models/StreetLamp.obj", "gfx/LightPole3.png");
	wall.load("models/oldWall.obj", "gfx/texture.jpg");
	tower.load("models/tower.obj", "gfx/texture.jpg");
	wall1.load("models/wall.obj", "gfx/concrite.png");
	wall2.load("models/wall2.obj", "gfx/concrete.jpg");
}

void Scene::update(float dt)
{
	// Handle user input
	//Fix the mouse to the centre of the screen
	glutWarpPointer(400, 300);

	//Wireframe button (O)
	if (input->isKeyDown('o'))
	{
		pressed = !pressed;
		input->SetKeyUp('o');
	}

	//Wireframe switch
	if (pressed)
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}

	if (!pressed)
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}

	//Camera 2 (M)
	if (input->isKeyDown('m'))
	{
		camera2True = true; 
		camera1True = false;
		camera3True = false;
		camera4True = false;
		input->SetKeyUp('m');
	}

	//Camera 1 (N)
	if (input->isKeyDown('n'))
	{
		camera2True = false;
		camera1True = true;
		camera3True = false;
		camera4True = false;
		input->SetKeyUp('n');
	}

	//Camera 3 (B)
	if (input->isKeyDown('b'))
	{
		camera3True = true; 
		camera2True = false; 
		camera1True = false; 
		camera4True = false;
		input->SetKeyUp('b');
	}

	//Camera 4 (V)
	if (input->isKeyDown('v'))
	{
		camera4True = true;
		camera3True = false;
		camera2True = false;
		camera1True = false;
		input->SetKeyUp('v');
	}

	//Light Switch
	if (input->isKeyDown('g'))
	{
		lightPressed = !lightPressed; 
		
		input->SetKeyUp('g');
	}

	//Light Switch
	if (lightPressed)
	{
		night = true;
		glDisable(GL_LIGHT0);
		glEnable(GL_LIGHT1);
		glEnable(GL_LIGHT2);
	}

	if (!lightPressed)
	{
		night = false;
		glDisable(GL_LIGHT1);
		glDisable(GL_LIGHT2);
		glEnable(GL_LIGHT0);
	}

	//Camera switch 
	if (camera1True)
	{
		// Handle user input (W,A,S,D)
		if (input->isKeyDown('w'))
		{
			camera1.moveForward(dt);
		}

		if (input->isKeyDown('s'))
		{
			camera1.moveBackward(dt);
		}

		if (input->isKeyDown('d'))
		{
			camera1.moveRight(dt);
		}

		if (input->isKeyDown('a'))
		{
			camera1.moveLeft(dt);
		}

		//Camera reset (P)
		if (input->isKeyDown('p'))
		{
			input->SetKeyUp('p');
			camera1.reset();
		}

		distanceX = (input->getMouseX() - (width / 2));
		camera1.lookRight_Left(dt, distanceX);

		distanceY = (input->getMouseY() - (height / 2));
		camera1.lookUp_Down(dt, distanceY);

		currentCam = camera1;
	}
	else if (camera2True)
	{
		distanceX = (input->getMouseX() - (width / 2));
		camera2.lookRight_Left(dt, distanceX);

		distanceY = (input->getMouseY() - (height / 2));
		camera2.lookUp_Down(dt, distanceY);

		currentCam = camera2;
	}
	else if (camera3True)
	{
		distanceX = (input->getMouseX() - (width / 2));
		camera3.lookRight_Left(dt, distanceX);

		distanceY = (input->getMouseY() - (height / 2));
		camera3.lookUp_Down(dt, distanceY);

		currentCam = camera3; 
	}
	else if (camera4True)
	{
		distanceX = (input->getMouseX() - (width / 2));
		camera4.lookRight_Left(dt, distanceX);

		distanceY = (input->getMouseY() - (height / 2));
		camera4.lookUp_Down(dt, distanceY);

		currentCam = camera4;
	}

	// update scene related variables.
	rotation += speed * dt;

	// Calculate FPS for output
	calculateFPS();
}

void Scene::render() {

	float shadowMatrix[16];

	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	// Reset transformations
	glLoadIdentity();
	// Set the camera
	gluLookAt(currentCam.getCamX(), currentCam.getCamY(), currentCam.getCamZ(), currentCam.getLookatX(), currentCam.getLookatY(), currentCam.getLookatZ(), currentCam.getUpX(), currentCam.getUpY(), currentCam.getUpZ());
	// Render geometry/scene here -------------------------------------

	//Materials
	GLfloat no_mat[] = { 0.0, 0.0, 0.0, 0.0 };
	GLfloat mat_ambient[] = { 0.4, 0.4, 0.4, 1.0 };
	GLfloat mat_ambient_colour[] = { 0.5, 0.5, 0.5, 1.0 };
	GLfloat mat_diffuse[] = { 0.1, 0.5, 0.8, 1.0 };
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat no_shininess[] = { 0.0 };
	GLfloat low_shininess[] = { 200 };
	GLfloat high_shininess[] = { 100 };
	GLfloat veryHigh_shininess[] = { 50 };
	GLfloat mat_emission[] = { 1, 0, 0, 0.0 };
	GLfloat mat_red[] = { 1, 0, 0, 1 };
	GLfloat mat_metal[] = { 0.3, 0.3, 0.9, 1 };
	GLfloat mat_blue[] = { 0.0, 0.0, 1.0, 1 };

	
	GLfloat floorVerts[] = { -25.f, 0.f, -25.f,	//Top left
							-25.f, 0.f, 25.f,	//Bottom left
							25.f, 0.f, 25.f,	//Bottom right
							25.f, 0.f, -25.f };	//Top right

	//Creates skybox 
	glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, skybox);
		glDisable(GL_DEPTH_TEST);
		glTranslatef(currentCam.getCamX(), currentCam.getCamY(), currentCam.getCamZ());
		shape.skybox();
		glEnable(GL_DEPTH_TEST);
	glPopMatrix();

	//DirectionLight
	light.directionalLight();

	//Create shadowmatrix
	shadow.generateShadowMatrix(shadowMatrix, lightPosition, floorVerts);

	//Ground
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, floor);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);

	glScalef(0.5, 0.5, 0.5);
	glTranslatef(-125.f, -2.5f, -125.f);
	shape.plane(150, 150);
		glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, gravel);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);

		glTranslatef(150.f, 0.f, 0.f);
		shape.plane(150, 150);
		glPopMatrix();

	glPopMatrix();

	if (!night)
	{
		//Shadowing
		glDisable(GL_DEPTH_TEST);
		glDisable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		
		glColor3f(0.1f, 0.1f, 0.1f);
		glPushMatrix();
			glMultMatrixf((GLfloat *)shadowMatrix);
			glTranslatef(0.f, 1.f, 0.f);

			//Wall2 model
			glPushMatrix();
				glScalef(2.5, 2.5, 2.5);
				glTranslatef(5.f, -0.5f, -5.75f);
				glRotatef(90, 0, 1, 0);
				for (int i = 0; i < 4; i++)
				{
					wall2.render();
					glTranslatef(2.5, 0, 0);
				}
			glPopMatrix();

			//Wall2 model
			glPushMatrix();
				glScalef(2.5, 2.5, 2.5);
				glTranslatef(6.25f, -0.5f, -14.5f);
				for (int i = 0; i < 8; i++)
				{
					wall2.render();
					glTranslatef(2.5, 0, 0);
				}
			glPopMatrix();

			//Wall2 model
			glPushMatrix();
				glScalef(2.5, 2.5, 2.5);
				glTranslatef(25.f, -0.5f, -13.25f);
				glRotatef(-90, 0, 1, 0);
				for (int i = 0; i < 8; i++)
				{
					wall2.render();
					glTranslatef(2.5, 0, 0);
				}
			glPopMatrix();

			//Wall2 model
			glPushMatrix();
				glScalef(2.5, 2.5, 2.5);
				glTranslatef(23.75f, -0.5f, 5.f);
				glRotatef(180, 0, 1, 0);
				for (int i = 0; i < 8; i++)
				{
					wall2.render();
					glTranslatef(2.5, 0, 0);
				}
			glPopMatrix();

			//Wall1 model
			glPushMatrix();
				glTranslatef(12.5f, -1.5f, -10.f);
				glRotatef(-90, 1, 0, 0);
				glRotatef(90, 0, 0, 1);
				glScalef(0.05, 0.05, 0.05);
				for (int i = 0; i < 3; i++)
				{
					wall1.render();
					glTranslatef(-55, 0, 0);
				}
			glPopMatrix();

			//Wall1 model
			glPushMatrix();
				glTranslatef(12.5f, -1.5f, 10.f);
				glRotatef(-90, 1, 0, 0);
				glRotatef(90, 0, 0, 1);
				glScalef(0.05, 0.05, 0.05);
				for (int i = 0; i < 3; i++)
				{
					wall1.render();
					glTranslatef(55, 0, 0);
				}
			glPopMatrix();

			//Street Lamps Model
			glPushMatrix();
				glScalef(0.5, 0.5, 0.5);
				glTranslatef(-20, 10, -16);
				glRotatef(-90, 0, 1, 0);
				Lamp.render();
					glPushMatrix();
					glTranslatef(0.f, 0.f, -5.f);
					light.spotLight();
					glPopMatrix();
			glPopMatrix();

			//Wall model
			glPushMatrix();
				glTranslatef(-12.5f, -1.f, 8.f);
				glRotatef(90, 0, 1, 0);
				for (int i = 0; i < 3; i++)
				{
					wall.render();
					glTranslatef(8, 0, 0);
				}
			glPopMatrix();

			//Wall model
			glPushMatrix();
				glTranslatef(7.5f, -1.f, -12.5f);
				for (int i = 0; i < 3; i++)
				{
					wall.render();
					glTranslatef(-8, 0, 0);
				}
			glPopMatrix();

			//Wall model
			glPushMatrix();
				glTranslatef(7.5f, -1.f, 11.5f);
				for (int i = 0; i < 3; i++)
				{
					wall.render();
					glTranslatef(-8, 0, 0);
				}
			glPopMatrix();

			//Disc
			glPushMatrix();
				glBindTexture(GL_TEXTURE_2D, shield);
				glTranslatef(-9.5, -0.25, 6.25);
				glRotatef(45, 1, 0, 0);
				shape.createDisc(20);
				shape.disc();
			glPopMatrix();

			//Cubes
			glPushMatrix();
				glBindTexture(GL_TEXTURE_2D, crate);
				glTranslatef(-10, 0, 8);
				shape.cube();
					glPushMatrix();
					glBindTexture(GL_TEXTURE_2D, crate);
					glTranslatef(1.75, 0, 1.5);
					glRotatef(45, 0, 1, 0);
					shape.cube();
						glPushMatrix();
						glBindTexture(GL_TEXTURE_2D, crate);
						glTranslatef(0.25, 2, -1.5);
						glRotatef(30, 0, 1, 0);
						shape.cube();
						glPopMatrix();
				glPopMatrix();
			glPopMatrix();

			//Sphere
			glPushMatrix();
				glDisable(GL_COLOR_MATERIAL);
				glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
				glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_red);
				glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
				glMaterialfv(GL_FRONT, GL_SHININESS, no_mat);
				glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
				glTranslatef(11.f, 0.25f, -5.f);
				shape.createSphere(20);
					glPushMatrix();
					glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
					glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_metal);
					glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
					glMaterialfv(GL_FRONT, GL_SHININESS, veryHigh_shininess);
					glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
					glTranslatef(0.f, 0.f, -2.5f);
					shape.createSphere(20);
						glPushMatrix();
						glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
						glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_blue);
						glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
						glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
						glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
						glTranslatef(0.f, 0.f, -2.5f);
						shape.createSphere(20);

				glEnable(GL_COLOR_MATERIAL);
						glPopMatrix();
				glPopMatrix();
			glPopMatrix();

			//Tower
			glPushMatrix();
				glScalef(1, 1, 1);
				glTranslatef(35, -0.f, -10);
				tower.render();
					glPushMatrix();
					glTranslatef(-2.0f, 3.0f, 0.0f);
					glRotatef(rotation, 0, 1, 0);
					light.spotLight2();
					glPopMatrix();
			glPopMatrix();

			//Window/Transparent quad
			glPushMatrix();
				glEnable(GL_BLEND);
				glRotatef(90, 0, 1, 0);
				glScalef(3.5, 3.5, 1);
				glTranslatef(0, 0.5, 11.5);
				glColor4f(0.1, 0.1, 1.0, 0.25);
				shape.render1();
				glDisable(GL_BLEND);
			glPopMatrix();

		glPopMatrix();

		glColor3f(1.0f, 1.0f, 1.0f);
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_LIGHTING);
		glEnable(GL_TEXTURE_2D);
	}

	glPushMatrix(); 

	//Wall2 Model
	glPushMatrix();
		glScalef(2.5, 2.5, 2.5);
		glTranslatef(5.f, -0.5f, -5.75f);
		glRotatef(90, 0, 1, 0);
		for (int i = 0; i < 4; i++)
		{
			wall2.render();
			glTranslatef(2.5, 0, 0);
		}
	glPopMatrix();

	//Wall2 Model
	glPushMatrix();
		glScalef(2.5, 2.5, 2.5);
		glTranslatef(6.25f, -0.5f, -14.5f);
		for (int i = 0; i < 8; i++)
		{
			wall2.render();
			glTranslatef(2.5, 0, 0);
		}
	glPopMatrix();

	//Wall2 Model
	glPushMatrix();
		glScalef(2.5, 2.5, 2.5);
		glTranslatef(25.f, -0.5f, -13.25f);
		glRotatef(-90, 0, 1, 0);
		for (int i = 0; i < 8; i++)
		{
			wall2.render();
			glTranslatef(2.5, 0, 0);
		}
	glPopMatrix();

	//Wall2 Model
	glPushMatrix();
		glScalef(2.5, 2.5, 2.5);
		glTranslatef(23.75f, -0.5f, 5.f);
		glRotatef(180, 0, 1, 0);
		for (int i = 0; i < 8; i++)
		{
			wall2.render();
			glTranslatef(2.5, 0, 0);
		}
	glPopMatrix();

	//Wall1 Model
	glPushMatrix();
		glTranslatef(12.5f, -1.5f, -10.f);
		glRotatef(-90, 1, 0, 0);
		glRotatef(90, 0, 0, 1);
		glScalef(0.05, 0.05, 0.05);
		for (int i = 0; i < 3; i++)
		{
			wall1.render();
			glTranslatef(-55, 0, 0);
		}
	glPopMatrix();

	//Wall1 Model
	glPushMatrix();
		glTranslatef(12.5f, -1.5f, 10.f);
		glRotatef(-90, 1, 0, 0);
		glRotatef(90, 0, 0, 1);
		glScalef(0.05, 0.05, 0.05);
		for (int i = 0; i < 3; i++)
		{
			wall1.render();
			glTranslatef(55, 0, 0);
		}
	glPopMatrix();

	//Street Lamps Model
	glPushMatrix();
		glScalef(0.5, 0.5, 0.5);
		glTranslatef(-20, 10, -16);
		glRotatef(-90, 0, 1, 0);
		Lamp.render();
			glPushMatrix();
			glTranslatef(0.f, 0.f, -5.f);
			light.spotLight();
			glPopMatrix();
	glPopMatrix();

	//Wall Model
	glPushMatrix();
		glTranslatef(-12.5f, -1.f, 8.f);
		glRotatef(90, 0, 1, 0);
		for (int i = 0; i < 3; i++)
		{
			wall.render();
			glTranslatef(8, 0, 0);
		}
	glPopMatrix();

	//Wall Model
	glPushMatrix();
		glTranslatef(7.5f, -1.f, -12.5f);
		for (int i = 0; i < 3; i++)
		{
			wall.render();
			glTranslatef(-8, 0, 0);
		}
	glPopMatrix();

	//Wall Model
	glPushMatrix();
		glTranslatef(7.5f, -1.f, 11.5f);
		for (int i = 0; i < 3; i++)
		{
			wall.render();
			glTranslatef(-8, 0, 0);
		}
	glPopMatrix();

	//Disc
	glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, shield);
		glTranslatef(-9.5, -0.25, 6.25);
		glRotatef(45, 1, 0, 0);
		shape.createDisc(20);
		shape.disc();
	glPopMatrix();

	//Cubes
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, crate);
	glTranslatef(-10, 0, 8);
	shape.cube();
		glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, crate);
		glTranslatef(1.75, 0, 1.5);
		glRotatef(45, 0, 1, 0);
		shape.cube();
			glPushMatrix();
			glBindTexture(GL_TEXTURE_2D, crate);
			glTranslatef(0.25, 2, -1.5);
			glRotatef(30, 0, 1, 0);
			shape.cube();
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();

	//Spheres with materials
	glPushMatrix();
	glDisable(GL_COLOR_MATERIAL);
	glDisable(GL_TEXTURE_2D);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_red);
	glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
	glMaterialfv(GL_FRONT, GL_SHININESS, no_mat);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
	glTranslatef(11.f, 0.25f, -5.f);
	shape.createSphere(20);
		glPushMatrix();
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_metal);
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, veryHigh_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		glTranslatef(0.f, 0.f, -2.5f);
		shape.createSphere(20);
			glPushMatrix();
			glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_blue);
			glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
			glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
			glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
			glTranslatef(0.f, 0.f, -2.5f);
			shape.createSphere(20);

			glEnable(GL_COLOR_MATERIAL);
			glEnable(GL_TEXTURE_2D);
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();

	//Tower with spotlight rotating around it
	glPushMatrix();
		glScalef(1, 1, 1);
		glTranslatef(35, 0.f, -10);
		tower.render();
			glPushMatrix();
			glTranslatef(-2.0f, 3.0f, 0.0f);
			glRotatef(rotation, 0, 1, 0);
			light.spotLight2();
			glPopMatrix();	
	glPopMatrix();

	//Window/Transparent quad
	glPushMatrix();
		glEnable(GL_BLEND);
		glRotatef(90, 0, 1, 0);
		glScalef(3.5, 3.5, 1);
		glTranslatef(0, 0.5, 11.5);
		glColor4f(0.1, 0.1, 1.0, 0.25);
		shape.render1();
		glDisable(GL_BLEND);
	glPopMatrix();

	glPopMatrix();

	// End render geometry --------------------------------------

	// Render text, should be last object rendered.
	renderTextOutput();
	
	// Swap buffers, after all objects are rendered.
	glutSwapBuffers();
}

// Handles the resize of the window. If the window changes size the perspective matrix requires re-calculation to match new window size.
void Scene::resize(int w, int h) 
{
	width = w;
	height = h;
	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;

	float ratio = (float)w / (float)h;
	fov = 45.0f;
	nearPlane = 0.1f;
	farPlane = 100.0f;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(fov, ratio, nearPlane, farPlane);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}

// Calculates FPS
void Scene::calculateFPS()
{

	frame++;
	time = glutGet(GLUT_ELAPSED_TIME);

	if (time - timebase > 1000) {
		sprintf_s(fps, "FPS: %4.2f", frame*1000.0 / (time - timebase));
		timebase = time;
		frame = 0;
	}
}

// Compiles standard output text including FPS and current mouse position.
void Scene::renderTextOutput()
{
	// Render current mouse position and frames per second.
	sprintf_s(mouseText, "Mouse: %i, %i", input->getMouseX(), input->getMouseY());
	displayText(-1.f, 0.96f, 1.f, 1.f, 1.f, mouseText);
	displayText(-1.f, 0.90f, 1.f, 1.f, 1.f, fps);
	displayText(-1.f, 0.84f, 1.f, 1.f, 1.f, cameraKeys);
}

// Renders text to screen. Must be called last in render function (before swap buffers)
void Scene::displayText(float x, float y, float r, float g, float b, char* string) {
	// Get Lenth of string
	int j = strlen(string);

	// Swap to 2D rendering
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, 5, 100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	// Orthographic lookAt (along the z-axis).
	gluLookAt(0.0f, 0.0f, 10.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

	// Set text colour and position.
	glColor3f(r, g, b);
	glRasterPos2f(x, y);
	// Render text.
	for (int i = 0; i < j; i++) {
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, string[i]);
	}
	// Reset colour to white.
	glColor3f(1.f, 1.f, 1.f);

	// Swap back to 3D rendering.
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fov, ((float)width/(float)height), nearPlane, farPlane);
	glMatrixMode(GL_MODELVIEW);
}
