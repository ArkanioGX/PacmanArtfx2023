#include "Player.h"

void Player::tick()
{
	int vdir = IsKeyDown(KEY_S) - IsKeyDown(KEY_W); //Vertical direction
	int hdir = IsKeyDown(KEY_D) - IsKeyDown(KEY_A); //Horizontal direction

	float vspd = vdir * speed * GetFrameTime();
	float hspd = hdir * speed * GetFrameTime();

	float tileSize = m->getTileSize();

	for (int i = 0; i < m->getWalls().size(); i++) {
		Vector2 wpos = m->getWalls().at(i);
		if (CheckCollisionRecs(Rectangle{ pos.x + hspd,pos.y + vspd,size,size }, Rectangle{ wpos.x, wpos.y,tileSize,tileSize })) {
			if (CheckCollisionRecs(Rectangle{ pos.x ,pos.y  + vspd,size ,size }, Rectangle{ wpos.x, wpos.y,tileSize,tileSize })) {
				vspd = 0;
			}
			if (CheckCollisionRecs(Rectangle{ pos.x + hspd,pos.y ,size ,size  }, Rectangle{ wpos.x, wpos.y,tileSize,tileSize })) {
				hspd = 0;
			}
		}
	}
	
	for (int i = 0; i < m->getFood().size(); i++) {
		Vector2 wpos = m->getFood().at(i);
		if (!m->getFoodPicked().at(i)) {
			if (CheckCollisionRecs(Rectangle{ pos.x + hspd,pos.y + vspd,size,size }, Rectangle{ wpos.x, wpos.y,tileSize / 4,tileSize / 4 })) {
				std::cout << "Picked";
				m->setFoodPicked(i, true);
				score++;
				if (score == m->getFood().size()) {
					Won = true;
				}
			}
		}
	}

	for (int i = 0; i < m->getPower().size(); i++) {
		int fsize = m->getFood().size();
		Vector2 wpos = m->getPower().at(i);
		if (!m->getFoodPicked().at(fsize+i)) {
			if (CheckCollisionRecs(Rectangle{ pos.x + hspd,pos.y + vspd,size,size }, Rectangle{ wpos.x, wpos.y,20,20 })) {
				std::cout << "Picked Power";
				m->setFoodPicked(fsize+i, true);
				for (int i = 0; i < Enemies.size(); i++) {
					Enemies.at(i)->setIsVulnerable(true);
				}
			}
		}
	}


	for (int i = 0; i < Enemies.size(); i++) {
		Vector2 wpos = Enemies.at(i)->getPos();
		if (CheckCollisionRecs(Rectangle{ pos.x + hspd,pos.y + vspd,size,size }, Rectangle{ wpos.x, wpos.y,30,30 })) {
			Enemy* currentEnemy = Enemies.at(i);
			if (!currentEnemy->getIsVulnerable() && !currentEnemy->getIsDead()) 
			{
				std::cout << "ded";
				isDead = true;
			}
			else if (currentEnemy->getIsVulnerable() && !currentEnemy->getIsDead()) {
				currentEnemy->setIsDead(true);
			}
		}
	}
	

	pos = Vector2{ pos.x + hspd, pos.y + vspd };
}

Player::Player(Map* map) {
	speed = 175;
	m = map;
	score = 0;
	isDead = false;
	Won = false;
	size = 24;
	pos = Vector2{ 308,348 };
	col = YELLOW;
	
}

bool Player::getIsDead()
{
	return isDead;
}

bool Player::isWon()
{
	return Won;
}

void Player::setEnemies(std::vector<Enemy*> en)
{
	for (int i = 0; i < en.size(); i++) {
		Enemies.push_back(en.at(i));
	}
	
}




