#pragma once
#include "stdafx.h"
#include "gameObject.h"
#include "screen.h"

class Enemy : public GameObject {

public:
	Enemy(int pos, const char* face, Screen* screen)
		: GameObject(pos, face, screen)
	{
	}

	void moveRandom()
	{
		setPosition(getPosition() + rand() % 3 - 1);
	}

	void update()
	{
		moveRandom();
	}
};
