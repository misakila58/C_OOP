#pragma once
#include "stdafx.h"
#include "gameObject.h"
#include "screen.h"

class Enemy : public GameObject {

	int hp;

public:
	Enemy(int pos, const char* face, Screen* screen,int weapontype)
		: GameObject(pos, face, screen)
	{
		hp = 5;
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
