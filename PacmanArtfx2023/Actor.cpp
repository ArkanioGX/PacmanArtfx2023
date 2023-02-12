#include "Actor.h"

Vector2 Actor::getPos() 
{
    return pos;
}

void Actor::setPos(Vector2 p)
{
    pos = p;
}

void Actor::draw()  //draw shape from Actor Data
{
    DrawRectangle(pos.x, pos.y, size, size, col);
}
