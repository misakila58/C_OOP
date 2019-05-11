#pragma once
#include "stdafx.h"
#include "gameObject.h"
#include "screen.h"


class Player : public GameObject {

public:
	Player(int pos, const char* face, Screen* screen)
		: GameObject(pos, face, screen)
	{
	}


	void moveLeft()
	{
		setPosition(getPosition() - 1);
	}

	void moveRight()
	{
		setPosition(getPosition() + 1);
	}

	void update()
	{

	}

};