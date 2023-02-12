#include "Game.h"
#include <string>

Game::Game(int resWidth, int resHeight, std::string title, int fpsMax)
{
	assert(!IsWindowReady());
	SetTargetFPS(fpsMax);
	InitWindow(resWidth, resHeight, title.c_str());

	map = new Map();
	
	player = new Player(map);

	Enemies.push_back(new Enemy(Vector2{ 45,85 },map,20));
	Enemies.push_back(new Enemy(Vector2{ 300 ,85 },map,40));
	Enemies.push_back(new Enemy(Vector2{ 45,605 },map,60));
	Enemies.push_back(new Enemy(Vector2{ 565,605 },map,80));

	player->setEnemies(Enemies);

	for (int i = 0; i < Enemies.size(); i++) {
		Enemies.at(i)->setPlayer(player);
	}
}

Game::~Game() noexcept
{
}

bool Game::gameShouldClose() const
{
	return WindowShouldClose();
}

void Game::Update()
{
	if (!player->isWon() && !player->getIsDead()) {
		player->tick();
		for (int i = 0; i < Enemies.size(); i++) {
			Enemies.at(i)->tick();
		}
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
	for (int i = 0; i < Enemies.size(); i++) {
		Enemies.at(i)->draw();
	}
	EndDrawing();
}
