 #include "shape.h"

//Vertices for quad
extern float verts[] = {	-1.0, 1.0, 1.0,			// Vertex #0
							-1.0, -1.0, 1.0,		// Vertex #1
							1.0,  -1.0, 1.0,		// Vertex #2
							1.0,  1.0, 1.0,			// Vertex #3
						};

//Normals for quad
extern float norms[] = { 0.0, 0.0, 1.0,		//0
						0.0, 0.0, 1.0,		//1
 						0.0, 0.0, 1.0,		//2
						0.0, 0.0, 1.0,		//3
						};		

//Texture coordinates for quad  
extern float texcoords[]= {	0.0, 0.0, 		//0
							0.0, 1.0, 		//1
 							1.0, 1.0, 		//2
							1.0, 0.0, 		//3
							};

//Indices for quad 
extern GLubyte indices[] = { 0, 1, 2, 3 //front
							};

//Vertices for cube 
extern float cubeVerts[] = { -1.0, 1.0, 1.0,		//0 //Front
								-1.0, -1.0, 1.0,	//1
								1.0, -1.0, 1.0,		//2
								1.0, 1.0, 1.0,		//3

								1.0, 1.0, 1.0,		//4	//Right
								1.0, -1.0, 1.0,		//5
								1.0, -1.0, -1.0,	//6
								1.0, 1.0, -1.0,		//7

								1.0, 1.0, -1.0,		//8 //Back
								1.0, -1.0, -1.0,	//9
								-1.0, -1.0, -1.0,	//10	
								-1.0, 1.0, -1.0,	//11

								-1.0, 1.0, -1.0,	//12 //Left
								-1.0, -1.0, -1.0,	//13
								-1.0, -1.0, 1.0,	//14
								-1.0, 1.0, 1.0,		//15

								1.0, 1.0, 1.0,		//16 //Top
								-1.0, 1.0, 1.0,		//17
								-1.0, 1.0, -1.0,	//18
								1.0, 1.0, -1.0,		//19
								
								-1.0, -1.0, -1.0,	//20 //Bottom
								1.0, -1.0, -1.0,	//21
								1.0, -1.0, 1.0,		//22
								-1.0, -1.0, 1.0		//23
							};

//Normals for a cube 
extern float cubeNorms[] = { 0.0, 0.0, 1.0,		//0	//Front
								0.0, 0.0, 1.0,		//1
								0.0, 0.0, 1.0,		//2
								0.0, 0.0, 1.0,		//3

								1.0, 0.0, 0.0,		//4	//Right
								1.0, 0.0, 0.0,		//5
								1.0, 0.0, 0.0,		//6
								1.0, 0.0, 0.0,		//7

								0.0, 0.0, -1.0,		//8	//Back
								0.0, 0.0, -1.0,		//9
								0.0, 0.0, -1.0,		//10
								0.0, 0.0, -1.0,		//11

								-1.0, 0.0, 0.0,		//12 //Left
								-1.0, 0.0, 0.0,		//13
								-1.0, 0.0, 0.0,		//14
								-1.0, 0.0, 0.0,		//15

								0.0, 1.0, 0.0,		//16 //Top
								0.0, 1.0, 0.0,		//17
								0.0, 1.0, 0.0,		//18
								0.0, 1.0, 0.0,		//19

								0.0, -1.0, 0.0,		//20 //Bottom
								0.0, -1.0, 0.0,		//21
								0.0, -1.0, 0.0,		//22
								0.0, -1.0, 0.0,		//23
								};

//Texture coordinates for a cube 
extern float cubeTex[] = { 0.0, 0.0, 		//0
							0.0, 1.0, 		//1
							1.0, 1.0, 		//2
							1.0, 0.0, 		//3

							0.0, 0.0, 		//4
							0.0, 1.0, 		//5
							1.0, 1.0, 		//6
							1.0, 0.0, 		//7

							0.0, 0.0, 		//8
							0.0, 1.0, 		//9
							1.0, 1.0, 		//10
							1.0, 0.0, 		//11

							0.0, 0.0, 		//12
							0.0, 1.0, 		//13
							1.0, 1.0, 		//14
							1.0, 0.0, 		//15

							0.0, 0.0, 		//16
							0.0, 1.0, 		//17
							1.0, 1.0, 		//18
							1.0, 0.0, 		//19

							0.0, 0.0, 		//20
							0.0, 1.0, 		//21
							1.0, 1.0, 		//22
							1.0, 0.0, 		//23
};

//Skybox texture coordinates 
extern float skyboxTex[] = { 0.25f, 0.333f,	//0 //Front
							0.25f, 0.666f,	//1
							0.5f, 0.666f,	//2
							0.5f, 0.333f,	//3

							0.5f, 0.333f,	//4	//Right
							0.5f, 0.666f,	//5
							0.75f, 0.666f,	//6
							0.75f, 0.333f,	//7

							0.75f, 0.333f,	//8 //Back
							0.75f, 0.666f,	//9
							1.0f, 0.666f,	//10
							1.0f, 0.333f,	//11

							0.0f, 0.333f,	//12 //Left
							0.0f, 0.666f,	//13
							0.25f, 0.666f,	//14
							0.25f, 0.333f,	//15

							0.25f, 0.333f,	//16 //Top
							0.5f, 0.333f,	//17
							0.5f, 0.0f,		//18
							0.25f, 0.0f,	//19

							0.25f, 0.666f,	//20 //Bottom
							0.25f, 1.0f,	//21
							0.5f, 1.0f,		//22
							0.5f, 0.666f	//23
							};

//Indices for skybox / cube 
extern GLubyte skyBoxIndices[] = { 0, 1, 2, 3, //Front 
									4, 5, 6, 7, //Right
									8, 9, 10, 11, //Back
									12, 13, 14, 15, //Left
									16, 17, 18, 19,	//Top
									20, 21, 22, 23	//Bottom
							};

//Render function using array element 
void Shape::render1()
{
	// add code to render the cube (above) using method 1
	// glArrayElement()
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0, verts);
	glNormalPointer(GL_FLOAT, 0, norms);
	glTexCoordPointer(2, GL_FLOAT, 0, texcoords);

	glBegin(GL_QUADS);
		glArrayElement(0);
		glArrayElement(1);
		glArrayElement(2);
		glArrayElement(3);
	glEnd();

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}
//Render function using draw arrays 
void Shape::render2()
{
	// add code to render the cube (above) using method 2
	// glDrawArrays()
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0, verts);
	glNormalPointer(GL_FLOAT, 0, norms);
	glTexCoordPointer(2, GL_FLOAT, 0, texcoords);

	glDrawArrays(GL_QUADS, 0, 4);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}

//Render function using indices
void Shape::render3()
{
	// add code to render the cube (above) using method 3
	// glDrawElements()
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0, verts);
	glNormalPointer(GL_FLOAT, 0, norms);
	glTexCoordPointer(2, GL_FLOAT, 0, texcoords);
	
	glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, indices);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}

//Render function for skybox 
void Shape::skybox()
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0, cubeVerts);
	glNormalPointer(GL_FLOAT, 0, cubeNorms);
	glTexCoordPointer(2, GL_FLOAT, 0, skyboxTex);

	glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, skyBoxIndices);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}

//Render function for cube 
void Shape::cube()
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0, cubeVerts);
	glNormalPointer(GL_FLOAT, 0, cubeNorms);
	glTexCoordPointer(2, GL_FLOAT, 0, cubeTex);

	glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, skyBoxIndices);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}

//Procedurally generated disc
void Shape::createDisc(int resolution)
{
	m_resolution = resolution + 2;
	discVerts = new float[m_resolution * 3];
	discNorms = new float[m_resolution * 3]; 
	discTex = new float[m_resolution * 2]; 

	float interval = (2 * 3.1415) / resolution; 
	float angle = 0; 

	discVerts[0] = 0; 
	discVerts[1] = 0;
	discVerts[2] = 0;
	discTex[0] = 0.5; 
	discTex[1] = 0.5;

	for (int i = 3; i < m_resolution * 3; i += 3)
	{
		double x = cos(angle); 
		discVerts[i] = x; 
		double y = sin(angle); 
		discVerts[i + 1] = y; 
		double z = 0; 
		discVerts[i + 2] = z;

		float u = (x / 2) + 0.5; 
		float v = (y / 2) + 0.5; 
		discTex[(2 * i / 3)] = u; 
		discTex[(2 * i / 3) + 1] = v; 
		angle += interval; 

		if (angle >= 6.283)
		{
			angle = 0; 
		}
		discNorms[i] = 0; 
		discNorms[i + 1] = 1; 
		discNorms[i + 2] = 0; 
	}
}

//Render function for disc
void Shape::disc()
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0, discVerts);
	glNormalPointer(GL_FLOAT, 0, discNorms);
	glTexCoordPointer(2, GL_FLOAT, 0, discTex);
		
	glDrawArrays(GL_TRIANGLE_FAN, 0, m_resolution);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}

//Render function for plane/ground 
void Shape::plane(int w, int h)
{
	for (int x = 0.5; x < w; x++)
	{
		for (int y = 0.5; y < h; y++)
		{
			glBegin(GL_QUADS);
			glNormal3f(0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(x, 0.5f, y);

			glNormal3f(0.0f, 1.0f, 0.0f);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(x + 1, 0.5f, y);

			glNormal3f(0.0f, 1.0f, 0.0f);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(x + 1, 0.5, y + 1);

			glNormal3f(0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(x, 0.5f, y + 1);
			glEnd();
		}
	}
}

//Procedurally generated sphere 
void Shape::createSphere(int resolution)
{
	m_resolution = resolution + 1;

	float theta = (2 * 3.1415) / resolution;
	float delta = 3.1415 / resolution;
	float angle_lon = 0;
	float angle_lat = 0;
	float next_lon = 0;
	float next_lat = 0;

	
	glBegin(GL_QUADS);

	for (int lon = 0; lon < m_resolution; lon++)
	{
		for (int lat = 0; lat < m_resolution; lat++)
		{
			next_lat = angle_lat + theta;

			//[lat][long]
			glNormal3f(cos(angle_lat) * sin(angle_lon), cos(angle_lon), sin(angle_lat) * sin(angle_lon));
			glVertex3f(cos(angle_lat)* sin(angle_lon), cos(angle_lon), sin(angle_lat) * sin(angle_lon));

			//[lat][long + 1] 
			glNormal3f(cos(next_lat) * sin(angle_lon), cos(angle_lon), sin(next_lat) * sin(angle_lon));
			glVertex3f(cos(next_lat)* sin(angle_lon), cos(angle_lon), sin(next_lat) * sin(angle_lon));

			//[lat + 1][long + 1] 
			glNormal3f(cos(next_lat) * sin(next_lon), cos(next_lon), sin(next_lat) * sin(next_lon));
			glVertex3f(cos(next_lat)* sin(next_lon), cos(next_lon), sin(next_lat) * sin(next_lon));

			//[lat + 1][lon]
			glNormal3f(cos(angle_lat) * sin(next_lon), cos(next_lon), sin(angle_lat) * sin(next_lon));
			glVertex3f(cos(angle_lat)* sin(next_lon), cos(next_lon), sin(angle_lat) * sin(next_lon));

			angle_lat = next_lat;
		}
		angle_lon = next_lon;
		next_lon = angle_lon + delta;
	}
	glEnd();
}

