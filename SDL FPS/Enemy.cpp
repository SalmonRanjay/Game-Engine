#include "Enemy.h"

Enemy::Enemy(‌int h, int str, float sp,collisionsphere ccs)
{
	health = h;
	strength = str;
	speed = sp;
	cs = ccs;
	iswalk true;
	isattack=isdead= false;
};
Enemy::~Enemy()
{

};
Enemy::bool update(std::vector<collisionplane>& col, vectorrd playerloc)
{
	if(!isdead)
	{
		direction.change(playerloc-cs.center);
		direction.normalize();

		vector3d newpos(cs.center);
		newpos+= direction * speed;
	}
};
Enemy::void show()
{

};
Enemy::bool setAttack(collisionsphere player)
{

};
Enemy::collisionsphere getCollisionSphere()
{

};
Enemy::void setLocation(vector3d newloc)
{

};
Enemy::void decreaseHealth(int num)
{

};
Enemy::int getHealth()
{
	return health;
};
Enemy::int getStrength()
{
	return strength;
};
Enemy::bool is Dead()
{

};
