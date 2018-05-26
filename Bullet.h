#ifndef BULLET_H
#define BULLET_H
#include "GameObjectLocation.h"
class CBullet :
	public CGameObjectLocation
{
public:
	CBullet(int x, int y, int direct, bool f);
	bool getFrom();
private:
	bool from;
};
#endif
