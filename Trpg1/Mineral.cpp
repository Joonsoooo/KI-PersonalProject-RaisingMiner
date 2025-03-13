#include "Mineral.h"

Mineral::Mineral()
{
}

Mineral::Mineral(std::string n, int a, int health, std::string aD, int p, MineralType t) : Item(n, a, health, aD, p), type(t)
{

}