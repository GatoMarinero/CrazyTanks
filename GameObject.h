#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <memory> 

#include "Location.h"
#include "DrawEngine.h"
#include "GameObjectBehavior.h"
#include "EnumDirections.h"

class GameObjectBehavior;

class GameObject {
public:
	GameObject(int lives,Location location,Direction direction);
	Location act();
	void getHit();
	void setBehavior(std::shared_ptr<GameObjectBehavior> objectBehavior);
	int getLives() const;
	Location getLocation() const;
	void setLocation(Location location);
	void setDirection(Direction direction);
	Direction getDirection() const;
private:
	int _lives;
	std::shared_ptr<GameObjectBehavior> _objectBehavior;
	Location _location;
	Direction _direction;	

};

#endif // !GAMEOBJECT_H