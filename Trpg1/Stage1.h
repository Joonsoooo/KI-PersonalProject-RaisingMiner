#pragma once
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <limits>
#include "Player.h"
#include "Shop.h"
#include "Weapon.h"
#include "Armour.h"
#include "Character.h"
#include "GameStart.h"
#include "Hotel.h"
#include "CoalMine.h"
#include "IronMine.h"
#include "GoldMine.h"
#include "DiamondMine.h"


class Stage1
{
private:
	Player player;
	Shop shop;
	GameStart gameStart;
	Hotel hotel;
	CoalMine coalMine;
	IronMine ironMine;
	GoldMine goldMine;
	DiamondMine diamondMine;




public:
	Stage1();
	
	void selectActMenu(); //1. 상점, 2. 던전, 3. 여관, 4. 집, 5.인벤토리 등등
	void showShopMenu();
	void showInventoryMenu();
	void showHotelMenu();
	void showMineMenu();

};

