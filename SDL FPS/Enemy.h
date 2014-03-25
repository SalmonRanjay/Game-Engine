#ifndef ENEMY_H
#define ENEMY_H
#include "Vector.h"
#include "CollisionSphere.h"
class Enemy
{
	int health, strength;
	float speed;
	vector3d direction,rotation;
	bool iswalk,isattack,isdead;
	collisionsphere cs;
	public:
	Enemy(‌int h, int str, float sp,collisionsphere ccs);
	~Enemy();
	bool update(std::vector<collisionplane>& col, vectorrd playerloc);
	void show();
	bool setAttack(collisionsphere player);
	collisionsphere getCollisionSphere();
	void setLocation(vector3d newloc);
	void decreaseHealth(int num);
	int getHealth();
	int getStrength();
	bool is Dead();
};

#endif
