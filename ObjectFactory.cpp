#include "ObjectFactory.h"


ObjectFactory::ObjectFactory(){
	drawEngine = std::make_shared<DrawEngine>() ;
	srand(clock());
}

std::shared_ptr<DrawEngine> ObjectFactory::getDrawEngine(){
	return drawEngine;
}

Location ObjectFactory::getRandomLocation(){
	Location location;
	bool isNotUnique=true;
	while (isNotUnique)
	{
		location.xCoord = 1 + rand() % 8;
		location.yCoord = 1 + rand() % 19;
		if (drawEngine->getCharAt(location) == ' ')
			isNotUnique = false;
	}
	return location;
}

Location ObjectFactory::getLocationOnDirection(Location location,Direction direction){
	if (direction==Direction::Up)
		--location.xCoord;
	else if (direction == Direction::Down)
		++location.xCoord;
	else if (direction == Direction::Right)
		++location.yCoord;
	else if (direction == Direction::Left)
		--location.yCoord;
	return location;
}

std::shared_ptr<GameObject> ObjectFactory::getPlayerTank() {
	Location location{ 10, 13 };
	auto obj = std::make_shared<GameObject>(3, location, Direction::Up);
	obj->setBehavior(getPlayerTankBehavior());
	return obj;
}

std::shared_ptr<GameObject> ObjectFactory::getBullet(Location location, Direction direction) {
	auto obj = std::make_shared<GameObject>(1, location, direction);
	obj->setBehavior(getBulletBehavior());
	drawEngine->setCharAt(location, '*');
	return obj;
}

std::shared_ptr<GameObject> ObjectFactory::getEnemyTank(Location location) {
	auto obj = std::make_shared<GameObject>(1, location, Direction::Down);
	obj->setBehavior(getEnemyTankBehavior());
	drawEngine->setCharAt(location, 'V');
	return obj;
}

std::shared_ptr<GameObject> ObjectFactory::getWall(Location location) {
	auto obj = std::make_shared<GameObject>(2, location, Direction::None);
	obj->setBehavior(getWallBehavior());
	drawEngine->setCharAt(location, 1);
	return obj;
}

std::shared_ptr<GameObject> ObjectFactory::getGold() {
	Location location = { 10, 10 };
	auto obj = std::make_shared<GameObject>(1, location, Direction::None);
	obj->setBehavior(getWallBehavior());
	drawEngine->setCharAt(location, 3);
	return obj;
}

std::shared_ptr<GameObjectBehavior> ObjectFactory::getPlayerTankBehavior(){
	return std::make_shared<PlayerTankBehavior>(drawEngine);
}

std::shared_ptr<GameObjectBehavior> ObjectFactory::getBulletBehavior(){
	return std::make_shared<BulletBehavior>(drawEngine);
}

std::shared_ptr<GameObjectBehavior> ObjectFactory::getEnemyTankBehavior(){
	return std::make_shared<EnemyTankBehavior>(drawEngine);
}

std::shared_ptr<GameObjectBehavior> ObjectFactory::getWallBehavior(){
	return std::make_shared<WallBehavior>();
};
