#include "stdafx.h"
#include "player.h"


void Player::seeLeft()
{
	setLeft();
}

void Player::seeRight()
{
	setRight();
}

void Player::moveLeft()
{
	setface("<*.*)");
	if (getLeft() == true)
		setPosition(getPosition() - 1);
	seeLeft();
}

void Player::moveRight()
{
	setface("(*.*>");
	if(getRight() == true)
	setPosition(getPosition() + 1);
	seeRight();
}

void Player::update()
{
}
