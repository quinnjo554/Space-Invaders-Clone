#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <conio.h>
#include <string.h>
#include "Level.h"
#include <time.h>
#include<dos.h>
#include <chrono>
#include <thread>
#include <cstdlib>
#include "Menu.h"

class Game {

public:
	Game();
	void run();
	void upgradeeMenu();
	void startMenu(bool &game);
	void startNextLevel();
	void setNewHighScore();
	void GameOver();
	Player getPlayer();
	bool getMenu();
	bool getAppRunning();
	void set_cursor(bool visible);
	void setAppRunning(bool appRunning);
private:
	//entites go here
	Level level;
	Player player;
	Menu menu;
	bool isMenuRunning = true;
	bool appRunning = true;


};
