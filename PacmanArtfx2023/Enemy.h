#pragma once
#include "Map.h"
#include "Actor.h"

class Enemy : public Actor
{
private:
	float speed;
	Map* m;

	bool isDead, isVulnerable;

	float SpawnCD, RSpawnCD, VTime, timer;
	int GoodPercentage;

	Vector2 lastDir, CurrentDir, spawnPos, ppos;

	Color BaseCol, DeadCol, VulnerableCol;

public:
	void tick();

	Enemy(Vector2 p, Map* map, int gp);

	bool getIsDead(), getIsVulnerable();
	void setIsDead(bool b), setIsVulnerable(bool b);
	//void setPlayer(Player* pla);

	Vector2 findDir(Vector2 target, bool isForward);
};

