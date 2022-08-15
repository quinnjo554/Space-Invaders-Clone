#pragma once
#include "Level.h"


Level::Level(int enemyCount) :
	enemyCount(enemyCount)
{
	
	//manually allocating memory for the arrays

	badGuys = (Enemy*)calloc((enemyCount), sizeof(Enemy));
	beatBadGuys = (int*)malloc(sizeof(int) * enemyCount);

	//rand spots for ememies
	std::srand(std::time(0));
		for (int i = 0; i < enemyCount; i++) {
			int x = (rand() % 17) + 1;
			int y = (rand() % 7) + 1;
			Enemy enemy(x, y);
			badGuys[i] = enemy;
		}
		randomEnemy = rand() % 100;


}

Level::~Level()
{
}

void Level::newLevel(Player &player)
{
	
	//incrament the numb of enemies untill 50
	
		enemyCount += 5;

		if (enemyCount >= 50) {
			enemyCount = 50;
		}

		//manually allocating with calloc
		badGuys = (Enemy*)calloc(enemyCount, sizeof(Enemy));
		std::srand(std::time(0));
		//this could also fill the same position with two enemies needing multiple shots to kill
		for (int i = 0; i < enemyCount; i++) {
			//get rand positions
			int x = (rand() % 17) + 1;
			int y = (rand() % 7) + 1;
			Enemy enemy(x, y);
			//fill the array with the Enemy
			badGuys[i] = enemy;

		}


		//give the player cash to spend
		//set max of 500

		player.setCash((player.getCash() + 100) + (double)(player.getScore() * 0.01) *2);
	}

	//if level is %3 =0;
	//print the boss enemy





void Level::newBossLevel(Player& player)
{
	this->setEnemyCount(20);
	badGuys = (Enemy*)calloc(this->getEnemyCount(), sizeof(Enemy));
	//top
	badGuys[0] = Enemy(4, 2);
	badGuys[1] = Enemy(5, 2);
	badGuys[2] = Enemy(6, 2);
	badGuys[3] = Enemy(7, 2);
	//right side
	badGuys[4] = Enemy(8, 3);
	badGuys[5] = Enemy(8, 4);
	badGuys[6] = Enemy(8, 5);
	
	//bottom
	badGuys[7] = Enemy(7, 6);
	badGuys[8] = Enemy(6, 6);
	badGuys[9] = Enemy(5, 6);
	badGuys[11] = Enemy(4, 6);

	badGuys[12] = Enemy(3, 5);
	badGuys[13] = Enemy(3, 4);
	badGuys[14] = Enemy(3, 3);

	badGuys[15] = Enemy(3, 5);
	badGuys[16] = Enemy(3, 4);
	badGuys[17] = Enemy(3, 3);

	badGuys[18] = Enemy(4, 6);
	badGuys[19] = Enemy(4, 6);
	  
	
	

	
	
}




 void Level::updatePlayerMovement(Player &player)
{

	 level[player.getY()][player.getX()] = '^';

	 //delete the extra ^ to left or right
	 if (KEY_A) {
		 level[player.getY()][double(player.getX())-1] = ' ';
		 
	 }
	 if (KEY_D) {
		 level[player.getY()][double(player.getX())+1] = ' ';
	 }


}

 void Level::updatePlayerShot(Player& player , int& iteration) {
	 if (iteration % 6 == 0) {
		 level[(double)player.getShotY() + 1][player.getShotX()] = ' ';
	 }
 }

 void Level::updateEnemy(int& tick, Player& player)
 {
	 
		 for (int i = 0; i < this->enemyCount; i++) {
         level[badGuys[i].getY()][badGuys[i].getX()] = badGuys[i].getGraphic();

			 if (level[badGuys[i].getY()][badGuys[i].getX()] == level[player.getShotY()][player.getShotX()] && badGuys[i].isEnemyDestroied() == false) {
				 //sets graphic to ' ' making it destroied
				 badGuys[i].setGraphic(' ');
				 PlaySound(TEXT("C:\\Users\\quinn\\source\\repos\\terminalGame\\invaderkilled"), NULL, SND_FILENAME | SND_ASYNC | SND_NOWAIT);
				 level[badGuys[i].getY()][badGuys[i].getX()] = ' ';
				 badGuys[i].setY(0);
				 badGuys[i].setX(0);
				 player.setShotY(0);
				 player.setScore(player.getScore() +1000);
				 player.setEnemiesKilled(player.getEnemiesKilled() + 1);
			 }

		 }

	 }

 void Level::updateEnemyMovement(int randNumber, Player& player)
 {
	 int random = rand()% 1000;

	 if (random < randNumber) {
		 
		 for (int i = 0; i < this->enemyCount; i++) {
			 //set bounds at player
			 if (badGuys[i].getY() > 19) {
				 player.setLives(0);
				 badGuys[i].setY(player.getY());
			 }
			 //moves the enemy
			 level[(double)badGuys[i].getY()][badGuys[i].getX()];
			 badGuys[i].setY(badGuys[i].getY() + 1);
			 badGuys[i].setShotY(badGuys[i].getY() + 1);
			 level[(double)badGuys[i].getY() - 1][badGuys[i].getX()] = ' ';
			 //moves bullet

		 }
	 }


 }

 //this maybe the worst code in the history of mankind and makes me sick to my stomach
 //void Level::updateEnemyShot(int& iteration, Player &player)
 //{
	// //get a random enemyNumber
	// if (this->getRandomEnemy() <= this->enemyCount) {
	//	 //if the shot is less
	//		 if (badGuys[this->getRandomEnemy()].getShotY() < 20 && !badGuys[this->getRandomEnemy()].isEnemyDestroied()) {
	//			 //moves shot
	//			 if (iteration % 10 == 0) {
	//				 level[(double)badGuys[this->getRandomEnemy()].getShotY() + 1][badGuys[this->getRandomEnemy()].getShotX()] = '|';
	//				 level[(double)badGuys[this->getRandomEnemy()].getShotY() - 1][badGuys[this->getRandomEnemy()].getShotX()] = ' ';
	//				 badGuys[this->getRandomEnemy()].setShotY(badGuys[this->getRandomEnemy()].getShotY() + 1);
	//			 }
	//			 //collision
	//			 if (player.getX() == badGuys[this->getRandomEnemy()].getShotX() && player.getY() == badGuys[this->getRandomEnemy()].getShotY()) {
	//				 player.setLives(player.getLives() - 1);
	//			 }


	//		 }

	//		  if (badGuys[this->getRandomEnemy()].getShotY() > 19) {
	//			  badGuys[this->getRandomEnemy()].setShotY(20);
	//			 level[19][badGuys[this->getRandomEnemy()].getShotX()] = ' ';
	//			 level[20][badGuys[this->getRandomEnemy()].getShotX()] = ' ';
	//			
	//			 this->getNewRandomEnemy();
	//		 }

	//		 
	//	 }
	// 
	// else {
	//	 this->getNewRandomEnemy();
	// }
	//
	// 

	//

 //}
 
 /// <summary>
 /// Updates the Enemies isShooting variable 
 /// </summary>
 /// <param name="iteration"></param>
 /// <param name="player"></param>
 void Level::updateEnemyShot(int& iteration, Player& player)
 {
	 using namespace std::this_thread;     // sleep_for, sleep_until
	 using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
	 using std::chrono::system_clock;


		 for (int i = 0; i < this->enemyCount; i++) {

			 if (getRandomEnemy() == i) {
				 badGuys[i].setisShooting(true);
			 }
			 else {
				 getNewRandomEnemy();
			 }

		 }
	 


	 for (int i = 0; i < this->enemyCount; i++) {

		

		 if (badGuys[i].getisShooting() && badGuys[i].isEnemyDestroied() == false) {
			 if (iteration % 7 == 0) {
				 level[(double)badGuys[i].getShotY() + 1][badGuys[i].getShotX()] = '|';
				 level[(double)badGuys[i].getShotY() - 1][badGuys[i].getShotX()] = ' ';
				 badGuys[i].setShotY(badGuys[i].getShotY() + 1);
			 }

			 if (badGuys[i].getShotY() > 19) {
				 badGuys[i].setisShooting(false);
				 badGuys[i].setShotY(20);
				 level[19][badGuys[i].getShotX()] = ' ';
     			
			 }

			 if (badGuys[i].isEnemyDestroied()) {
				 level[(double)badGuys[i].getShotY()][badGuys[i].getShotX()] = ' ';
				 level[(double)badGuys[i].getShotY() - 1][badGuys[i].getShotX()] = ' ';
				 badGuys[i].setisShooting(false);
			 }

			 //collision
			 if (player.getX() == badGuys[i].getShotX() && player.getY() == badGuys[i].getShotY()) {
				 //if the player loses a life
				 player.setLives(player.getLives() - 1);
				 level[player.getY()][player.getX()] = ' ';
				 player.setX(5);
				 PlaySound(TEXT("C:\\Users\\quinn\\source\\repos\\terminalGame\\game-over-arcade-6435.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_NOWAIT);
				 system("cls");
				 system("pause");

			 }


		 }

		 }

	 }


 
 

 void Level::drawShot(Player& player,int &isShot, int &tick, int& iteration) {
	 
	
	 if (isShot == 1 && player.getShotY() > 0) {
		 //moves shot
		 if (iteration % 6 == 0) {
			 level[(double)player.getShotY() - 1][player.getShotX()] = '|';
			

			 player.setShotY(player.getShotY() - 1);
		 }
		 
	 }

	 }


	 
 
 

 void Level::eraseShot(Player& player, int& isShot, int& i, int& iteration)
 {

	 if (player.getShotY() < 1) {


		 player.setShotX(player.getX());
		 player.setShotY(player.getY());

		level[(const unsigned int)player.getShotY() - i][player.getShotX()] = ' ';
	 }


 }


 void Level::drawLevel(Menu &menu) {
	 //prints level
	 std::cout << "HIGH SCORE\n";
	 std::cout << menu.getHighestScore() <<"\n";

	 for (int col = 0; col < 22; col++) {

		 for (int row = 0; row < 18; row++) {

			 if (col == 0) {
				 std::cout << level[col][row] << '#';
			 }
			 else if (col == 21) {
				 std::cout << level[col][row] << '#';
			 }
			 else if (row == 17) {
				 std::cout << level[col][row] << '#';
			 }
			 else if (row == 0) {
				 std::cout << level[col][row] << '#';
			 }

			 else {
				 std::cout << level[col][row] << ' ';
			 }
			 //if the end of row new line
			 if (row == 17) {
				 std::cout << "\n";
			 }
		 }
	 }

 }
	 //Cant bring myself to delete because I have 4 brain cells still left in my brain 
	 /*std::cout << level[0][0] << " " << level[0][1] << " " << level[0][2] << " " << level[0][3] << " " << level[0][4] << " " << level[0][5] << " " << level[0][6] << " " << level[0][7] << " " << level[0][8] << " " << level[0][9] << "\n";
	 std::cout << level[1][0] << " " << level[1][1] << " " << level[1][2] << " " << level[1][3] << " " << level[1][4] << " " << level[1][5] << " " << level[1][6] << " " << level[1][7] << " " << level[1][8] << " " << level[1][9] << "\n";
	 std::cout << level[2][0] << " " << level[2][1] << " " << level[2][2] << " " << level[2][3] << " " << level[2][4] << " " << level[2][5] << " " << level[2][6] << " " << level[2][7] << " " << level[2][8] << " " << level[2][9] << "\n";
	 std::cout << level[3][0] << " " << level[3][1] << " " << level[3][2] << " " << level[3][3] << " " << level[3][4] << " " << level[3][5] << " " << level[3][6] << " " << level[3][7] << " " << level[3][8] << " " << level[3][9] << "\n";
	 std::cout << level[4][0] << " " << level[4][1] << " " << level[4][2] << " " << level[4][3] << " " << level[4][4] << " " << level[4][5] << " " << level[4][6] << " " << level[4][7] << " " << level[4][8] << " " << level[4][9] << "\n";
	 std::cout << level[5][0] << " " << level[5][1] << " " << level[5][2] << " " << level[5][3] << " " << level[5][4] << " " << level[5][5] << " " << level[5][6] << " " << level[5][7] << " " << level[5][8] << " " << level[5][9] << "\n";
	 std::cout << level[6][0] << " " << level[6][1] << " " << level[6][2] << " " << level[6][3] << " " << level[6][4] << " " << level[6][5] << " " << level[6][6] << " " << level[6][7] << " " << level[6][8] << " " << level[6][9] << "\n";
	 std::cout << level[7][0] << " " << level[7][1] << " " << level[7][2] << " " << level[7][3] << " " << level[7][4] << " " << level[7][5] << " " << level[7][6] << " " << level[7][7] << " " << level[7][8] << " " << level[7][9] << "\n";
	 std::cout << level[8][0] << " " << level[8][1] << " " << level[8][2] << " " << level[8][3] << " " << level[8][4] << " " << level[8][5] << " " << level[8][6] << " " << level[8][7] << " " << level[8][8] << " " << level[8][9] << "\n";
	 std::cout << level[9][0] << " " << level[9][1] << " " << level[9][2] << " " << level[9][3] << " " << level[9][4] << " " << level[9][5] << " " << level[9][6] << " " << level[9][7] << " " << level[9][8] << " " << level[9][9] << "\n";
	 std::cout << level[10][0] << " " << level[10][1] << " " << level[10][2] << " " << level[10][3] << " " << level[10][4] << " " << level[10][5] << " " << level[10][6] << " " << level[10][7] << " " << level[10][8] << " " << level[10][9] << "\n";
	 std::cout << level[11][0] << " " << level[11][1] << " " << level[11][2] << " " << level[11][3] << " " << level[11][4] << " " << level[11][5] << " " << level[11][6] << " " << level[11][7] << " " << level[11][8] << " " << level[11][9] << "\n";
	 std::cout << level[12][0] << " " << level[12][1] << " " << level[12][2] << " " << level[12][3] << " " << level[12][4] << " " << level[12][5] << " " << level[12][6] << " " << level[12][7] << " " << level[12][8] << " " << level[12][9] << "\n";
	 std::cout << level[13][0] << " " << level[13][1] << " " << level[13][2] << " " << level[13][3] << " " << level[13][4] << " " << level[13][5] << " " << level[13][6] << " " << level[13][7] << " " << level[13][8] << " " << level[13][9] << "\n";
	 std::cout << level[14][0] << " " << level[14][1] << " " << level[14][2] << " " << level[14][3] << " " << level[14][4] << " " << level[14][5] << " " << level[14][6] << " " << level[14][7] << " " << level[14][8] << " " << level[14][9] << "\n";
	 std::cout << level[15][0] << " " << level[15][1] << " " << level[15][2] << " " << level[15][3] << " " << level[15][4] << " " << level[15][5] << " " << level[15][6] << " " << level[15][7] << " " << level[15][8] << " " << level[15][9] << "\n";
	 std::cout << level[16][0] << " " << level[16][1] << " " << level[16][2] << " " << level[16][3] << " " << level[16][4] << " " << level[16][5] << " " << level[16][6] << " " << level[16][7] << " " << level[16][8] << " " << level[16][9] << "\n";
	 std::cout << level[17][0] << " " << level[17][1] << " " << level[17][2] << " " << level[17][3] << " " << level[17][4] << " " << level[17][5] << " " << level[17][6] << " " << level[17][7] << " " << level[17][8] << " " << level[17][9] << "\n";
	 std::cout << level[18][0] << " " << level[18][1] << " " << level[18][2] << " " << level[18][3] << " " << level[18][4] << " " << level[18][5] << " " << level[18][6] << " " << level[18][7] << " " << level[18][8] << " " << level[18][9] << "\n";
	 std::cout << level[19][0] << " " << level[19][1] << " " << level[19][2] << " " << level[19][3] << " " << level[19][4] << " " << level[19][5] << " " << level[19][6] << " " << level[19][7] << " " << level[19][8] << " " << level[19][9] << "\n";
	 */

 

 char** Level::getLevel()
 {

	 char** array2D = 0;
	 array2D = new char* [20];

	 for (int h = 0; h < 20; h++)
	 {
		 array2D[h] = new char[10];

		 for (int w = 0; w < 10; w++)
		 {
			 // fill in some initial values
			 // (filling in zeros would be more logic, but this is just for the example)
			 array2D[h][w] = level[h][w];
		 }


		 return array2D;
	 }
 }

 int Level::getNewRandomEnemy()
 {
	 this->randomEnemy = rand() % 4000;
	 return randomEnemy;
 }

 int Level::getRandomEnemy()
 {
	 return randomEnemy;
 }

 void Level::setEnemyCount(int x)
 {
	 enemyCount = x;
 }

 int Level::getEnemyCount()
 {
	 return this->enemyCount;
 }

 void Level::setLevelCount(int x)
 {
	 this->levelcount = x;
 }

 int Level::getLevelCount()
 {
	 return this->levelcount;
 }


 void Level::setPosition(int x, int y, char charater) {
	 if (x > 9) {
		 x = 9;
	 }
	 if (y > 19) {
		 y = 19;
	 }

	 level[x][y] = charater;


 }