#include <GL/gl.h>
#include <GL/glx.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <math.h>

class CameraClass
{
	public:
	CameraClass();
	float xpos,ypos, zpos, xrot, yrot , angle;
	void moveCamera();
	void cameraView();
};
