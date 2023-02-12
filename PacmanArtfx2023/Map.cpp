#include "Map.h"

int Map::getMapSize()
{
    return (sizeof idMap / sizeof idMap[0]);
}

void Map::loadMap()
{
    for (int x = 0; x < getMapSize(); x++) {
        for (int y = 0; y < getMapSize(); y++) {
            switch (idMap[y][x])
            {
            case 0:
                Walls.push_back(Vector2{ (float)x * tileSize,((float)y + 1) * tileSize });
                break;
            case 1:
                Food.push_back(Vector2{ (float)x * tileSize + (tileSize / 2 - tileSize / 8),((float)y + 1)* tileSize + (tileSize / 2 - tileSize / 8) });
                foodPicked.push_back(false);
                break;
            case 2:
                Power.push_back(Vector2{ (float)x * tileSize + (tileSize / 2 - tileSize / 4),((float)y + 1) * tileSize + (tileSize / 2 - tileSize / 4) });
                break;

            }
        }
    }
}

Map::Map() {
    tileSize = 40;
    loadMap();
}

void Map::drawMap() {
    for (int i = 0; i < Walls.size(); i++) {
        DrawRectangle(Walls.at(i).x, Walls.at(i).y, tileSize, tileSize, Color{ 16,100,230,255 });
    }
    for (int i = 0; i < Food.size(); i++) {
        if (foodPicked.at(i)) {
            DrawRectangle(Food.at(i).x, Food.at(i).y, tileSize / 4, tileSize / 4, DARKGRAY);
        }
        else
        {
            DrawRectangle(Food.at(i).x, Food.at(i).y, tileSize / 4, tileSize / 4, RAYWHITE);
        }
    }
    for (int i = 0; i < Power.size(); i++) {
        DrawRectangle(Power.at(i).x, Power.at(i).y, tileSize / 2, tileSize / 2, YELLOW);
    }
}

std::vector<Vector2> Map::getWalls()
{
    return Walls;
}

void Map::setFoodPicked(int i, bool b)
{
    foodPicked[i] = b;
}

std::vector<Vector2> Map::getFood()
{
    return Food;
}

std::vector<Vector2> Map::getPower()
{
    return Power;
}

std::vector<bool> Map::getFoodPicked()
{
    return foodPicked;
}

int Map::getTileSize() {
    return tileSize;
}