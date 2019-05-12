#pragma once
#include "stdafx.h"
#include "screen.h"


class GameObject {
private:
	int pos;
	char face[20];
	Screen* screen;
	bool left;
	bool right;
	int weapontype;

public:
	GameObject(int pos, const char* face, Screen* screen)
		: pos(pos), screen(screen)
	{
		left = false, right = false;
		weapontype = 1;
		strcpy(this->face, face);
	}

	void setFace(const char* face)
	{
		strcpy(this->face, face);
	}
	char* getFace()
	{
		return face;
	}


	void setWeapontype(int weapontype)
	{
		this->weapontype = weapontype;
	}

	int getWeapontype()
	{
		return weapontype;
	}

	int getFaceLen()
	{
		return strlen(this->face);
	}

	void setLeft()
	{
		right = false;
		left = true;
	}

	void setRight()
	{
		left = false;
		right = true;
	}

	bool getLeft()
	{
		return left;
	}
	bool getRight()
	{
		return right;
	}

	int getPosition()
	{
		return pos;
	}
	void setPosition(int pos)
	{
		this->pos = pos;
	}
	void draw()
	{
		screen->draw(pos, face);
	}

	void draw(char* loc, const char* face)
	{
		strncpy(loc, face, strlen(face));
	}
};