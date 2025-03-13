#pragma once
#include <string>
#include "Item.h"

enum class MineralType {
    NONE,
    ROCK,
    COAL,
    IRON,
    GOLD,
    DIAMOND,
};

class Mineral : public Item
{
private:
    MineralType type;
public:
    Mineral();
    Mineral(std::string n, int a, int health, std::string aD, int price, MineralType t);

};

