#pragma once
#include "Item.h"

class Material : public Item
{
public:
	Material();
	Material(std::string name, int a, int health, std::string d, int p);

};

