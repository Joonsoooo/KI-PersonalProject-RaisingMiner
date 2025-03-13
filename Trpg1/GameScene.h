#pragma once
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include "Player.h"
#include "Shop.h"
#include "Weapon.h"
#include "Armour.h"
#include "Character.h"
#include "GameStart.h"
#include "Hotel.h"
#include "Stage1.h"

class GameScene
{
private:
    /*Player player; 
    Shop shop;
    Hotel hotel;*/

    GameStart gameStart;
    Stage1 stage1;

public:
    GameScene(); 
    ~GameScene();

    /*void showShopMenu();
    void inventoryMenu();
    void showHotelMenu();*/


    GameStart getGameStart();
    Stage1 getStage1();

    

};
