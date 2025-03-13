#pragma once
#include "Character.h"
#include "Inventory.h"
#include "Food.h"
#include "Mineral.h"

class Player : public Character
{
private:
	int price;
	int maxHealth;
	Inventory inventory;

public:

	Player();
	Player(int h, int a, int p);
	~Player();

	void Attack();
	void Miss();
	void Move();
	int SkillAttack(int skill);
	int TakeDamage(int attack);

	int getPrice();
	int getMaxHealth();
	int setPrice(int p);
	void setMaxHealth(int h);

	int BuyWeapon(Weapon w);
	int BuyArmour(Armour a);
	int BuyMaterial(Material m);
	int BuyFood(Food f);
	int SellWeapon(Weapon w);
	int SellArmour(Armour a); 

	void ShowInventory();
	void showStats();

	void MountedWeapon(Weapon& w);
	void UnequipWeapon();
	void MountedArmour(int choice);
	void UnequipArmour(int choice);

	void richEnding();

	Inventory& getInventory();
};

