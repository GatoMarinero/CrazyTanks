#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H

#include <memory>
#include <ctime>
#include "EnumDirections.h"
#include "DrawEngine.h"
#include "GameObject.h"
#include "GameObjectBehavior.h"
#include "PlayerTankBehavior.h"
#include "EnemyTankBehavior.h"
#include "BulletBehavior.h"
#include "WallBehavior.h"


class ObjectFactory {
public:
	ObjectFactory();
	static Location getLocationOnDirection(Location location, Direction direction);
	Location getRandomLocation();
	std::shared_ptr<DrawEngine> getDrawEngine();
	std::shared_ptr<GameObject> getPlayerTank();
	std::shared_ptr<GameObject> getBullet(Location location, Direction direction);
	std::shared_ptr<GameObject> getEnemyTank(Location location);
	std::shared_ptr<GameObject> getWall(Location location);
	std::shared_ptr<GameObject> getGold();
	std::shared_ptr<GameObjectBehavior> getPlayerTankBehavior();
	std::shared_ptr<GameObjectBehavior> getBulletBehavior();
	std::shared_ptr<GameObjectBehavior> getEnemyTankBehavior();
	std::shared_ptr<GameObjectBehavior> getWallBehavior();
private:
	std::shared_ptr<DrawEngine> drawEngine;
};

#endif // !OBJECTFACTORY_H