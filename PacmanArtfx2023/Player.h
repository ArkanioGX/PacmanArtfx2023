#pragma once
#include "Actor.h"
#include "Enemy.h"
#include "Map.h"
#include <iostream>
#include <vector>
class Player : public Actor
{
private:
	float speed; //Speed of the player
	Map* m; //Map info

	int score;

	bool isDead, Won;

	std::vector<Enemy*> Enemies; //List of enemies to check for collision

public:
	void tick(); //Update of the player each frame

	Player(Map* map); //Constructor

	int getScore() {
		return score;
	}
	bool getIsDead(), isWon();

	void setEnemies(std::vector<Enemy*> en);
};

