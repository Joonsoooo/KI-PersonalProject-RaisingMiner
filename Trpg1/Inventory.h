#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include "Weapon.h"
#include "Armour.h"
#include "Material.h"
#include "Mineral.h"
#include "gotoxy.h"


class Inventory
{
private:
    std::vector<Weapon> wI; // 0π¯ ¿Œµ¶Ω∫ø° ¿÷¿∏∏È ¿Â¬¯
    std::vector<Armour> aI; // 0, 1, 2 ∞¢ «Ô∏‰ ∞©ø  πŸ¡ˆ∑Œ ¿Â¬¯
    std::vector<Material> mI;
    std::vector<Mineral> minI;
    int price;

public:

    void AddWeapon(Weapon w);
    void AddArmour(Armour a);
    void AddMaterial(Material m);
    void AddMineral(Mineral m);
    void RemoveWeapon();
    void RemoveWeapon(Weapon w);
    void RemoveArmour();
    void RemoveArmour(Armour a);
    void fronAddWeapon(Weapon w);

    void ShowInventory();
    void ShowWeapon();
    void ShowArmour();
    void ShowMaterial();

    int getWeaponSize();
    int getArmourSize();
    int getMaterialSize();
    int getMineralSize();

    Weapon selectWeapon(int choice);
    Armour selectArmour(int choice);

    Weapon sellSelectWeapon(int choice);
    Armour sellSelectArmour(int choice);
    Mineral sellSelectMineral(int choice);

    std::vector<Weapon>& getWeapon();
    std::vector<Armour>& getArmour();
    std::vector<Material>& getMaterial();
    std::vector<Mineral>& getMineral();

    Weapon& getWeaponAt(int index);
    Armour& getArmourAt(int index);
};

