#include <GL/gl.h>
#include <GL/glx.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>

class EnvironmentObjects
{
	public:
	EnvironmentObjects();
	float xcoord;
	float ycoord;
	float zcoord;
	void renderObject(float xcoord,float ycoord,float zcoord,float xt, float yt, float zt);
};
