#pragma once
#include <Vector>
#include "raylib.h"
class Map
{
private:
	int tileSize;
	std::vector<Vector2> Walls, Food, Power;
    std::vector<bool> foodPicked;

    int idMap[16][16] = { {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,2,1,1,1,1,1,1,1,1,1,1,1,1,2,0},
                            {0,1,0,0,1,0,0,0,0,0,0,1,0,0,1,0},
                            {0,1,0,0,1,1,1,1,1,1,1,1,0,0,1,0},
                            {0,1,1,1,1,0,0,1,1,0,0,1,1,1,1,0},
                            {0,1,0,1,0,0,0,1,1,0,0,0,1,0,1,0},
                            {0,1,0,1,0,1,1,1,1,1,1,0,1,0,1,0},
                            {0,1,0,1,1,1,0,1,1,0,1,0,1,0,1,0},
                            {0,1,0,1,0,1,0,1,1,0,1,1,1,0,1,0},
                            {0,1,0,1,0,1,1,1,1,1,1,0,1,0,1,0},
                            {0,1,0,1,0,0,0,1,1,0,0,0,1,0,1,0},
                            {0,1,1,1,1,0,0,1,1,0,0,1,1,1,1,0},
                            {0,1,0,0,1,1,1,1,1,1,1,1,0,0,1,0},
                            {0,1,0,0,1,0,0,0,0,0,0,1,0,0,1,0},
                            {0,2,1,1,1,1,1,1,1,1,1,1,1,1,2,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} };

public:
    void loadMap();

    int getMapSize();

    int getTileSize();

    Map();

    void drawMap();

    std::vector<Vector2> getWalls(), getFood(), getPower();
    std::vector<bool> getFoodPicked();
    void setFoodPicked(int i, bool b);
   
};

