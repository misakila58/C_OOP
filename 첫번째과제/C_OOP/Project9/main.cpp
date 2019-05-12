//1. 플레이어는 방향성을 가진다.오른쪽으로 이동하고자 한다면 머리방향이 먼저 오른쪽으로 방향전환한 후 이동한다.머리 방향이 전환되었다는 것을 확인하기 위해 머리모양에 해당하는 그림을 표시하도록 한다.
//2. 플레이어는 공격시에 현재 방향으로만 공격가능하다.
//3. 플레이어의 공격 무기로는(1) 총, (2) 레이저건 이 있다.총은 단발의 데미지량은 1인 반면 레이저건의 데미지량은 2초간 지속적으로 데미지를 준다.레어저건의 초당 데미지량은 1에 해당한다.레이저건의 경우, 
//   타켓의 위치와 플레이어의 위치를 일직선으로 이어서 공격을 지속적으로 받고 있다는 것을 알려준다.
//4. 총 공격의 경우, 총 10발의 총알이 있으며 연사 가능하며 비어 있을 경우, 1초당 한 발씩 총알이 자동 추가된다.단, 총알이 없어야 자동 장전이 가능하다. 10초간 기다리면 모두 장전할 수 있으나 기다리지 못하고 총알을 쏘게되면 추가로 1초당 한 발씩 총알이 자동 추가되지 않는다.
//5. 레이저건 공격의 경우, 2초간 공격후, 3초간 cooltime이 적용된다.
//6. 공격시 플레이어 공격의 반대방향에 현재 공격의 상태 정보(총 공격의 경우, 남은 총알 수, 10발 재장전까지 남은 시간 등; 레이저건 공격의 경우, 남은 공격 시간, 쿨 타임시 남은 시간 등)를 보여준다.
//7. 공격 전환의 경우, ‘m’키를 이용한다.
//8. 공격 상태 정보는 공격시에만 1초간 화면에 보인다.
//9. 적은 매 10초마다 임의의 위치에서 나타나며 적의 위치를 기준으로 5m 이내 플레이어는 독 공격을 받는다.
//10. 적의 독공격은 매초 2만큼 데미지를 주며 3초간 지속된다.지속 공격시 플레이어의 hp값이 줄어드는 것을 화면에 보이도록 한다.적은 3초 지속 공격후, 2초간 cooltime을 갖는다.
//11. 화면상에 보일 수 있는 최대 적의 개수는 5마리이다. (동일 위치에 적이 겹쳐 있으면 보이지 않을 수 있다)
//12. 적은 2초당 1m만큼의 속도로 플레이어를 향해 이동한다.
//13. 적, 플레이어는 모두 hp를 가지며 적은 5, 플레이어는 10만큼 갖는다.
//14. 플레이어가 죽은 시점에 게임은 종료되며 플레이어가 살아 있었던 시간과 죽인 적들의 개수를 화면에 보여준 후 게임을 종료한다.
//15. 플레이어의 공격시 공격방향으로 여러 적들이 있으면 가장 가까운 적부터 공격한다.

#include "stdafx.h"
#include "player.h"
#include "enemy.h"
#include "bullet.h"

int main()
{
	int a = 0;
	Screen screen{ 80 };
	Player player = { 30, "(^_^)", &screen,1 };
	Enemy enemy{ 60, "(*--*)", &screen,3 };
	Bullet* bullets[10];

	
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
			case 'm':
				player.changeweapon();
				break;
			case ' ':
						Bullet* bullet = new Bullet(-1, "+", &screen);
						bullets[a] = bullet;
						bullets[a]->fire(player.getPosition(), player.getLeft(), player.getFaceLen(), player.getWeapontype());
						a++;
						if (a == 9)
							a = 0;

				break;
			}
		}

		player.draw();
		enemy.draw();

		for (int i = 0; i < a; i++)
		{
			bullets[i]->draw();
		}
		player.update();
		enemy.update();  
		
		for (int i = 0; i < a; i++)
		{
			bullets[i]->update(enemy.getPosition());
		}
		

		screen.render();
		Sleep(66);
	}

	return 0;
}

