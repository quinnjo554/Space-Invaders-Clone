#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include "Shot.h"


class Enemy {

public:

	Enemy();
	//x and y coordinates are swapped oops
	Enemy(int x, int y);

	

	int move(int& isShot, int& tick, int& shotNum, bool& hasShot);
	void setGraphic(char graphic);
	void setX(int x);
	void setY(int y);
	void setShotX(int x);
	void setShotY(int y);
	void setisShooting(bool shooting);
	int getisShooting();
	int getX();
	int getY();
	int getnumOfshots();
	int getShotX();
	int getShotY();
	char getGraphic();
	bool isEnemyDestroied();
	int getNewRand();
	
private:
	int numOfshots;
	int x, y;
	char graphic = '0';
	bool isDestroied = false;
	int shotX, shotY;
	int randNum;
	bool isShooting = false;
};