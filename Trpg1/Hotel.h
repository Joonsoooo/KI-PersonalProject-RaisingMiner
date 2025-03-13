#pragma once
#include <vector>
#include <windows.h>
#include <cstdlib>
#include <map>
#include <list>
#include "time.h"
#include "Food.h"
#include "Player.h"

class Hotel
{
private:
	std::vector<Food> food;
	int friendShip = 0;

public:
	void addFood();

	void hotelSleep(Player& player);
	void Talk();
	void Gift(int choice, Player& player);
	void outputFood();
	void marriageEnding();
	void guessFood(Player& player);

	//void miniGame();
	//void baskinRobbins31(Player& player);


	int getFoodSize();
	int setFriendShip(int num);
	int getFriendShip();
	
	Food sellFood(int choice);
	Food selectFood(int choice);
	std::vector<Food>& getFood();

};

