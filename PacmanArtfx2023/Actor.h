#pragma once
#include "raylib.h"
class Actor
{
protected:
	Vector2 pos;
	Color col;
	float size;

public:
	Vector2 getPos();
	void setPos(Vector2 p);

	virtual void draw();
};

