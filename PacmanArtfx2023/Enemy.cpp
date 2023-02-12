#include "Enemy.h"

Enemy::Enemy(Vector2 p, Map* map, int gp) { //Enemy Constructor
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

	CurrentDir = Vector2{ 1,0 };

	isVulnerable = false;
}

void Enemy::tick() { //Enemy update each Frame
	if (isDead)								//Blinking when dead and respawning
	{
		timer -= GetFrameTime();
		if (timer <= 1)						//Blinking Faster when respawning soon
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
			if ((fmod(timer, 0.8)) <= 0.4) //Normal Blink Speed
				col = BaseCol;
			else
				col = DeadCol;

		}
	}
	else if (isVulnerable)				//Blinking after a certain time to show the enemy will be back
	{
		timer -= GetFrameTime();
		if (timer <= 1)					//Faster Blink
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
		else if (timer <= VTime / 2) {	//Blink when half the vulnerable time passed
			if ((fmod(timer, 0.8)) <= 0.4)
				col = BaseCol;
			else
				col = VulnerableCol;
		}
	}
	else {
		if (pos.x <= 40 || pos.x >570) {	//Normal left and right scrolling
			CurrentDir = Vector2{-CurrentDir.x,0};
		}
		pos = Vector2{ pos.x + (speed * CurrentDir.x) * GetFrameTime(), pos.y };
	}
}

void Enemy::setIsDead(bool b) //Set the enemy dead or respawn him
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

bool Enemy::getIsDead() //know if the enemy is dead
{
	return isDead;
}

bool Enemy::getIsVulnerable() //know if the enemy is dead
{
	return isVulnerable;
}

void Enemy::setIsVulnerable(bool b)//Set the enemy vulnerable 
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
