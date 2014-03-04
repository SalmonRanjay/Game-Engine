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
//#include "CreateWindow.h"
#include "Sphere.h"
//#include "Triangles.h"
#include "CameraClass.h"



CreateWindow obj;
CameraClass cameraObject;
//Triangles triangle1;
Sphere sphereone;
float lastx, lasty;
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
					//triangle1.xtranslate+=0.25;
					//sphereone.xtranslate+=0.25;
					// Camera movement calculations
					  	
					  
    					   float yyyrotrad;
					    yyyrotrad = (cameraObject.yrot / 180 * 3.141592654f);
					    cameraObject.xpos += float(cos(yyyrotrad)) * 0.2;
					    cameraObject.zpos += float(sin(yyyrotrad)) * 0.2;
				break;
				case XK_Left:
					//triangle1.xtranslate-=0.25;
					//sphereone.xtranslate-=0.25;
					  float yyyyrotrad;
					    yyyyrotrad = (cameraObject.yrot / 180 * 3.141592654f);
					    cameraObject.xpos -= float(cos(yyyyrotrad)) * 0.2;
					    cameraObject.zpos -= float(sin(yyyyrotrad)) * 0.2;
				break;
				case XK_Up:
					//triangle1.ytranslate+=0.25;
					//sphereone.ytranslate+=0.25;
					    float xrotrad, yrotrad;
					    yrotrad = (cameraObject.yrot / 180 * 3.141592654f);
					    xrotrad = (cameraObject.xrot / 180 * 3.141592654f); 
					    cameraObject.xpos += float(sin(yrotrad)) ;
					    cameraObject.zpos -= float(cos(yrotrad)) ;
					    cameraObject.ypos -= float(sin(xrotrad)) ;
				break;
				case XK_Down:
					//triangle1.ytranslate-=0.25;
					//sphereone.ytranslate-=0.25;
					   float xxrotrad, yyrotrad;
					    yyrotrad = (cameraObject.yrot / 180 * 3.141592654f);
					    xxrotrad = (cameraObject.xrot / 180 * 3.141592654f); 
					    cameraObject.xpos -= float(sin(yyrotrad));
					    cameraObject.zpos += float(cos(yyrotrad)) ;
					    cameraObject.ypos += float(sin(xxrotrad));
				break;
				case XK_a: 
				case XK_A:
					//triangle1.ztranslate+=0.25;
					   cameraObject.xrot += 1;
    					   if (cameraObject.xrot >360) cameraObject.xrot -= 360;
				break;
				case XK_s: case XK_S:
					//triangle1.ztranslate-=0.25;
					cameraObject.xrot -= 1;
					if (cameraObject.xrot < -360) cameraObject.xrot += 360;
				break;
				case XK_Escape:
					XDestroyWindow(obj.dpy, obj.win);
					XCloseDisplay(obj.dpy);
				break; 
	
	
			}
			

		} else if(obj.event.type == MotionNotify)
			{
				XQueryPointer(obj.dpy, obj.win, &obj.root_return, &obj.child_return,
				&obj.root_x_return, &obj.root_y_return,
				&obj.win_x_return, &obj.win_y_return,
				&obj.mask_return);
				obj.MouseCalc();
				int diffx = obj.win_x_return - lastx;
				int diffy = obj.win_y_return - lasty;
				lastx = obj.win_x_return;
				lasty = obj.win_y_return;
				cameraObject.xrot += (float) diffy;
				cameraObject.yrot += (float) diffx;
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
	glLoadIdentity();
	cameraObject.cameraView();
	cameraObject.moveCamera();
	sphereone.drawSphere(obj);
	//triangle1.drawTriangle(obj);
	obj.Buffer();

};

