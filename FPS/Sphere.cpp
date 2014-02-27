#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include <X11/Xatom.h>
#include <X11/keysym.h>
#include <math.h>
/* open GL includes*/
#include <GL/gl.h>
#include <GL/glx.h>
#include <GL/glu.h>
#include <iostream>
#include "Sphere.h"
using namespace std;


void Sphere:: drawSphere()
{
		// preparing the window to draw
		/*
		XGetWindowAttributes(dpy,win,&winattr);
		glViewport(0,0,winattr.width, winattr.height);// setting up the view port
		*/
		glClearColor(0.7f,0.7f,0.7f,0.0f);// controls the background color
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//glColor3f(0.0f,0.02f,0.7f); // color the inside of the sphere
		glPushMatrix();
		glTranslatef(xtranslate, ytranslate, ztranslate);
		//glRotatef(angle, 1.0 , 1.0 ,0.0);
	
		// drawing background
		glColor3f(0.09f, 0.9f,0.9f);
		glBegin(GL_QUAD_STRIP);
			glVertex3f(-100.0f,0.0f,-100.0f);
			glVertex3f(-100.0f,0.0f,100.0f);
			glVertex3f(100.0f,0.0f,100.0f);
			glVertex3f(100.0f,0.0f,-100.0f);
		glEnd();
		
		for(angle2 = -3.1416/2 ; angle2 <= 3.1416/2; angle2 += RESOLUTION)
		{
			// specify the beginning of drawing the sphere
			glBegin(GL_QUAD_STRIP);

			for(angle1 =0.0; angle1 <= 3.1416*2.0+RESOLUTION ;angle1 += RESOLUTION)
			{

				y=sin(angle2);
				x=cos(angle1)*cos(angle2);
				z=sin(angle2)*cos(angle2);

				y2=sin(angle2 + RESOLUTION);
				x2=cos(angle1)*cos(angle2 + RESOLUTION);
				z2=sin(angle2)*cos(angle2 + RESOLUTION);

				glColor3f(z*z,x*x,1.0f);
				glVertex3f(x,y,z);
				glVertex3f(x2,y2,z2);	
			
			}
			glEnd();// end of drawing SPHERE
		}

		glPopMatrix();
		/*
		glXSwapBuffers(dpy,win);// Set BUffer

		usleep(5000);
		*/
		angle+=1;
		if(angle == 360)
			angle = 0;

		//glFlush();
}