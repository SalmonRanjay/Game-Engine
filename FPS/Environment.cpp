#include <iostream>
#include "Environment.h"

Environment::Environment()
{
};

void Environment::renderEnvironment()
{
	glPushMatrix();
	glColor3f(0.09f, 0.9f,0.9f);
	glBegin(GL_QUADS);
			glVertex3f(-100.0f,-1.0f,-100.0f);
			glVertex3f(-100.0f,-1.0f,100.0f);
			glVertex3f(100.0f,-1.0f,100.0f);
			glVertex3f(100.0f,-1.0f,-100.0f);
		glEnd();
	glPopMatrix();
};
