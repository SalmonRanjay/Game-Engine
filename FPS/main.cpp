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
#include <stdio.h> 
#include "CreateWindow.h"
//#include "Sphere.h"
#include "Triangles.h"



CreateWindow obj;
Triangles triangle1;
//Sphere sphereone;
void DrawStuff();
int main(int argc, char *argv[])
{

	//createWindow();
	
	obj.drawWindow();

	
	while(1)
	{
		if(XPending(obj.dpy)==0)
		{
			//DrawSphere();
			continue;
		}
		XNextEvent(obj.dpy, &obj.event);
		if(obj.event.type == Expose)
		{
			//DrawSphere();
				
		}

		if(obj.event.type == KeyPress)
		{
			/*
			XDestroyWindow(dpy, win);
			XCloseDisplay(dpy);
			break;

			*/
			char buffer[31];
    			//KeySym keysym;
    			XLookupString(&obj.event.xkey,buffer,30,&obj.keysym,NULL);
			float fraction = 0.1f;
			
			switch(obj.keysym)
			{
				case XK_Right:
					triangle1.xtranslate+=0.25;
				break;
				case XK_Left:
					triangle1.xtranslate-=0.25;
				break;
				case XK_Up:
					triangle1.ytranslate+=0.25;
				break;
				case XK_Down:
					triangle1.ytranslate-=0.25;
				break;
				case XK_a: 
				case XK_A:
					triangle1.ztranslate+=0.25;
				break;
				case XK_s: case XK_S:
					triangle1.ztranslate-=0.25;
				break;
				case XK_Escape:
					XDestroyWindow(obj.dpy, obj.win);
					XCloseDisplay(obj.dpy);
				break;
	
	
			}
	

		} else if(obj.event.type == MotionNotify)
			{
				XQueryPointer(obj.dpy, obj.win, &root_return, &child_return,
				&root_x_return, &root_y_return,
				&win_x_return, &win_y_return,
				&mask_return);
				//printf("%d, %d\n", win_x_return, win_y_return);
			} 

		//DrawSphere();
		//drawBackground();
		//sphereone.drawSphere();
		DrawStuff();
		
		
	}
	

	return 0;

};

void DrawStuff()
{
	obj.view();
	glClearColor(0.9f,0.5f,0.6f,0.0f);// controls the background color
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	triangle1.drawTriangle();
	obj.Buffer();

};

