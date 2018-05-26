#include "GameObjectLocation.h"


CGameObjectLocation::CGameObjectLocation(int x, int y, int d)
{
	setLocation(x, y);
	setDirection(d);
}

void CGameObjectLocation::setDirection(int d)
{
	direction = d;
}

int CGameObjectLocation::getDirection()
{
	return direction;
}

void CGameObjectLocation::setLocation(int a, int b)
{
	x = a;
	y = b;
}

void CGameObjectLocation::lookAt(int direction, int &a, int &b)
{
	a = x;
	b = y;
	switch (direction)
	{
	case 0: {
				b--;
				break;
	}
	case 1: {
				b++;
				break;
	}
	case 2:  {
				a--;
				break;
	}
	case 3:{
			    a++;
			    break;
	}
	default:;
	}
}

void CGameObjectLocation::moveTo(int direction)
{
	switch (direction){
	case 0: {
				y--;
				break;
	}
	case 1: {
				y++;
				break;
	}
	case 2:  {
				x--;
				break;
	}
	case 3:{
			    x++;
			    break;
	}
	}
	setDirection(direction);
}