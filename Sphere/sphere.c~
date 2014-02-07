#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include <X11/Xatom.h>
#include <math.h>
/* open GL includes*/
#include <GL/gl.h>
#include <GL/glx.h>
#include <GL/glu.h>
#define RESOLUTION 0.05

// TUTORIAL USED LINK:http://www.youtube.com/watch?v=gBlk-14SIMI
Display *dpy;
Window win,root_win;
XWindowAttributes winattr;

void DrawSphere(void)
{
	
	//angle = 2;
	float angle1,angle2;
	float x,y,z,x2,y2,z2;

	// preparing the window to draw
	XGetWindowAttributes(dpy,win,&winattr);
	glViewport(0,0,winattr.width, winattr.height);// setting up the view port

	glClearColor(0.7f,0.7f,0.7f,0.0f);// controls the background color
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glColor3f(0.0f,0.02f,0.7f); // color the inside of the sphere
	glPushMatrix();
	glRotatef(angle,1.0,1.0,0.0);

	for(angle2= -3.14162/2; angle2<= 3.14162/2; angle2+=RESOLUTION)
	{
		// specify the beginning of drawing the sphere
		glBegin(GL_QUAD_STRIP);

		for(angle1 =0.0;angle1<=3.1416;angle1+=RESOLUTION)
		{

			y=sin(angle2);
			x=cos(angle1)*cos(angle2);
			z=sin(angle2)*cos(angle2);

			y2=sin(angle2 + RESOLUTION);
			x2=cos(angle1)*cos(angle2+RESOLUTION);
			z2=sin(angle2)*cos(angle2+ RESOLUTION);
			glColor3f(z*z,x*x,0.0f);
			glVertex3f(x,y,z);
			glVertex3f(x2,y2,z2);	
			//glVertex3f(0.5f,0.5f,0.0f);
		}
		glEnd();// end of drawing SPHERE
	}

	glPopMatrix();
	glXSwapBuffers(dpy,win);// Set BUffer

	

}

int main(int argc, char *argv[])
{

	
	int screen;
	XEvent event;
	unsigned int depth;
	XSetWindowAttributes attrs;
	int true = 1;
	
	
	
	//Glx variables

	GLint att[] = {GLX_RGBA, GLX_DEPTH_SIZE,24,GLX_DOUBLEBUFFER,None};
	XVisualInfo *visual;
	GLXContext glc;


	dpy = XOpenDisplay(NULL);
	if(dpy == NULL)
	{
		fprintf(stderr, "cannot open display\n");
		exit(1);
	}

	screen = DefaultScreen(dpy);
	depth= DefaultDepth(dpy,screen);
	root_win = RootWindow(dpy,screen);

	visual = glXChooseVisual(dpy,screen,att);

	//setting windows attributes using the "attr" varaible
	attrs.border_pixel = BlackPixel(dpy, screen);
	attrs.background_pixel = WhitePixel(dpy,screen);
	attrs.override_redirect = true;
	//attrs.colormap = CopyFromParent;
	attrs.colormap = XCreateColormap(dpy,root_win,visual->visual,AllocNone);
	attrs.event_mask = ExposureMask | KeyPressMask;
	attrs.event_mask = ExposureMask | KeyPressMask;


	win = XCreateWindow(dpy, root_win,200,200,500,300,
	0,visual->depth,InputOutput,visual->visual,CWBackPixel| CWColormap|CWBorderPixel | CWEventMask,&attrs);

	//XSelectInput(dpy, win, ExposureMask| KeyPressMask);

	XMapWindow(dpy, win);

	glc = glXCreateContext(dpy,visual,NULL,GL_TRUE);
	glXMakeCurrent(dpy, win, glc);
	glEnable(GL_DEPTH_TEST);
	while(1)
	{
		XNextEvent(dpy, &event);
		if(event.type == Expose)
		{
			DrawSphere();
				
		}

		if(event.type == KeyPress)
		{
			XDestroyWindow(dpy, win);
			XCloseDisplay(dpy);
			break;

		}
	}



	return 0;

};
