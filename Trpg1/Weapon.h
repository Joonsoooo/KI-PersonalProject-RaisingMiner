#pragma once
#include "Item.h"
#include <iostream>
#include <string>
#include <vector>

class Weapon : public Item
{

public:
	Weapon(std::string n, int a, int defense, std::string wD, int p);
	Weapon();

};

