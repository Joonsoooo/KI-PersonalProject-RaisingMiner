#include "Weapon.h"
#include <string>

Weapon::Weapon(std::string n, int a, int defense, std::string wD, int p) : Item(n, a, defense, wD, p)
{

}

Weapon::Weapon()
{
}
