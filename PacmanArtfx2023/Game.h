#pragma once
#include <string>
#include "raylib.h"
#include "Player.h"
#include "Enemy.h"
#include "assert.h"
#include "Map.h"
#include <iostream>
#include <array>

class Game
{
public:
	Game(int resWidth, int resHeight, std::string title, int fpsMax);
	~Game() noexcept;

	bool gameShouldClose() const;

	void Update();
private:
	void drawAll();

	std::string scoreTxt;

	Player *player;
	std::array<Enemy*, 4> Enemies;

	Map *map;

};

