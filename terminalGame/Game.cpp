#include "Game.h"

#define CLEAR system("cls")

void Game::run()
{
    
	//logic
	using namespace std::this_thread;     // sleep_for, sleep_until
	using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
	using std::chrono::system_clock;
	bool game = true;
	int isShot = -1;
	unsigned long startTime_;
	unsigned int diffInMilliSeconds;
	int tick = 0;
	int shotNum = 1;
	int xPos =0;
	int yPos = 0;
	bool isFiring = false;
	int iterations = 0;
	
	while (getAppRunning() == true) {

		
		game = true;
		this->startMenu(game);
		
		//clear console
		CLEAR;
		//put highscores here
		system("color a");
		set_cursor(false);
		while (game) {
			
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
			//keeps the terminal from scrolling
				//draw the level
			level.drawLevel(menu);
			
			//only moves player if the kb is hit
			if (_kbhit()) {
				xPos = player.move(isShot, tick, shotNum, isFiring);
			}
			//moves player
			level.updatePlayerMovement(player);
			//only draws shot when iteration is 5
			level.drawShot(player, isShot, tick, iterations);
			//removes trail
			level.updatePlayerShot(player, iterations);

			level.updateEnemy(iterations, player);
			level.updateEnemyMovement(tick, player);
			level.updateEnemyShot(iterations, player);
			if (player.getLives() < 1) {
				game = false;
				player.setLives(3);
			}

			this->startNextLevel();

			if ((iterations % 60 == 0)) {
				tick++;
				iterations = 0;
			}
			if (tick % 10 == 0) {
				tick = 0;
			}
			std::cout << "BULLETS:" << player.getnumOfshots() <<"\n";
			std::cout << "LEVEL:" << level.getLevelCount() << "  SCORE:" << player.getScore() << "\n";
			std::cout << "MONEY:" << player.getCash() << "  LIVES:" << player.getLives() << "\n";
			
			iterations++;

		}
		
		CLEAR;
		this->GameOver();
		CLEAR;
		this->setNewHighScore();
	}
	}

void Game::upgradeeMenu()
{
	CLEAR;
	int menuSelection = 3;
bool isRunning = true;
while (isRunning) {
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });

	this->menu.displayUpgradeMenu(player);
	menuSelection = this->menu.updateMenu();
	this->menu.upadateCursor();

	if (menuSelection == 0 && player.getCash() >=100) {
		player.setNumOfShots(player.getnumOfshots() + 20);
		player.setCash(player.getCash() - 100);
	}
	if (menuSelection == 1) {
		this->setAppRunning(false);
		isRunning = false;
	}


}


}
	



void Game::startMenu(bool &game)
{
	int menuSelection =3;
	bool isRunning = true;
	while (isRunning) {
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
		
		this->menu.displayMenu();
		menuSelection = this->menu.updateMenu();
		this->menu.upadateCursor();
		
		if (menuSelection == 0) {
			isRunning = false;
		}
		if (menuSelection == 1) {
			this->setAppRunning(false);
			game = false;
			isRunning = false;
		}


	}


}

void Game::startNextLevel()
{
	using namespace std::this_thread;     // sleep_for, sleep_until
	using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
	using std::chrono::system_clock;
	if (player.getEnemiesKilled() == level.getEnemyCount()) {

		
		level.setLevelCount(level.getLevelCount() + 1);
		player.setEnemiesKilled(0);
		this->upgradeeMenu();
		sleep_for(0.05ns);
		CLEAR;
		std::cout << "\t==================================\n" << "\t           START LEVEL:" << level.getLevelCount() << "\n" << "\t==================================\n";
		sleep_until(system_clock::now() + 5s);
		CLEAR;
		
		
			//level.newBossLevel(player);
			level.newLevel(player);
		
	}
}

void Game::setNewHighScore()
{
	if (this->getAppRunning()) {
		if (menu.getLowestScore() < player.getScore()) {

			std::cout << "======================================================================\n";
			std::cout << "                       NEW HIGH SCORE!                                \n";
			std::cout << "======================================================================\n";
			std::string initials;

			std::cout << "ENTER INTITALS:";
			std::cin >> initials;

			while (initials.size() > 3 || initials.size() <= 0) {
				std::cout << "ENTER INTITALS:";
				std::cin >> initials;
			}
			for (int i = 0; i < initials.size(); i++) {
				putchar(std::toupper(initials[i]));
			}

			int line;
			line = menu.writeToScoreFile();
			menu.writeNewScore(player, line, initials);
		}

	}
}

void Game::GameOver()
{
	using namespace std::this_thread;     // sleep_for, sleep_until
	using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
	using std::chrono::system_clock;
	
	if (this->getAppRunning()) {
		sleep_for(0.05ns);
		std::cout << "                  ---------------------------------------------------------\n";
		std::cout << "                                        GAME OVER      \n";
		std::cout << "                  ----------------------------------------------------------\n";
		sleep_until(system_clock::now() + 5s);
	}
}

Player Game::getPlayer()
{
	return this->player;
}

bool Game::getMenu()
{
	bool isRunning = this->isMenuRunning;
	return isRunning;
}

bool Game::getAppRunning()
{
	return this->appRunning;
}




void Game::setAppRunning(bool appRunning)
{
	this->appRunning = appRunning;
}

void Game::set_cursor(bool visible) {

	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = visible;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);


}


Game::Game():
	player(3,40,5,20), level(10)
{
	


}