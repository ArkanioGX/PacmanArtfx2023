#include "Game.h"
#include <string>

Game::Game(int resWidth, int resHeight, std::string title, int fpsMax) //Load for first time the game
{
	assert(!IsWindowReady());
	SetTargetFPS(fpsMax);
	InitWindow(resWidth, resHeight, title.c_str());

	map = new Map();
	
	player = new Player(map);

	Enemies.push_back(new Enemy(Vector2{ 45,85 }, map, 20));
	Enemies.push_back(new Enemy(Vector2{ 300 ,85 }, map, 40));
	Enemies.push_back(new Enemy(Vector2{ 45,605 }, map, 60));
	Enemies.push_back(new Enemy(Vector2{ 565,605 }, map, 80));

	player->setEnemies(Enemies);
}

Game::~Game() noexcept
{
	
}

bool Game::gameShouldClose() const
{
	return WindowShouldClose();
}

void Game::Update() //Call all tick and draw all objects
{
	if (!player->isWon() && !player->getIsDead()) { //Condition to know if the game should be stopped
		player->tick();
		scoreTxt = "Score : " + std::to_string(player->getScore());
		for (int i = 0; i < Enemies.size(); i++) {
			Enemies.at(i)->tick();
		}
	}
	else //Show message when game finished
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

void Game::drawAll() //Draw all objects
{
	BeginDrawing();
	ClearBackground(Color{ 20,30,80,255 });
	
	DrawText(scoreTxt.c_str(),0,0,40,RAYWHITE);
	map->drawMap();								//Draw Map
	player->draw();								//Draw Player
	for (int i = 0; i < Enemies.size(); i++) {	//Draw Enemies
		Enemies.at(i)->draw();
	}
	EndDrawing();
}
