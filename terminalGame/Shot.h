#pragma once
#include <iostream>
#include <vector>
#include <Windows.h>


class Shot {

public:
	
	void move();
	void setX(int x);
	void setY(int y);
	Shot(int x, int y);
	Shot();
	char shot = '|';
	int x =0;
	int y=0;



};