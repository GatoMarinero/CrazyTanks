#ifndef GAMEOBJECTBEHAVIOR_H
#define GAMEOBJECTBEHAVIOR_H

#include <memory>
#include "GameObject.h"
#include "Location.h"
#include "EnumDirections.h"

class GameObject;

class GameObjectBehavior {
public:
	virtual Location act(GameObject* owner) = 0;
	virtual ~GameObjectBehavior(){};
};

#endif
