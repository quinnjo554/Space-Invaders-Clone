#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include "Player.h"
#include <fstream>
#include <algorithm>
#include <sstream>


class Menu {
	
public:

	Menu();
	void displayMenu();
	void displayUpgradeMenu(Player& player);
	void upadateCursor();
	void setTopScores();
	int updateMenu();
	void setMenuNumber(int num);
	int getMenuNumber();
	bool isRunning = true;
	int menuAnsewer = 0;
	int writeToScoreFile();
	void writeNewScore(Player& player, int &minLine, std::string initials);
	void eraseFileLine(std::string path, std::string eraseLine);
	double getLowestScore();
	std::string getHighestScore();
	void bubbleSort(std::vector<std::string>& a);
private:
	int menuPos = 1;
	char* CursorPos;
	std::vector<std::string> topScores;
	std::vector<std::string> topInitials;
	std::fstream scoreFile; //ios::out for writing
	int fileSize = 0;



};
