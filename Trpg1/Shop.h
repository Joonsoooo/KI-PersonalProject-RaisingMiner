#pragma once
#include <iostream>
#include <vector>
#include <conio.h>
#include "Weapon.h"
#include "Armour.h"
#include "Player.h"
#include "Material.h"


class Shop
{
private:
	std::vector<Weapon> weapon;
	std::vector<Armour> armour;
	std::vector<Material> material;
	

public:
	Shop();
	~Shop();

	void addWeapon();
	void addWeapon(Weapon w);
	void addArmour();
	void addArmour(Armour a);
	void addMaterial();
	void buyWeapon(Weapon w, Player p); // 상점이 사는 거
	void buyArmour(Armour a, Player p);
	void buyMaterial(Material m, Player p);
	void outputWeapon();
	void outputArmour();
	void outputMaterial();
	int SellWeapon(int choice); // 상점이 파는 거
	int SellArmour(int choice);
	int SellMaterial(int choice);
	int getWeaponSize();
	int getArmourSize();
	int getMaterialSize();
	int selectWeapon(int choice, Weapon& selectedWeapon);
	int selectArmour(int choice, Armour& selectedArmour);
	int selectMaterial(int choice, Material& selectedMaterial);

};

