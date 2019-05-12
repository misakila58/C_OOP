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
	setFace("<*.*)");
	if (getLeft() == true)
		setPosition(getPosition() - 1);
	seeLeft();
}

void Player::moveRight()
{
	setFace("(*.*>");
	if(getRight() == true)
	setPosition(getPosition() + 1);
	seeRight();
}

void Player::update()
{
}

void Player::changeweapon()
{
	int weapontype = getWeapontype();
	weapontype += 1;
	setWeapontype(weapontype % 2);


}
