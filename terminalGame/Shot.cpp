#pragma once
#include <iostream>
#include <vector>
#include "Shot.h"
#include "Player.h"
#include "Level.h"

void Shot::move()
{
	this->y++;

}

Shot::Shot(int x, int y)
{

	this->x = x;
	this->y = y;


}

void Shot::setX(int x)
{
	this->x = x;
}

void Shot::setY(int y)
{
	this->y = y;
}

Shot::Shot()
{
	//this->x = 7;
}


