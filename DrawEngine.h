#ifndef DRAWENGINE_H
#define DRAWENGINE_H

#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include "Location.h"


class DrawEngine {
public:
	DrawEngine();
	void setCharAt(Location location,char c);
	char getCharAt(Location location) const;
	void printInfo(int score,int lives,double currentTime);
private:
	std::vector<std::string> gameMap;
	HANDLE outputHandle;
	COORD cursorPosition;
};

#endif