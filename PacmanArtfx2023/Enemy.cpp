#include "Enemy.h"

Enemy::Enemy(Vector2 p, Map* map, int gp) {
	speed = 160;
	m = map;
	isDead = false;
	size = 30;
	pos = p;
	col = RED;

	GoodPercentage = gp;
	spawnPos = p;

	BaseCol = col;
	DeadCol = DARKGRAY;
	VulnerableCol = RAYWHITE;

	SpawnCD = 2;
	RSpawnCD = 2;
	VTime = 5;
	timer = SpawnCD;

	isVulnerable = false;
}

void Enemy::tick() {
	if (isDead)
	{
		timer -= GetFrameTime();
		if (timer <= 1)
		{
			if ((fmod(timer, 0.2)) <= 0.1)
				col = DeadCol;
			else
				col = BaseCol;
			if (timer <= 0)
			{
				setIsDead(false);
				timer = 0;
			}
		}
		else {
			if ((fmod(timer, 0.8)) <= 0.4)
				col = BaseCol;
			else
				col = DeadCol;

		}
	}
	else if (isVulnerable)
	{
		timer -= GetFrameTime();
		if (timer <= 1)
		{
			if ((fmod(timer, 0.2)) <= 0.1)
				col = VulnerableCol;
			else
				col = BaseCol;
			if (timer <= 0)
			{
				setIsVulnerable(false);
				timer = 0;
			}
		}
		else if (timer <= VTime / 2) {
			if ((fmod(timer, 0.8)) <= 0.4)
				col = BaseCol;
			else
				col = VulnerableCol;
		}
	}
	else {
		pos = Vector2{ pos.x + speed / 4 * GetFrameTime(), pos.y };
	}
}

void Enemy::setIsDead(bool b)
{
	isDead = b;
	isVulnerable = false;
	if (b) {
		col = DeadCol;
		pos = spawnPos;
		timer = RSpawnCD;
	}
	else {
		col = BaseCol;
	}
}

bool Enemy::getIsDead()
{
	return isDead;
}

bool Enemy::getIsVulnerable()
{
	return isVulnerable;
}

void Enemy::setIsVulnerable(bool b)
{
	if (!isDead) {
		isVulnerable = b;
		if (b) {
			col = VulnerableCol;
			timer = VTime;
		}
		else {
			col = BaseCol;
		}
	}
}