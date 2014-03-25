#ifndef GAMELOGIC_H
#define GAMELOGIC_H
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "Camera.h"
#include "Vector.h"
#include "Collision.h"
#include "CollisionSphere.h"
#include "Dummy.h"
#include <iostream>
#include <cstdlib>
#include "Player.h"
using namespace std;

class GameLogic
{
	private:
	camera cam;
	Player* player1;
	
	void update();
	void show();

	public:
	unsigned int texture;
	Dummy obj;
	GameLogic();
	void createWindow();
	void start();
	
};
#endif

