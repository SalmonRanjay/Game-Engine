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
using namespace std;


class CreateWindow
{

public:
	Display *dpy;
	Window win,root_win;
	XWindowAttributes winattr;
	XEvent event;
	KeySym keysym;
	
	/*Display* getDpy()
	{
		return dpy;
	};
	*/
	XEvent getEvent()
	{
		return event;
	};
	KeySym getksym()
	{
		return keysym;
	};

	void drawWindow();
	void view();
	void Buffer();
	
};

