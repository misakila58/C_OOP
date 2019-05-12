#include "stdafx.h"
#include "bullet.h"

void Bullet::fire(int player_pos, bool direction, int faceLen,int weapontype)
{
	
	switch (weapontype)
	{
	case 1:
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
		break;
	case 2:
	
		break;
	}
	

}

void Bullet::update(int enemy_pos)
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
	
}
