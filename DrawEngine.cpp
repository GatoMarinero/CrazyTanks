#include "DrawEngine.h"

DrawEngine::DrawEngine(){
	outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(outputHandle, &cursorInfo);
	cursorInfo.bVisible = FALSE;
	cursorInfo.dwSize = 1;
	SetConsoleCursorInfo(outputHandle, &cursorInfo);
	gameMap={
		    	{"_____________________"},
		    	{"|                   |"},
		  		{"|                   |"},
				{"|                   |"},
				{"|                   |"},
				{"|                   |"},
				{"|                   |"},
				{"|                   |"},
				{"|                   |"},
				{"|                   |"},
				{"|                   |"},
				{"_____________________"}
			};
	for (auto it = gameMap.at(0).begin(); it != gameMap.at(0).end(); ++it)
		*it = (char)2;
	for (auto it = gameMap.at(11).begin(); it != gameMap.at(11).end(); ++it)
		*it = (char)2;
	for (auto it = gameMap.begin() + 1; it != gameMap.end() - 1; ++it){
		it->at(0) = it->at(20) = char(2);
	}

	for (auto it = gameMap.begin(); it != gameMap.end(); ++it)
		std::cout << *it << std::endl;
}

void DrawEngine::setCharAt(Location location,char c) {
	gameMap.at(location.xCoord).at(location.yCoord)=c;
	cursorPosition.X = location.yCoord;
	cursorPosition.Y = location.xCoord;
	SetConsoleCursorPosition(outputHandle, cursorPosition);
	std::cout << c;
}

char DrawEngine::getCharAt(Location location)const {
	return gameMap.at(location.xCoord).at(location.yCoord);
}

void DrawEngine::printInfo(int score,int lives,double currentTime){
	cursorPosition.X=25;
	cursorPosition.Y=5;
	SetConsoleCursorPosition(outputHandle, cursorPosition);
	std::cout<< "Score: "<<score << " Lives: "<< lives;
	cursorPosition.X=30;
	cursorPosition.Y=6;
	currentTime/=1000;
	int sec=(int)currentTime%60;
	int min=(int)currentTime/60; 
	SetConsoleCursorPosition(outputHandle, cursorPosition);
	std::cout<<min<<" : "<<sec<<"  ";
}
