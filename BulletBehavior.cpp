#include "BulletBehavior.h"

BulletBehavior::BulletBehavior(std::shared_ptr<DrawEngine> drawEngine){
	_drawEngine=drawEngine;
}

Location BulletBehavior::act(GameObject* owner) {
	Location possibleColisionLocation = ObjectFactory::getLocationOnDirection(owner->getLocation(), owner->getDirection());
	if (_drawEngine->getCharAt(possibleColisionLocation) == ' '){
		_drawEngine->setCharAt(owner->getLocation(), ' ');
		owner->setLocation(possibleColisionLocation);
		_drawEngine->setCharAt(possibleColisionLocation, '*');
		return{ 0, 0 };
	}
	return possibleColisionLocation;
}
