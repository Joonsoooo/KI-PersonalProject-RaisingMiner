#pragma once
#include <iostream>
#include <string>
#include <vector>

class Character
{
private:
	int health;
	int attack;
	int defense;
	std::string name;
	std::string skill;

public:
	Character();
	Character(int h, int a);

	virtual void Attack() = 0; // 공격할 때 할 말
	virtual void Miss() = 0; // 공격력이 0이거나 미스가 났을 때 할 말
	void Move(); // 움직일 때 할 말 상황 마다 다르게?
	virtual int SkillAttack(int skill) = 0; // 스킬 쓸 때 할 말
	virtual int TakeDamage(int attack) = 0; // 데미지를 입음

	void setAttack(int a);
	int getAttack();
	void setDefense(int d);
	int getDefense();
	void setHealth(int h);
	int getHealth();
};

