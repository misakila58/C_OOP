#pragma once
#include "gameObject.h"
#include "screen.h"
#include "stdafx.h"
#include "player.h"
#include "enemy.h"

class Bullet : public GameObject {
	bool isFiring;
	int bulletType;
	
	clock_t start, end; //초 구현을 clock 함수로 시도 
	double delayTime = 0;
	Enemy* enemy;

public:
	Bullet(int pos, const char* face, Screen* screen)
		: GameObject(pos, face, screen), isFiring(false), enemy(nullptr)
	{
		bulletType = 1;
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

	void shoot(int enemy_pos);
	void setLaser();
	void setGun();


};
