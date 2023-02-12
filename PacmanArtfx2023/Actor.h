#pragma once
#include "raylib.h"
class Actor
{
protected:
	Vector2 pos; //Position
	Color col;	//Color
	float size; //Size in pixels

public:
	Vector2 getPos();
	void setPos(Vector2 p);

	virtual void draw(); //Draw object
};

