#include <iostream>
#include <vector>
#include <string>
#include "Player.h"
#include "Armour.h"
#include "Weapon.h"
#include "GameScene.h"
#include "Shop.h"

int main()
{
	GameScene G;
	Stage1 S = G.getStage1();


	G.getGameStart().gameOpening(); // ���� ���� 

	while (true)
	{
		S.selectActMenu();
	}
}
