#include "GameObject.h"

GameObject::GameObject(int lives,Location location,Direction direction){
	_lives=lives;
	_location=location;
	_direction=direction;
}

void GameObject::setBehavior(std::shared_ptr<GameObjectBehavior> objectBehavior){
	_objectBehavior = objectBehavior;
}

Location GameObject::act() {
	return _objectBehavior->act(this);
}

void GameObject::getHit() {
	--_lives;
}

int GameObject::getLives() const {
	return _lives;
}

void GameObject::setLocation(Location location){
	_location=location;
}

void GameObject::setDirection(Direction direction){
	_direction = direction;
}

Location GameObject::getLocation() const{
	return _location;
}

Direction GameObject::getDirection() const{
    return _direction; 
}


