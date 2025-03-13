#pragma once
#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include "Mineral.h"
#include "Player.h"

class CreateMine 
{
protected:
	const int WIDTH = 25;
	const int HEIGHT = 20;
	int playerX, playerY;
	Player *player;// ������ 
	// ���� ���� 


	std::vector<std::vector<MineralType>> grid;

public:

	void resetGrid(); // ���� ũ�� ����
	void Dig();
	void Move(int dx, int dy);
	void printMine();

	std::string getMineralName(MineralType mineral);

	Mineral selectMineral(MineralType type);
	Mineral addMineral(MineralType type);
	virtual void initializeMine(); // ���� Ȯ�� ����

	int getWIDTH();
	int getHEIGHT();
	int getPlayerX();
	int getPlayerY();

	void setPlayer(Player *player);

	int setPlayerX(int x);
	int setPlayerY(int y);

	std::vector<std::vector<MineralType>> getGrid();

	// ĳ�� ������ ���� ü�� ����
	// ������
	// ĵ ���� �κ����� �̵� 

};

