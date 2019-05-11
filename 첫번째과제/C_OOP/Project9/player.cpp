#include "stdafx.h"
#include "player.h"


void Player::seeLeft()
{
	right = false;
	left = true;

}

void Player::seeRight()
{
	left = false;
	right = true;
}


void Player::moveLeft()
{
	setface("<*.*)");
	if (left == true)
		setPosition(getPosition() - 1);
	seeLeft();
}

void Player::moveRight()
{
	setface("(*.*>");
	if(right == true)
	setPosition(getPosition() + 1);
	seeRight();
}

void Player::update()
{
}
