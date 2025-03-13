#pragma once
#include "Item.h"

class Food : public Item
{
private:

public:
	Food(std::string name, int a, int health, std::string d, int p);
	Food();
};

