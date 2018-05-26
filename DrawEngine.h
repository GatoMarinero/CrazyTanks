#ifndef DRAWENGINE_H
#define DRAWENGINE_H
#include <string>
#include <vector>
#include <iostream>
#include <windows.h>
class CDrawEngine {
public:
	CDrawEngine();
	void putTank(int x, int y, int direction, bool IsPlayer);
	bool IsEmptyAt(int x, int y);
	void putBullet(int x, int y);
	void clearAt(int x, int y);
	bool charCompare(int x,int y,char t);
	void printInfo(int score,int lives,double currentTime);
private:
	void createMap();
	std::vector <std::string> gameMap;
	std::string ModelP;
	std::string ModelE;
	HANDLE outputHandle;
	COORD cursorPosition;
};
#endif                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
