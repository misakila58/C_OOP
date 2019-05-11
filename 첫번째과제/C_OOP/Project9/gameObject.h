#pragma once
#include "stdafx.h"
#include "screen.h"


class GameObject {
	int pos;
	char face[20];
	Screen* screen;

public:
	GameObject(int pos, const char* face, Screen* screen)
		: pos(pos), screen(screen)
	{
		strcpy(this->face, face);
	}

	void setface(const char* face)
	{
		strcpy(this->face, face);
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