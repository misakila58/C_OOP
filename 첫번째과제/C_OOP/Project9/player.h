#pragma once
#include "stdafx.h"
#include "gameObject.h"
#include "screen.h"


class Player : public GameObject {

private:
	bool left;
	bool right;

public:
	Player(int pos, const char* face, Screen* screen)
		: GameObject(pos, face, screen)
	{
	}

	void seeLeft();
	void seeRight();



	void moveLeft();

	void moveRight();


	void update();

};