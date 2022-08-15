#pragma once
#include "Enemy.h"

Enemy::Enemy()
	:x(0), y(0)
	{
		this->shotX = x;
		this->shotY = y;
		this->randNum = rand() % 300;
	}

Enemy::Enemy(int x, int y)
{
	
	
	this->x = x;
	this->y = y;
	this->shotX = x;
	this->shotY = y;
	
}

int Enemy::move(int& isShot, int& tick, int& shotNum, bool& hasShot)
{




	return 0;
}

void Enemy::setGraphic(char graphic)
{
	this->graphic = graphic;
}

void Enemy::setX(int x)
{
	this->x = x;
}

void Enemy::setY(int y)
{
	this->y = y;
}

void Enemy::setShotX(int x)
{
	this->shotX = x;
}

void Enemy::setShotY(int y)
{
	this->shotY = y;
}

void Enemy::setisShooting(bool shooting)
{
	this->isShooting = shooting;
}

int Enemy::getisShooting()
{
	return this->isShooting;
}

int Enemy::getX()
{
	return this->x;
}

int Enemy::getY()
{
	return this->y;
}

int Enemy::getnumOfshots()
{
	this->randNum = rand() % 300;
	return randNum;
}

int Enemy::getShotX()
{
	return this->shotX;
}

int Enemy::getShotY()
{
	return this->shotY;
}

char Enemy::getGraphic()
{
	return this->graphic;
}

bool Enemy::isEnemyDestroied()
{
	if (this->getGraphic() == ' ') {
		return true;
	}
	if (this->getGraphic() == '0') {
		return false;
	}
}

int Enemy::getNewRand()
{
	return 0;
}
