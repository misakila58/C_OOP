#pragma once
#include "stdafx.h"
#include "gameObject.h"
#include "screen.h"


class Player : public GameObject {

private:


public:
	Player(int pos, const char* face, Screen* screen,int weapontype)
		: GameObject(pos, face, screen)
	{
	}

	void seeLeft();
	void seeRight();
	void changeweapon();



	void moveLeft();

	void moveRight();


	void update();

};