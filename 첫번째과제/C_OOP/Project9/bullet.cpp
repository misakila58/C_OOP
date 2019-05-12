#include "stdafx.h"
#include "bullet.h"

void Bullet::fire(int player_pos, bool direction, int faceLen,int weapontype)
{

	switch (weapontype)
	{
	case 1:
		bulletType = 1;
		setGun();
		isFiring = true;
		if (direction == true)
		{
			setPosition(player_pos - 1);
			setLeft(); 
		}
		else
		{
			setPosition(player_pos + faceLen);
			setRight();
		}
		break;
	case 0:
		bulletType = 2;
		delayTime = clock();
		setLaser();
		isFiring = true;

		if (direction == true)
		{
			setPosition(player_pos - 1);
			setLeft();
		}
		else
		{
			setPosition(player_pos + faceLen);
			setRight();
		}
		break;
	}
	

}

void Bullet::setGun()
{
	setFace("+");
}

void Bullet::setLaser()
{
	setFace("-");

}
void Bullet::shoot(int enemy_pos)
{
	
}
void Bullet::update(int enemy_pos)
{
		if (isFiring == false) return;
		int pos = getPosition();

		switch (bulletType)
		{
		case 1:

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
			break;
		case 2://적의 위치 내 총알의 위치 레이저 

			int distance = enemy_pos - pos;
			int test = clock();
			int tempTime = (test - delayTime) / CLOCKS_PER_SEC;
			if (tempTime < 2000)
			{
				
				for (int i = 0; i <= distance; i++)
				{
					draw();
					setPosition(pos);
					pos = pos + 1;
				}
			}

			break;
		}
	
}
