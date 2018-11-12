#ifndef GAME_H
#define GAME_H


#include <list>
#include <vector>
#include <ctime>
#include <algorithm>
#include "GameObject.h"
#include "ObjectFactory.h"
#include "EnumDirections.h"

class Game {
public:
	Game(int maxScore);
	void run();
private:
	void endGame(bool status);
	void gameUpdate();
	void findTarget(Location location);
	std::vector<std::shared_ptr<GameObject>> tanks;
	std::vector<std::shared_ptr<GameObject>> walls;
	std::list<std::shared_ptr<GameObject>> bullets;
	std::shared_ptr<GameObject> gold;
	ObjectFactory factory;
	int _maxScore;
	int score;
	double startTime;
	double lastTime;
	bool notGameEnd;
};

#endif // !GAME_H