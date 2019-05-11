#pragma once
#include "gameObject.h"
#include "screen.h"
#include "stdafx.h"
#include "bullet.h"
#include "player.h"


class Bullet : public GameObject   {
	bool isFiring;

public:
	Bullet(int pos, const char* face, Screen* screen)
		: GameObject(pos, face, screen), isFiring(false)
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

	void draw()
	{
		if (isFiring == false) return;
		GameObject::draw();
	}

	void fire(int player_pos,bool direction,int faceLen)
	{
		isFiring = true;
		if (direction == true)
		{
			setPosition(player_pos - 1);
			setLeft(); //Bullet¿« Left∞° true
		}
			
		else
		{
			setPosition(player_pos + faceLen);
			setRight();
		}
		

	}

	void update(int enemy_pos)
	{
		if (isFiring == false) return;

		int pos = getPosition();

		if (getLeft() == true)
		{
			pos = pos - 1;
		}
		else if (getRight() == true)
		{
			pos = pos + 1;
		}

		if (pos == enemy_pos)
		{
			isFiring = false;
		}
		setPosition(pos); 
		

	/*	if (isFiring == false) return;
		int pos = getPosition();
		if (pos < enemy_pos) {
			pos = pos + 1;
		}
		else if (pos > enemy_pos) {
			pos = pos - 1;
		}
		else {
			isFiring = false;
		}
		setPosition(pos);*/
	}
};