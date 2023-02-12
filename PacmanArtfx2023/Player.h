#pragma once
#include "Actor.h"
#include "Enemy.h"
#include "Map.h"
#include <iostream>
#include <vector>
class Player : public Actor
{
private:
	float speed;
	Map* m;

	int score;

	bool isDead, Won;

	std::vector<Enemy*> Enemies;

public:
	void tick();

	Player(Map* map);

	int getScore() {
		return score;
	}
	bool getIsDead(), isWon();

	void setEnemies(std::vector<Enemy*> en);
};

