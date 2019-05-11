#pragma once
#include "stdafx.h"
#include "screen.h"


class GameObject {
	int pos;
	char face[20];
	Screen* screen;
	bool left;
	bool right;

public:
	GameObject(int pos, const char* face, Screen* screen)
		: pos(pos), screen(screen)
	{
		left = false, right = false;
		strcpy(this->face, face);
	}

	void setface(const char* face)
	{
		strcpy(this->face, face);
	}
	
	int getFace()
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