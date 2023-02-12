#pragma once
#include "Actor.h"
#include "Map.h"
#include <iostream>
class Player : public Actor
{
private:
	float speed;
	Map* m;

	int score;

	bool isDead, Won;

public:
	void tick();

	Player(Map* map);

	int getScore() {
		return score;
	}
	bool getIsDead(), isWon();
};

