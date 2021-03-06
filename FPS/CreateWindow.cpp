#include "CreateWindow.h"
#include <iostream>

using namespace std;
	
	/*CreateWindow:: CreateWindow()
	{
		root_x_return = 0.0, 
		root_y_return = 0.0;
		win_x_return = 0.0, 
		win_y_return = 0.0;
		mask_return = 0.0; 
	
	}; */
void CreateWindow:: drawWindow()
{
	int screen;
	
	unsigned int depth;
	XSetWindowAttributes attrs;
	int trueu = 1;
	
	
	
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
	attrs.override_redirect = trueu;
	//attrs.colormap = CopyFromParent;
	attrs.colormap = XCreateColormap(dpy,root_win,visual->visual,AllocNone);
	attrs.event_mask = ExposureMask | KeyPressMask;
	attrs.event_mask = ExposureMask | KeyPressMask | PointerMotionMask;


	win = XCreateWindow(dpy, root_win,200,200,500,300,
	0,visual->depth,InputOutput,visual->visual,CWBackPixel| CWColormap|CWBorderPixel | CWEventMask,&attrs);

	//XSelectInput(dpy, win, ExposureMask| KeyPressMask);

	XMapWindow(dpy, win);

	glc = glXCreateContext(dpy,visual,NULL,GL_TRUE);
	glXMakeCurrent(dpy, win, glc);
	glEnable(GL_DEPTH_TEST);

}

void CreateWindow:: view()
{
	XGetWindowAttributes(dpy,win,&winattr);
	glViewport(0,0,winattr.width, winattr.height);// setting up the view port

}

void CreateWindow:: Buffer()
{
	glXSwapBuffers(dpy,win);// Set BUffer
	usleep(5000);
}

void CreateWindow::MouseCalc()
{
	nx = (win_x_return*20.0/ winattr.width)-10.0;
	ny = 10.0-(win_y_return *20.9/winattr.height);
}
