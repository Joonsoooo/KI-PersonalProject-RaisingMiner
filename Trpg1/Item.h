#pragma once
#include <iostream>
#include <string>

class Item
{
private:
	std::string name;
	std::string description;
	int attack;
	int health;
	int price;

public:
	Item();
	Item(std::string name, int a, int health, std::string d, int p);



	std::string getName();
	std::string getDescription();
	int getAttack();
	int getHealth();
	int getPrice();
};

