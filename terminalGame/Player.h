#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include "Shot.h"

constexpr auto KEY_W = 119;
constexpr auto KEY_A = 97;
constexpr auto KEY_S = 115;
constexpr auto KEY_D = 100;
constexpr auto KEY_SPACE = 32;
constexpr auto KEY_P = 112;

class Player {

public:

	Player();
	//x and y coordinates are swapped oops
	Player(int lives, int numOfShots, int x, int y);
	int move(int& isShot, int &i, int& shotNum, bool& hasShot);
	
	void setX(int x);
	void setY(int y);
	void setShotX(int x);
	void setShotY(int y);
	void setLives(int lives);
	void setNumOfShots(int shots);
	void setShotSprite(char sprite);
	void setEnemiesKilled(int num);
	void setScore(double scoreNum);
	void setCash(double cash);
	int getX();
	int getY();
	int getLives();
	int getnumOfshots();
	int getShotX();
	int getShotY();
	int getEnemiesKilled();
	double getScore();
	char getSpite();
	double getCash();
	
private:
	
	char shotSprite = '|';
	int lives;
	int enemiesKilled = 0;
	int numOfshots;
	int x, y;
	double score = 0.0;
	double cash = 0.00;
	int shotX, shotY;
	

};