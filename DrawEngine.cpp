#include "DrawEngine.h"
#include <ctime>


CDrawEngine::CDrawEngine()
{
	outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(outputHandle, &cursorInfo);
	cursorInfo.bVisible = FALSE;
	cursorInfo.dwSize = 1;
	SetConsoleCursorInfo(outputHandle, &cursorInfo);
	ModelP="<>AV";
	ModelE="{}MW";
	createMap();
}

void CDrawEngine::createMap() {
	srand((unsigned int)time(0));
	gameMap.clear();
	gameMap.push_back("_____________________");
	gameMap.push_back("|                   |");
	gameMap.push_back("|                   |");
	gameMap.push_back("|                   |");
	gameMap.push_back("|                   |");
	gameMap.push_back("|                   |");
	gameMap.push_back("|                   |");
	gameMap.push_back("|                   |");
	gameMap.push_back("|                   |");
	gameMap.push_back("|                   |");
	gameMap.push_back("|                   |");
	gameMap.push_back("_____________________");
	for (int i = 0; i<20; i++)
	{
		gameMap[1 + rand() % 8][1 + rand() % 19] = (char)1;
	}
	gameMap[9][9] = (char)1;
	gameMap[9][10] = (char)1;
	gameMap[9][11] = (char)1;
	gameMap[10][9] = (char)1;
	gameMap[10][10] = (char)3;
	gameMap[10][11] = (char)1;
	std::vector <std::string>::iterator i;
	for ( i = gameMap.begin(); i != gameMap.end(); i++)
		std::cout << *i << std::endl;
}
void CDrawEngine::putTank(int x, int y, int direction, bool IsPlayer) {
	std::string m;
	if (IsPlayer)
		m = ModelP;
	else
		m = ModelE;
	gameMap[x][y] = m[direction];
	cursorPosition.X = y;
	cursorPosition.Y = x;
	SetConsoleCursorPosition(outputHandle, cursorPosition);
	std::cout << m[direction];
}

bool CDrawEngine::IsEmptyAt(int x, int y)
{
	if (gameMap[x][y] == ' ')
		return 1;
	else return 0;
}

void CDrawEngine::putBullet(int x, int y) {
	gameMap[x][y] = '*';
	cursorPosition.X = y;
	cursorPosition.Y = x;
	SetConsoleCursorPosition(outputHandle, cursorPosition);
	std::cout << '*';
}

bool CDrawEngine::charCompare(int x, int y, char t) {
	if (gameMap[x][y] == t)
		return 1;
	else return 0;
}

void CDrawEngine::clearAt(int x, int y)
{
	gameMap[x][y] = ' ';
	cursorPosition.X = y;
	cursorPosition.Y = x;
	SetConsoleCursorPosition(outputHandle, cursorPosition);
	std::cout << ' ';
}

void CDrawEngine::printInfo(int score,int lives,double currentTime)
{
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

