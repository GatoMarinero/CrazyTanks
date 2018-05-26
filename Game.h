#ifndef GAME_H
#define GAME_H
#include <vector>
#include <iostream>
#include "Bullet.h"
#include "Tank.h"
#include "DrawEngine.h"

class CGame
{
public:
	CGame();
	void run();
private:
	CDrawEngine drawEngine;
	double startTime;
	double lastTime;
	std::vector <CBullet> bullets;
	std::vector <CBullet> ::iterator bulletIterator; 
	std::vector <CTank> tanks;
	std::vector <CTank>::iterator tankIterator;
	void gameOver();
	void victory();
	void gameUpdate();
	void createTanks();
	void enemyTurn();
	void playerTurn();
	void bulletFlight();
	void tankMove(int direction);
	void tankFire();
	void findTarget(int x,int y);
	int score;
};
#endif
