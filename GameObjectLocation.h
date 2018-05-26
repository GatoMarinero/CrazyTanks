#ifndef GAMEOBJECTLOCATION_H
#define GAMEOBJECTLOCATION_H
class CGameObjectLocation
{
public:
	CGameObjectLocation(int x, int y, int d);
	void setDirection(int d);
	int getDirection();
	void setLocation(int a,int b);
	void lookAt(int direction,int &a,int &b);
	void moveTo(int direction);
private:
	int x;
	int y;
	int direction;

};

#endif
