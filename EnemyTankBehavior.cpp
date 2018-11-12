#include "EnemyTankBehavior.h"

EnemyTankBehavior::EnemyTankBehavior(std::shared_ptr<DrawEngine> drawEngine){
	_drawEngine=drawEngine;
}

Location EnemyTankBehavior::act(GameObject* owner) {
	int chanse;
	Direction direction;
	Location locationForNewBullet = { 0, 0 };
	direction = static_cast<Direction>( 1 + rand() % 4);
	Location location = owner->getLocation();
	_drawEngine->setCharAt(location, ' ');
	location = ObjectFactory::getLocationOnDirection(location, direction);
	if (_drawEngine->getCharAt(location) == ' '){
		owner->setLocation(location);
	}
	owner->setDirection(direction);
	drawTank(owner);
	chanse =rand() % 4;
	if (!chanse){
		locationForNewBullet = ObjectFactory::getLocationOnDirection(owner->getLocation(), owner->getDirection());
	}
	return locationForNewBullet;
}

void EnemyTankBehavior::drawTank(GameObject* owner){
	int direction = static_cast<int>(owner->getDirection());
	std::string model = " AV<>";
	_drawEngine->setCharAt(owner->getLocation(), model[direction]);
}