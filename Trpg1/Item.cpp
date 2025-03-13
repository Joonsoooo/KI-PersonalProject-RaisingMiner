#include "Item.h"
#include <string>

Item::Item()
{
}

Item::Item(std::string name, int a, int health, std::string d, int p) : name(name), attack(a), health(health), description(d), price(p)
{
}

std::string Item::getName()
{
	return name;
}

std::string Item::getDescription()
{
	return description;
}

int Item::getAttack()
{
	return attack;
}

int Item::getHealth()
{
	return health;
}

int Item::getPrice()
{
	return price;
}


