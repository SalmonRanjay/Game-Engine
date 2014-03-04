#include <iostream>
#include "EnvironmentObjects.h"

EnvironmentObjects::EnvironmentObjects()
{
	xcoord = ycoord = zcoord = 0.5;
};

void EnvironmentObjects::renderObject(float x,float y,float z,float xt,float yt,float zt)
{
	xcoord=x;
	ycoord=y;
	zcoord=z;
	
	glPushMatrix();
	glTranslatef(xt, yt,zt );
	glBegin(GL_POLYGON);
	glColor3f(   1.0,  1.0, 1.0 );
	glVertex3f(  xcoord, -ycoord, zcoord );
	glVertex3f(  xcoord,  ycoord, zcoord );
	glVertex3f( -xcoord,  ycoord, zcoord );
	glVertex3f( -xcoord, -ycoord, zcoord );
	glEnd();
	 
	// Purple side - RIGHT
	glBegin(GL_POLYGON);
	glColor3f(  1.0,  0.0,  1.0 );
	glVertex3f( xcoord, -ycoord, -zcoord );
	glVertex3f( xcoord,  ycoord, -zcoord );
	glVertex3f( xcoord,  ycoord,  zcoord );
	glVertex3f( xcoord, -ycoord,  zcoord );
	glEnd();
	 
	// Green side - LEFT
	glBegin(GL_POLYGON);
	glColor3f(   0.0,  1.0,  0.0 );
	glVertex3f( -xcoord, -ycoord,  zcoord );
	glVertex3f( -xcoord,  ycoord,  zcoord );
	glVertex3f( -xcoord,  ycoord, -zcoord );
	glVertex3f( -xcoord, -ycoord, -zcoord );
	glEnd();
	 
	// Blue side - TOP
	glBegin(GL_POLYGON);
	glColor3f(   0.0,  0.0,  1.0 );
	glVertex3f(  xcoord,  ycoord,  zcoord );
	glVertex3f(  xcoord,  ycoord, -zcoord );
	glVertex3f( -xcoord,  ycoord, -zcoord );
	glVertex3f( -xcoord,  ycoord,  zcoord );
	glEnd();
	 
	// Red side - BOTTOM
	glBegin(GL_POLYGON);
	glColor3f(   1.0,  0.0,  0.0 );
	glVertex3f(  xcoord, -ycoord, -zcoord );
	glVertex3f(  xcoord, -ycoord,  zcoord );
	glVertex3f( -xcoord, -ycoord,  zcoord );
	glVertex3f( -xcoord, -ycoord, -zcoord );
	glEnd();
	glPopMatrix(); 
	glFlush();
};
