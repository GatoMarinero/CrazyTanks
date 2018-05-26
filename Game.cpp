#include "Game.h"
#include <conio.h>
#include <windows.h>
#include <time.h> 
CGame::CGame()
{
	createTanks();
	score=0;
	for (tankIterator=tanks.begin();tankIterator!=tanks.end();tankIterator++)  
 	{
 	int x,y;
	tankIterator->lookAt(4,x,y);
    	drawEngine.putTank(x,y,tankIterator->getDirection(),tankIterator->IsPlayer());	
	}
}
void CGame::run()
{	
	lastTime = 0;
	startTime = clock();
	while (1)
	{
		gameUpdate();
	}
}
void CGame::gameUpdate()
{
	double currentTime = clock() - lastTime;
	if (currentTime < 300)
		return;
	lastTime = clock();
	drawEngine.printInfo(score,tanks[0].isAlive(),lastTime);
	if(!bullets.empty())	
		{
		for (bulletIterator=bullets.begin();bulletIterator!=bullets.end();)
        		bulletFlight();
        		if (!tanks[0].isAlive()) gameOver();
		}
	for (tankIterator=tanks.begin();tankIterator!=tanks.end();tankIterator++)  
		if(tankIterator->isAlive()!=0)
	    {
			if (tankIterator->IsPlayer())
			playerTurn();
			else 
			enemyTurn();
		}	
}
void CGame::gameOver()
 {
 	system("cls");
	std::cout<<"                GAME OVER"<<std::endl;
	exit(0);
}
void CGame::victory()
 {
 	system("cls");
	std::cout<<"                 VICTORY"<<std::endl;
	exit(0);
 }
void CGame::createTanks()
 {
 	CTank ptank(10,13,2,1);
 	tanks.push_back(ptank);
 	CTank tank1(1+rand()%3,1+rand()%3,1,0);
 	tanks.push_back(tank1);
 	CTank tank2(3+rand()%3,3+rand()%6,2,0);
 	tanks.push_back(tank2);
 	CTank tank3(5+rand()%3,9+rand()%3,3,0);
	tanks.push_back(tank3);
 	CTank tank4(1+rand()%3,5+rand()%6,0,0);
 	tanks.push_back(tank4);
	CTank tank5(3+rand()%3,9+rand()%9,1,0);
 	tanks.push_back(tank5);
 }
void CGame::playerTurn()
 {
    char act;
    int ch;	
    if ( kbhit() )
    {
        act= getch();
        ch = static_cast<int>(act);
        if (ch == 75)
            tankMove(0) ;
        else if (ch == 77)
      	    tankMove(1) ;
   	    else if (ch == 72)
        	tankMove(2) ;
	    else if (ch == 80)
            tankMove(3) ; 
 	    if (act==' ')
	 	   tankFire();
	}
}
void CGame ::enemyTurn ()
	{
	int chanse;	
	int direct;	
	direct=rand()%4;
	tankMove(direct);
   	chanse=rand()%4;
    if(!chanse)
	    tankFire();
}
void CGame ::tankMove(int direction)
 {
 	int x,y;
 	tankIterator->lookAt(direction,x,y);
 	if (drawEngine.IsEmptyAt(x,y))
	{
		tankIterator->lookAt(4,x,y);
		drawEngine.clearAt(x,y);
		tankIterator->lookAt(direction,x,y);
		tankIterator->moveTo(direction);		
		drawEngine.putTank(x,y,tankIterator->getDirection(),tankIterator->IsPlayer());
		}
	else tankIterator->setDirection(direction);
 }
void CGame ::tankFire()
 {
 	int x,y;
 	tankIterator->lookAt(tankIterator->getDirection(),x,y);
	if (drawEngine.IsEmptyAt(x,y))
	{
		drawEngine.putBullet(x,y);	
		bullets.push_back(tankIterator->Fire());
				}
	else
		{
		if(drawEngine.charCompare(x,y,(char)1))
		 drawEngine.clearAt(x,y);
				}
 }
void CGame::bulletFlight()
 { 
    int x,y; 
	bulletIterator->lookAt(bulletIterator->getDirection(),x,y);
	if (drawEngine.IsEmptyAt(x,y)) 
		{
		drawEngine.putBullet(x,y);
		bulletIterator->lookAt(4,x,y);
	    drawEngine.clearAt(x,y);
		bulletIterator->moveTo(bulletIterator->getDirection());
		bulletIterator++;
		}
	else
		{	
		findTarget(x,y);
		bulletIterator->lookAt(4,x,y);
	    drawEngine.clearAt(x,y);		
		bulletIterator= bullets.erase(bulletIterator);
		}
}
 
  void CGame:: findTarget(int x,int y)
 {  
	 int a,b;
	 if(drawEngine.charCompare(x,y,(char)3))
		 gameOver();
	 if(drawEngine.charCompare(x,y,(char)1))
		 drawEngine.clearAt(x,y);
	 for(tankIterator=tanks.begin();tankIterator!=tanks.end();tankIterator++)
		{
			tankIterator->lookAt(4,a,b);
			if (x==a&&y==b)
			   	{
			      	if (bulletIterator->getFrom()==1)
					{
					score++;
					drawEngine.clearAt(x,y);	
					if (score==5) victory();
					}
                		   tankIterator->getHit(bulletIterator->getFrom());									 
					 }	 
		}			 
 }   
 
