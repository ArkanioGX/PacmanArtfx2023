#include "Game.h"
#include <string>

Game::Game(int resWidth, int resHeight, std::string title, int fpsMax)
{
	assert(!IsWindowReady());
	SetTargetFPS(fpsMax);
	InitWindow(resWidth, resHeight, title.c_str());

	map = new Map();
	
	player = new Player(map);
}

Game::~Game() noexcept
{
}

bool Game::gameShouldClose() const
{
	return false;
}

void Game::Update()
{
	if (!player->isWon() && !player->getIsDead()) {
		player->tick();
		scoreTxt = "Score : " + std::to_string(player->getScore());
	}
	else
	{
		if (player->isWon()) {
			scoreTxt = "Bravo !!!";
		}
		else
		{
			scoreTxt = "Perdu ! :(";
		}
	}
	drawAll();
}

void Game::drawAll()
{
	BeginDrawing();
	ClearBackground(Color{ 20,30,80,255 });
	
	DrawText(scoreTxt.c_str(),0,0,40,RAYWHITE);
	map->drawMap();
	player->draw();
	EndDrawing();
}
