#pragma once

#include "Actor.h"
#include "Map.h"

class Enemy : public Actor
{
private:
	float speed;
	Map* m;

	bool isDead, isVulnerable;

	float SpawnCD, RSpawnCD, VTime, timer;
	int GoodPercentage;

	Vector2 CurrentDir, spawnPos, ppos;

	Color BaseCol, DeadCol, VulnerableCol;

public:
	void tick(); //Update each frame

	Enemy(Vector2 p, Map* map, int gp);

	bool getIsDead(), getIsVulnerable(); 
	void setIsDead(bool b), setIsVulnerable(bool b);

};

