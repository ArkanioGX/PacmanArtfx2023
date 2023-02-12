#pragma once
#include <Vector>
#include "raylib.h"
class Map
{
private:
	int tileSize;
	std::vector<Vector2> Walls, Food, Power; //Every map object
    std::vector<bool> foodPicked; //The food that was taken

    int idMap[16][16] = { {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, //Map data
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
    void loadMap(); //Load all object from the Map Data

    int getMapSize(); 

    int getTileSize();

    int getIdfromMap(int x, int y); 

    Map();

    void drawMap();

    std::vector<Vector2> getWalls(), getFood(), getPower(); //get map data info
    std::vector<bool> getFoodPicked(); //get the food that was already taken
    void setFoodPicked(int i, bool b);
   
};

