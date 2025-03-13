#include "Character.h"
#include <string>

Character::Character()
{
}

Character::Character(int n, int a) : health(n), attack(a)
{

}

void Character::setAttack(int a)
{
	attack = a;
}

int Character::getAttack()
{
	return attack;
}

void Character::setDefense(int d)
{
	defense = d;
}

int Character::getDefense()
{
	return defense;
}

void Character::setHealth(int h)
{
	health = h;
}

int Character::getHealth()
{
	return health;
}
