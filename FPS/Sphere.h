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
///#include "CreateWindow.h"
#define RESOLUTION 0.05
//using namespace std;

class Sphere
{

	public :

		int angle;
		float angle1,angle2;
		float x,y,z,x2,y2,z2;
		int xtranslate, ytranslate, ztranslate;
		CreateWindow winObject;
		Sphere();
		void drawSphere(CreateWindow winObject);
		
};
