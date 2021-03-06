#include <iostream>
#include "CameraClass.h"

CameraClass:: CameraClass()
{
	float xpos = 0, ypos = 0, zpos = 0, xrot = 0, yrot = 0, angle=0.0;
}
void CameraClass::moveCamera()
{
    glRotatef(xrot,1.0,0.0,0.0);  //rotate our camera on the x-axis (left and right)
    glRotatef(yrot,0.0,1.0,0.0);  //rotate our camera on the y-axis (up and down)
    glTranslated(-xpos,-ypos,-zpos); //translate the screen to the position of our camera
}

void CameraClass::cameraView()
{
	   glMatrixMode (GL_PROJECTION); //set the matrix to projection

    glLoadIdentity ();
    gluPerspective (60, 1.0, 1.0, 1000.0); 
    glMatrixMode (GL_MODELVIEW); //set the matrix back to model
}
