#include "Armour.h"
#include <string>

Armour::Armour(std::string n, int a, int health, std::string aD, int p, ArmourType t) : Item(n, a, health, aD, p), type(t) 
{
}

Armour::Armour()
{
}

ArmourType Armour::getType() const {
    return type;
}