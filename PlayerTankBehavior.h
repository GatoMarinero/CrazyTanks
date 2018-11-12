#ifndef PLAYERTANKBEHAVIOR_H
#define PLAYERTANKBEHAVIOR_H


#include <string>
#include <conio.h>
#include "GameObjectBehavior.h"
#include "ObjectFactory.h"


class PlayerTankBehavior : public GameObjectBehavior {
public:
	PlayerTankBehavior(std::shared_ptr<DrawEngine> drawEngine);
	virtual Location act(GameObject* owner) override;
private:
	void drawTank(GameObject* owner);
	std::shared_ptr<DrawEngine> _drawEngine;
};

#endif // !PLAYERTANKBEHAVIOR_H