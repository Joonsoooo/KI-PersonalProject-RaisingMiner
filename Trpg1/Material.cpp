#include "Material.h"

Material::Material()
{
}

Material::Material(std::string name, int a, int health, std::string d, int p) : Item(name, a, health, d, p)
{
}
