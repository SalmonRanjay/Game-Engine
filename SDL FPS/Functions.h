#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
//#include <math.h>
#include <cmath>
#include <cstdlib>
#include "Vector.h"
using namespace std;
#ifndef FUNCTION_H
#define FUNCTION_H
#define T_PI 3.1415926535
#define RESL 0.05


class Functions
{	
	public:
	float camX;
	float camY;
	float camZ;
	float camYaw;
	float camPitch;
	bool mousein;
	Functions();
	void lockCamera();
	void moveCamera(float,float);
	void moveCameraUp(float,float);
	void Control(float,float,bool);
	void updateCamera();
	void drawCube(float size);
	//center point vector3d, direction vector, start point of ray,and radius
	bool raySphereIntersection(float xc,float yc,float zc,float xd, float yd, float zd, float xs, float ys, float zs, float r,float* dist=NULL, vector3d* point=NULL);
	void drawSphere();
	void drawEnvironment();
	float trianglearea(vector3d p1,vector3d p2,vector3d p3); // calculate area of triangles within quads
	//normal vector points, start point of ray,reflection vector,points of quad 
	bool rayplane(float nx,float ny,float nz,float xs,float ys,float zs,float xd,float yd,float zd,vector3d p1,vector3d p2,vector3d p3,vector3d p4,float* dist=NULL, vector3d* point=NULL);
	void drawPlane(vector3d p1, vector3d p2, vector3d p3,vector3d p4);
	bool spheresphere(vector3d& c1,float r1,vector3d c2,float r2);
	float pointdistance(vector3d c1,vector3d c2);
	void moveTo(vector3d c);
	vector3d camPos();
	bool sphereplane(vector3d& sp, vector3d vn,vector3d p1,vector3d p2,vector3d p3, vector3d p4,float r);
	loadTexture(const char* filename);
		
};
#endif
