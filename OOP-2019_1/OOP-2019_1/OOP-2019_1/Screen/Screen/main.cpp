// Screen.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// Screen 포인터 객체를 레퍼런스 객체로 변환 
// Player, Enemy, Bullet 객체들을 GameObject* 배열에 집어 넣고 필요한 update 함수 등에서 읽어내어 원하는 기능을 구현하기
// 게임오브젝트를 3개 만들고 게임오브젝트를 플레이어 에너미 불렛으로 형변환 시키고 virtual로 각각 클래스에 있는 함수를 가져다가 써야 함 


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
	void draw()
	{
		screen.draw(pos, face);
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

public:
	Bullet(int pos, const char* face, Screen& screen) 
		: GameObject(pos, face, screen), isFiring(false)
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

	void update(int enemy_pos)
	{
		if (isFiring == false) return;
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
		setPosition(pos);
	}
};

#define NORMAL_PLAY 1

#if NORMAL_PLAY
int main()
{
	Screen screen{ 80 };

	Player player = { 30, "(^_^)", screen };
	Enemy enemy{ 60, "(*--*)", screen };
	Bullet bullet( -1, "+", screen);
	
				
	while (true)
	{
		screen.clear();

		if (_kbhit())
		{
			int c = _getch();
			switch (c) {
			case 'a':
				player.moveLeft();
				break;
			case 'd':
				player.moveRight();
				break;
			case ' ':
				bullet.fire(player.getPosition());
				break;
			}
		}
		player.draw();
		enemy.draw();
		bullet.draw();

		player.update();
		enemy.update();
		bullet.update(enemy.getPosition());
		
		screen.render();
		Sleep(66);
	}

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