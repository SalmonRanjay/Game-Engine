#include "Dummy.h"
void Dummy:: drawCube(float size)
{
	glPushMatrix();
	float difamb[]={1.0,0.5,0.3,1.0};
	glBegin(GL_QUADS);
	// front face
	//glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,difamb);
	glNormal3f(0.0,0.0,1.0);
	glColor3f(   1.0,  0.0, 0.0 );
	glVertex3f(  size/2, size/2, size/2 );
	glVertex3f(  -size/2,  size/2, size/2 );
	glVertex3f( -size/2,  -size/2, size/2 );
	glVertex3f( size/2, -size/2, size/2 );

	// left face
	glNormal3f(-1.0,0.0,0.0);
	glColor3f(  0.0,  1.0,  0.0 );
	glVertex3f( -size/2, size/2, size/2 );
	glVertex3f( -size/2,  size/2, -size/2 );
	glVertex3f( -size/2, -size/2,  -size/2 );
	glVertex3f( -size/2, -size/2,  size/2 );
	
	 
	// BACK FACE
	glNormal3f(0.0,0.0,-1.0);
	glColor3f(   0.0,  0.0,  1.0 );
	glVertex3f( size/2, size/2,  -size/2 );
	glVertex3f( -size/2,  size/2,  -size/2 );
	glVertex3f( -size/2,  -size/2, -size/2 );
	glVertex3f( size/2, -size/2, -size/2 );
	 
	// RIGHT FACE
	glNormal3f(1.0,0.0,0.0);
	glColor3f(   2.0,  1.0,  1.0 );
	glVertex3f(  size/2,  size/2,  -size/2 );
	glVertex3f(  size/2,  size/2, size/2 );
	glVertex3f(  size/2,  -size/2, size/2 );
	glVertex3f(  size/2,  -size/2, -size/2 );
	
	 
	// TOP FACE
	glNormal3f(0.0,1.0,0.0);
	glColor3f(   1.0,  0.0,  1.0 );
	glVertex3f(  size/2, size/2, size/2 );
	glVertex3f(  -size/2, size/2,  size/2 );
	glVertex3f( -size/2, size/2,  -size/2 );
	glVertex3f( size/2, size/2, -size/2 );
	
	//BOTTOM FACE
	glNormal3f(0.0,-1.0,0.0);
	glColor3f(1.0,3.0,1.0);
	glVertex3f(  size/2, -size/2, size/2 );
	glVertex3f(  -size/2, -size/2,  size/2 );
	glVertex3f( -size/2, -size/2,  -size/2 );
	glVertex3f( size/2, -size/2, -size/2 );

	glEnd();
	glPopMatrix();
	collplane.push_back(collisionplane(size/2, size/2, size/2,-size/2,  size/2, size/2,
						-size/2,  -size/2, size/2,size/2, -size/2, size/2,
							0.0,0.0,1.0));
	collplane.push_back(collisionplane(-size/2, size/2, size/2 ,-size/2,  size/2, -size/2,
						-size/2, -size/2,  -size/2,-size/2, -size/2,  size/2 ,
							-1.0,0.0,0.0));
	
	collplane.push_back(collisionplane(size/2, size/2,  -size/2,-size/2,  size/2,  -size/2,
						-size/2,  -size/2, -size/2, size/2, -size/2, -size/2,0.0,0.0,-1.0));
	collplane.push_back(collisionplane(size/2,  size/2,  -size/2,size/2,  size/2, size/2,-size/2,  -size/2, -size/2,
						size/2,  -size/2, -size/2,1.0,0.0,0.0));
};

void Dummy::drawSphere()
{
	float angle1, angle2;
	float xx,yy,zz,xxp,yyp,zzp;
	
	
	glPushMatrix();
	
	for(angle2 = -T_PI/2 ; angle2<=T_PI/2; angle2+= RESL)
	{
		glBegin(GL_QUAD_STRIP);
		for(angle1 =0.0 ; angle1 <=T_PI*2.0 + RESL ; angle1 += RESL)
		{
			yy = sin(angle2);
			xx = cos(angle1) * cos(angle2);
			zz = sin(angle1) * cos(angle2);
			
			yyp = sin(angle2 + RESL);
			xxp = cos(angle1) * cos(angle2 + RESL);
			zzp = sin(angle1) * cos(angle2 + RESL);

			glColor3f(0.0,1.0,0.0); 
			glVertex3f(xx,yy,zz);
			glColor3f(0.0,0.0,1.0);
			glVertex3f(xxp,yyp,zzp);
		}
		glEnd();
	}
	glPopMatrix();
};

void Dummy::drawEnvironment()
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

	collplane.push_back(collisionplane(-100.0,-1.0,-100.0,-100.0,-1.0,100.0,
						100.0,-1.0,100.0,100.0,-1.0,-100.0 ,
							0.000000, 1.000000, -0.000000));
	
};

void Dummy:: drawPlane(vector3d p1, vector3d p2, vector3d p3,vector3d p4)
{
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_QUADS);
		glVertex3f(p1.x, p1.y,p1.z);
		glVertex3f(p2.x, p2.y,p2.z);
		glVertex3f(p3.x, p3.y,p3.z);
		glVertex3f(p4.x, p4.y,p4.z);	
	glEnd();
	
	collplane.push_back(collisionplane(p1.x, p1.y,p1.z,p2.x, p2.y,p2.z,
				p3.x, p3.y,p3.z,p4.x, p4.y,p4.z,0.0,0.0,1.0));
};

std::vector<collisionplane> Dummy:: getCollisionPlane()
{
	return collplane;
};

