#ifndef BULLETBEHAVIOR_H
#define BULLETBEHAVIOR_H

#include "GameObjectBehavior.h"
#include "ObjectFactory.h"

class BulletBehavior : public GameObjectBehavior {
public:
	BulletBehavior(std::shared_ptr<DrawEngine> drawEngine);
	virtual Location act(GameObject* owner);
private:
	std::shared_ptr<DrawEngine> _drawEngine;
};


#endif