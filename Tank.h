#ifndef TANK_H
#define TANK_H
#include "GameObjectLocation.h"
#include "Bullet.h"
class CTank :
	public CGameObjectLocation
{
public:
	CTank(int x, int y, int direct, bool player);
	bool IsPlayer();
	int isAlive();
	CBullet Fire();
	void setWho(bool p);
	void setLives(short liv);
	void getHit(bool from);
private:
	bool Player;
	short lives;
};

#endif
