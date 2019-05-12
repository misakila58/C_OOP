#pragma once
#include "gameObject.h"
#include "screen.h"
#include "stdafx.h"
#include "player.h"


class Bullet : public GameObject {
	bool isFiring;

public:
	Bullet(int pos, const char* face, Screen* screen)
		: GameObject(pos, face, screen), isFiring(false)
	{
	
	}

	void fire(int player_pos, bool direction, int faceLen, int weapontype);

	void update(int enemy_pos);
	
	void moveLeft()
	{
		setPosition(getPosition() - 1);
	}

	void moveRight()
	{
		setPosition(getPosition() + 1);
	}

	void draw()
	{
		if (isFiring == false) return;
		GameObject::draw();
	}



};
