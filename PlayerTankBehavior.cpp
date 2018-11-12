#include "PlayerTankBehavior.h"

PlayerTankBehavior::PlayerTankBehavior(std::shared_ptr<DrawEngine> drawEngine){
	_drawEngine=drawEngine;
	drawEngine->setCharAt({ 10, 13 }, 30);
}

Location PlayerTankBehavior::act(GameObject* owner) {
	Location location = owner->getLocation();
	Location locationForNewBullet = { 0, 0 };
	Direction direction = Direction::None;
	char act=0;
	int ch;
	if (_kbhit())
	{
		act = _getch();
		ch = static_cast<int>(act);
		if (ch == 75){
			direction = Direction::Left;
		}
		else if (ch == 77){
			direction = Direction::Right;
		}
		else if (ch == 72){
			direction = Direction::Up;
		}
		else if (ch == 80){
			direction = Direction::Down;
		}
	}
	if (direction != Direction::None){
	_drawEngine->setCharAt(location, ' ');
	location = ObjectFactory::getLocationOnDirection(location, direction);
	if (_drawEngine->getCharAt(location) == ' '){
		owner->setLocation(location);
	}
	owner->setDirection(direction);
	drawTank(owner);
    }
	if (act == ' '){
		locationForNewBullet = ObjectFactory::getLocationOnDirection(owner->getLocation(),owner->getDirection());
	}
	return locationForNewBullet;
}

void PlayerTankBehavior::drawTank(GameObject* owner){
	int direction =static_cast<int>( owner->getDirection());
	char c = ' ';

	switch (direction)  {
	case 1:{
		c = (char)30;
		break;
	}
	case 2:{
		c = (char)31;
		break;
	}
	case 3:{
		c = (char)17;
		break;
	}
	case 4:{
		c = (char)16;
		break;
	}
	}
	_drawEngine->setCharAt(owner->getLocation(), c);
}

