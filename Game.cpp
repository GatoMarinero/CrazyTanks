#include "Game.h"

Game::Game(int maxScore) :factory(), tanks(), bullets(), _maxScore(maxScore){
	notGameEnd = true;
	score = 0;
	tanks.push_back(factory.getPlayerTank());
	for (int i = 0; i < maxScore; ++i){
		tanks.push_back(factory.getEnemyTank(factory.getRandomLocation()));
	}
	for (int i = 0; i < 25 - _maxScore; ++i){
		walls.push_back(factory.getWall(factory.getRandomLocation()));

	walls.push_back(factory.getWall({ 9, 9 }));
	walls.push_back(factory.getWall({ 9, 10 }));
	walls.push_back(factory.getWall({ 9, 11 }));
	walls.push_back(factory.getWall({ 10, 9 }));
	walls.push_back(factory.getWall({ 10, 11 }));

	gold = factory.getGold();
	}

}
void Game::run() {
	lastTime = 0;
	startTime = clock();
	while (notGameEnd)
	{
		gameUpdate();
	}
}

void Game::gameUpdate(){
	Location location;
	Location nullLoc = { 0, 0 };
	double currentTime = clock() - lastTime;
	if (currentTime < 250)
		return;
	lastTime = clock();
	if (!bullets.empty()){
		for (auto it = bullets.begin(); it != bullets.end();){
			location=(*it)->act();
			if (location != nullLoc){
				findTarget(location);
				factory.getDrawEngine()->setCharAt((*it)->getLocation(), ' ');
				it = bullets.erase(it);
			}
			else ++it;
		}
	}
	for (unsigned i =0; i< tanks.size();++i){
		location=tanks[i]->act();
		if (location != nullLoc)
		if (factory.getDrawEngine()->getCharAt(location) == ' ')
			bullets.push_back(factory.getBullet(location, tanks[i]->getDirection()));
		else findTarget(location);
	}
	if (score == _maxScore){
		endGame(1);
	}
	factory.getDrawEngine()->printInfo(score, tanks[0]->getLives(), currentTime);
}

void Game::findTarget(Location location){
	char c = factory.getDrawEngine()->getCharAt(location);
	if (c == (char)2) return;
	if (c == (char)1){
		unsigned i = 0;
		for (; i < walls.size(); ++i){
			Location target = walls[i]->getLocation();
			if (location == target)
				break;
		}
		walls[i]->getHit();
		if (walls[i]->getLives() == 0){
			factory.getDrawEngine()->setCharAt(location, ' ');
			walls.erase(walls.begin() + i);
		}
		return;
	}
	else if (c == '*'){
		auto it = std::find_if(bullets.begin(), bullets.end(), [location](std::shared_ptr<GameObject> object){
			Location target = object->getLocation();
			return location == target;});
		if (it != bullets.end()){
			bullets.erase(it);
			factory.getDrawEngine()->setCharAt(location, ' ');
		}
	}
	else if (c == (char)3){
		endGame(0);
	}
	else {
		unsigned i = 0;
		for (; i < tanks.size(); ++i){
			Location target = tanks[i]->getLocation();
			if (location == target)
				break;
		}
		tanks[i]->getHit();
		if (tanks[i]->getLives() == 0){
			if (i == 0) endGame(0);
			else {
				factory.getDrawEngine()->setCharAt(location, ' ');
				tanks.erase(tanks.begin() + i);
				++score;
			}
		}
		return;
	}
}

void Game::endGame(bool status){
	notGameEnd = false;
	std::string message;
	if (status == 1)
		 message = "                 VICTORY";
	else message = "                GAME OVER";
	system("cls");
	std::cout << message << std::endl;
}