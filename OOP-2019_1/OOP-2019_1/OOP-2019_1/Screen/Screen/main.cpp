// Screen.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
// Screen ������ ��ü�� ���۷��� ��ü�� ��ȯ 
// Player, Enemy, Bullet ��ü���� GameObject* �迭�� ���� �ְ� �ʿ��� update �Լ� ��� �о�� ���ϴ� ����� �����ϱ�
// ���ӿ�����Ʈ�� 3�� ����� ���ӿ�����Ʈ�� �÷��̾� ���ʹ� �ҷ����� ����ȯ ��Ű�� virtual�� ���� Ŭ������ �ִ� �Լ��� �����ٰ� ��� �� 


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

void draw(char* loc, const char* face)
{
	strncpy(loc, face, strlen(face));
}

class Screen {
	int size;
	char* screen;

public:
	Screen(int sz) 
		: size(sz), screen(new char[sz + 1]) 
	{

	}
	~Screen() 
	{ 
		if (screen) {
			delete[] screen;
			screen = nullptr;
		}
	}

	void draw(int pos, const char* face) 
	{
		if (face == nullptr) return;
		if (pos < 0 || pos >= size) return;
		strncpy(&screen[pos], face, strlen(face));
	}

	void render() 
	{
		printf("%s\r", screen);
	}

	void clear()
	{
		memset(screen, ' ', size);
		screen[size] = '\0';
	}

	int length()
	{
		return size;
	}

};

class GameObject {
	int pos;
	char face[20];
	Screen& screen;


public:
	GameObject(int pos, const char* face, Screen& screen)
		: pos(pos), screen(screen)
	{
		strcpy(this->face, face);
	}

	~GameObject()
	{
	}

	
	int getPosition()
	{
		return pos;
	}
	void setPosition(int pos)
	{
		this->pos = pos;
	}
	virtual void draw()
	{
		screen.draw(pos, face);
	}

	virtual void update()
	{

	}
};

class Player : public GameObject {
	
public:
	Player(int pos, const char* face, Screen& screen) 
		: GameObject(pos, face, screen)
	{	
	}

	~Player()
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

	void update()
	{

	}

};

class Enemy : public GameObject {
	
public:
	Enemy(int pos, const char* face, Screen& screen) 
		: GameObject(pos, face, screen)
	{
	
	}

	~Enemy()
	{

	}

	void moveRandom()
	{
		setPosition( getPosition() + rand() % 3 - 1);
	}

	void update()
	{
		moveRandom();
	}
};

class Bullet : public GameObject {
	bool isFiring;
	Enemy * enemy;
public:
	Bullet(int pos, const char* face, Screen& screen,Enemy *enemy) 
		: GameObject(pos, face, screen), isFiring(false),enemy(enemy)
	{
		
	}
	~Bullet()
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

	void fire(int player_pos)
	{
		isFiring = true;
		setPosition(player_pos);
	}

	void update()
	{
		if (isFiring == false) return;
		int pos = getPosition();
		if (pos < enemy->getPosition()) {
			pos = pos + 1;
		}
		else if (pos > enemy->getPosition()) {
			pos = pos - 1;
		}
		else {
			isFiring = false;
		}
		setPosition(pos);
	}
};

#define NORMAL_PLAY 1

#if NORMAL_PLAY
int main()
{
	Screen screen{ 80 };
			
	Player *player = new Player(30, "(^_^)", screen);
	Enemy *enemy = new Enemy{ 60, "(*--*)", screen };
	Bullet *bullet = new Bullet( -1, "+", screen,enemy);
	
	GameObject *gameobject[3];


	
	gameobject[0] = player;
	gameobject[1] = enemy;
	gameobject[2] = bullet;
	
	while (true)
	{
		screen.clear();

		if (_kbhit())
		{
			int c = _getch();
			Player * tPlayer = dynamic_cast<Player*>(gameobject[0]);
			Bullet * tBullet = dynamic_cast<Bullet*>(gameobject[2]);
			switch (c) {
			case 'a':
				tPlayer->moveLeft();
				break;
			case 'd':
				tPlayer->moveRight();
				break;
			case ' ':
				tBullet->fire(tPlayer->getPosition());
				break;
			}
		}

		for (int i = 0; i < 3; i++)
		{
			gameobject[i]->draw();
		}
		for (int i = 0; i < 3; i++)
		{
			gameobject[i]->update();
		}

		screen.render();
		Sleep(66);
	}
	
	delete player,enemy,bullet;


	return 0;
}

#else
void test()
{
	Screen* screen = nullptr;

	screen = new Screen(80);
	/* 80 };
	Player player = { 30, "(^_^)", &screen };
	Enemy enemy{ 60, "(*--*)", &screen };
	Bullet bullet(-1, "+", &screen);
	*/
	
}

int main()
{
	test();


	Screen* another = nullptr;
	int ch = _getch();
	return 0;
}

#endif