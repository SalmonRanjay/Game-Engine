#include <iostream>
#include "Triangles.h"


using namespace std;

Triangles::Triangles()
{
 	ytranslate = 0.0;
 	xtranslate = 0.0;  
 	ztranslate =0.0;
	
}
void Triangles::drawTriangle(CreateWindow object)
{
	
		
	gluLookAt( 0,0,0,
		   0,0,-1,
		   0,2,0);
	
	

	
	

	glColor3f(0.0f,0.02f,0.7f); // color the inside of the triangle
	glPushMatrix();
	//glRotatef(0, 1.0, 1.0, 0.0);
	//UglTranslatef(object.nx, object.ny, 0.0f);
	glTranslatef(xtranslate, ytranslate, ztranslate);

	/*glBegin(GL_QUADS);
		glVertex3f(0.5f,0.5f,0.5f);
		glVertex3f(-0.5f,0.5f,0.5f);
		glVertex3f(-0.5f,0.5f,-0.5f);
		glVertex3f(0.5f,0.5f,-0.5f);
	glEnd(); */
	
	glBegin(GL_TRIANGLES);// specify the beginning of drawing the triangle
		glVertex3f(0.0f,0.0f,0.0f);
		glVertex3f(-0.5f,0.5f,0.0f);	
		glVertex3f(0.5f,0.8f,0.0f);
	glEnd();// end of drawing triangle
	
	glPopMatrix();

}
