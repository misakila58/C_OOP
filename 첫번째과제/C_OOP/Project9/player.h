#pragma once
#include "stdafx.h"
#include "gameObject.h"
#include "screen.h"


class Player : public GameObject {

private:
	int hp;

public:
	Player(int pos, const char* face, Screen* screen,int weapontype)
		: GameObject(pos, face, screen)
	{
		hp = 10;
	}

	void seeLeft();
	void seeRight();
	void changeweapon();



	void moveLeft();

	void moveRight();


	void update();

};