
#include "Menu.h"


Menu::Menu()
{
	
	CursorPos = (char*)malloc(sizeof(char) * 2);
	



	CursorPos[0] = ' ';
	CursorPos[1] = ' ';


	setTopScores();

}

void Menu::displayMenu()
{
	//setTopScores();

	std::cout << "       ===================================================================================================" << "\n";
	std::cout << "                                               ARCADE                                             " << "\n";
	std::cout << "       ===================================================================================================" << "\n";
	std::cout << "                                                                                                     " << "\n";
	std::cout << "                                                                                                     " << "\n";
	std::cout << "                                                                                                     " << "\n";
	std::cout << "                                            HIGH SCORES                                                 " << "\n";
	std::cout << "                                                                                                     " << "\n";
	std::cout << "                                  SCORE           NAME       " << "      RANK" << "\n";
	std::cout << "                                    " << topScores[4] << "                1                \n";
	std::cout << "                                    " << topScores[3] << "                2                \n" ;
	std::cout << "                                    " << topScores[2] << "                3                \n" ;
	std::cout << "                                    " << topScores[1] << "                4                \n" ;
	std::cout << "                                    " << topScores[0] << "                5                \n" ;
	std::cout << "                                                                                                     " << "\n";
	std::cout << "                                                                                                     " << "\n";
	std::cout << "                                                                                                     " << "\n";
	std::cout << "                                                                                                     " << "\n";
	std::cout << "                                           " << CursorPos[0] << " -Start-                                                    " << "\n";
	std::cout << "                                           " << CursorPos[1] << " -Quit-                                                  " << "\n";
	std::cout << "                                                                                                     " << "\n";
	std::cout << "     ___________________________________________________________________________________________________ " << "\n";

}

void Menu::displayUpgradeMenu(Player& player)
{

	std::cout << "   ===================================================================================================" << "\n";
	std::cout << "                                         UPGRADE                                             " << "\n";
	std::cout << "   ===================================================================================================" << "\n";
	std::cout << "                                                                                                     " << "\n";
	std::cout << "                               " << "Player Money-" << player.getCash() << "\n";
	std::cout << "                               " << "PLayer Bullets-" << player.getnumOfshots() << "\n";
	std::cout << "                                                                                                     " << "\n";
	std::cout << "                                                                                                     " << "\n";
	std::cout << "       " << CursorPos[0] << "        Bullets-20           $100 \n";
	std::cout << "       " << CursorPos[1] << "        Continue              \n";
	
}





void Menu::upadateCursor()
{
	CursorPos[this->getMenuNumber()] = '>';
	if (this->getMenuNumber() == 0) {
		CursorPos[this->getMenuNumber() +1] = ' ';
	}
	if (this->getMenuNumber() == 1) {
		CursorPos[this->getMenuNumber() - 1] = ' ';
	}
	

}

void Menu::setTopScores()
{
	std::string line;
	scoreFile.open("Scores.txt", std::ios::in);

	//put lines into scores vector
	if (scoreFile.is_open()) {
		while (!scoreFile.eof()) {
			std::getline(scoreFile, line);
			topScores.push_back(line);
		}
	}
	scoreFile.close();

	this->bubbleSort(topScores);

	
	
}


int Menu::updateMenu()
{


	char key = _getch();
	int value = key;


	switch (key) {

	case KEY_W:
		this->setMenuNumber(this->getMenuNumber() - 1);
		if (this->getMenuNumber() <= 0) {
			this->setMenuNumber(0);
		}
		break;

	case KEY_S:
		this->setMenuNumber(this->getMenuNumber() + 1);
		if (this->getMenuNumber() >=1 ) {
			this->setMenuNumber(1);
		}
			
		break;
	

	case KEY_SPACE:
			
		menuAnsewer = this->getMenuNumber();
		return menuAnsewer;
		break;
		
		
	}
	
	
}

void Menu::setMenuNumber(int num)
{
	this->menuPos = num;
}

int Menu::getMenuNumber()
{
	return this->menuPos;
}

int Menu::writeToScoreFile()
{
	//find the smallest value in the file 
	//call erase line on that line
	//write the new score to the same line 
	//put the file into the score array
	//sort the array 
	//then display



	//check if any file score is less than the player score that game
	//if so do above\



	//since topscore is sorted just erase the line topscore[4] form the first and second
	std::string scoreRemove = " ";
	scoreRemove = this->topScores[0];

	eraseFileLine("Scores.txt", topScores[0]);
	return 0;

}

void Menu::writeNewScore(Player& player, int& minLine, std::string initials)
{
	std::fstream initialsFile;
	std::string line;
	int lineNum = 0;
	scoreFile.open("Scores.txt", std::ios::app);

	if (scoreFile.is_open()) {
		
		while (lineNum < 6) {
			
			
			if (lineNum == 0) {
				scoreFile << player.getScore() << "     :     " << initials;
			}
			lineNum++;
		}

	}
	scoreFile.close();

}



void Menu::eraseFileLine(std::string path, std::string eraseLine)
{
	std::string line;
	std::ifstream fin;

	fin.open(path);
	// contents of path must be copied to a temp file then
	// renamed back to the path file
	std::ofstream temp;
	temp.open("temp.txt");

	while (getline(fin, line)) {
		// write all lines to temp other than the line marked for erasing
		if (line != eraseLine)
			temp << line << std::endl;
	}

	temp.close();
	fin.close();

	// required conversion for remove and rename functions
	const char* p = path.c_str();
	remove(p);
	rename("temp.txt", p);
}

double Menu::getLowestScore()
{
	double number;
	double min = INT_MAX;
	for (int i = 0; i < topScores.size(); i++) {
		number = std::stod(topScores[i], nullptr);
		if (number < min) {
			min = number;
		}

	}

	return min;
}

std::string Menu::getHighestScore()
{
	return topScores[4];
}

void Menu::bubbleSort(std::vector<std::string>& a)
{
	bool swapp = true;
	while (swapp) {
		swapp = false;
		for (size_t i = 0; i < a.size() - 1; i++) {
			
			double d1 = atof(a[i].c_str());
			double d2 = atof(a[i +1].c_str());
			if (d1 > d2) {
				std::swap(a[i], a[i + 1]);
				swapp = true;
			}
		}
	}
}





