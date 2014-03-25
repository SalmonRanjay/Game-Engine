#ifndef DUMMY_H
#define DUMMY_H
#include <GL/gl.h>
#include <GL/glu.h>
#include <cmath>
#include <cstdlib>
#include "Vector.h"
#include <vector>
#include "CollisionPlane.h"
#define T_PI 3.1415926535
#define RESL 0.05

class Dummy
{
	public:
	std::vector<collisionplane> collplane;
	std::vector<vector3d> normals;
	void drawCube(float size);
	void drawSphere();
	void drawEnvironment();
	void drawPlane(vector3d p1, vector3d p2, vector3d p3,vector3d p4);
	std::vector<collisionplane> getCollisionPlane();
};
#endif
