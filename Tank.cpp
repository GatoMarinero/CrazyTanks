#include "Tank.h"
#include <stdio.h>

CTank::CTank(int x, int y, int direct, bool player) :CGameObjectLocation(x, y, direct)
{
	setWho(player);
	if (player) setLives(3);
	else setLives(1);
}

bool CTank::IsPlayer()
{
	return Player;
}

int CTank::isAlive()
{
	return lives;
}

void CTank::setWho(bool p)
{
	Player = p;
}

void CTank::setLives(short liv)
{
	lives = liv;
}

void CTank::getHit(bool from)
{
	if (Player == 0 && from == 1)
	{
		lives = 0;
		setLocation(0, 0);
	}
	else
	if (Player == 1 && from == 0)
		lives--;
}

CBullet CTank::Fire()
{
	int x;
	int y;
	lookAt(getDirection(),x,y);
	CBullet temp(x, y, getDirection(),IsPlayer());
	return temp;
}




