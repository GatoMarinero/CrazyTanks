#include "Bullet.h"


CBullet::CBullet(int x, int y, int direct, bool f) : CGameObjectLocation(x, y, direct)
{
	from = f;
};

bool CBullet::getFrom()
{
	return from;
}