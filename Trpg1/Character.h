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

	virtual void Attack() = 0; // ������ �� �� ��
	virtual void Miss() = 0; // ���ݷ��� 0�̰ų� �̽��� ���� �� �� ��
	void Move(); // ������ �� �� �� ��Ȳ ���� �ٸ���?
	virtual int SkillAttack(int skill) = 0; // ��ų �� �� �� ��
	virtual int TakeDamage(int attack) = 0; // �������� ����

	void setAttack(int a);
	int getAttack();
	void setDefense(int d);
	int getDefense();
	void setHealth(int h);
	int getHealth();
};

