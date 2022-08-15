#include "Player.h"

Player::Player()                         
	:x(0), y(0), lives(3), numOfshots(3)
{
	this->shotX = x;
	this->shotY = y;

}

Player::Player(int lives, int numShots, int x, int y):
	lives(lives), numOfshots(numShots), x(x), y(y)
	
{
	
	this->shotX = x;
	this->shotY = y;
	
	
}

int Player::move(int &isShot, int& i,int& shotNum, bool &finnishedShot)
{
	char key = _getch();
	int value = key;
	

	switch (key) {

	case KEY_A:
		this->setX(this->getX() - 1);
		
		if (isShot != 1) {
			this->setShotX(this->getShotX() - 1);
		}

		if (this->getX() < 1 || this->getShotX() < 1) {
			this->setX(1);
			this->setShotX(1);
		}
		break;


	case KEY_D:

		this->setX(this->getX() + 1);
		if (isShot != 1) {
			this->setShotX(this->getShotX() + 1);
		}
		if (this->getX() > 17 || this->getShotX() > 17) {
			this->setX(17);
			this->setShotX(17);
		}
		break;
		
	case KEY_SPACE:
		//could make some of these variables player variables
		//put a cap on number of times you can press the space bar
		//isShot *= -1;
		if (this->getnumOfshots() != 0) {
			PlaySound(TEXT("C:\\Users\\quinn\\source\\repos\\terminalGame\\shoot"), NULL, SND_FILENAME | SND_ASYNC | SND_NOWAIT);
			isShot *= -1;
			if (isShot != 1) {
				isShot *= -1;

				//this->setNumOfShots(this->getnumOfshots() - 1);
			}

			if (isShot == 1) {
				//makes it so you cant pause the bullet
				if (this->getShotY() < 1) {
					isShot *= -1;
				}
			}
			this->setNumOfShots(this->getnumOfshots() - 1);

			//reset tick for enemy falling and adds randomness
			//i = 0;
		}
		break;
		
	}

	//make a is desroyed which checks if the bullet hit an ennemie or 
	
	if (isShot != 1) {
		this->setShotX(this->getX());
	}
	if (this->getShotY() < 1) {
		//resets shots and docs score
		this->setScore(this->getScore() - 500.25);
		this->setShotX(this->getX());
		this->setShotY(this->getY());
		isShot *=-1;
	}

	

	
	return key;

}







void Player::setX(int x)
{
	this->x = x;
}

void Player::setY(int y)
{
	this->y = y;
}

void Player::setShotX(int x)
{
	this->shotX = x;
}



void Player::setShotY(int y)
{
	this->shotY = y;
}

void Player::setLives(int lives)
{
	this->lives = lives;
}

void Player::setNumOfShots(int shots)
{
	this->numOfshots = shots;
}

int Player::getX()
{
	return this->x;
}

int Player::getY()
{
	return this->y;
}



int Player::getLives()
{
	return this->lives;
}

int Player::getnumOfshots()
{
	return this->numOfshots;
}

int Player::getShotX()
{
	return this->shotX;
}

int Player::getShotY()
{
	return this->shotY;
}

int Player::getEnemiesKilled()
{
	return this->enemiesKilled;
}

double Player::getScore()
{
	return this->score;
}

char Player::getSpite()
{
	return this->shotSprite;
}

double Player::getCash()
{
	return this->cash;
}

void Player::setShotSprite(char sprite)
{

	this->shotSprite = sprite;

}

void Player::setEnemiesKilled(int num)
{
	this->enemiesKilled = num;
}

void Player::setScore(double scoreNum)
{
	this->score = scoreNum;
}

void Player::setCash(double cash)
{
	this->cash = cash;
}
