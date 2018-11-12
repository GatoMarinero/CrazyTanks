#ifndef ENEMYTANKBEHAVIOR_H
#define ENEMYTANKBEHAVIOR_H

#include "GameObjectBehavior.h"
#include "ObjectFactory.h"

class EnemyTankBehavior : public GameObjectBehavior {
public:
	EnemyTankBehavior(std::shared_ptr<DrawEngine> drawEngine);
	virtual Location act(GameObject* owner) override;
private:
	std::shared_ptr<DrawEngine> _drawEngine;
	void drawTank(GameObject* owner);
};

#endif