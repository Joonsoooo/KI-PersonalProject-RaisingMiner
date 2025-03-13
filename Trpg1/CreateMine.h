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
	Player *player;// 포인터 
	// 참조 형식 


	std::vector<std::vector<MineralType>> grid;

public:

	void resetGrid(); // 광산 크기 조절
	void Dig();
	void Move(int dx, int dy);
	void printMine();

	std::string getMineralName(MineralType mineral);

	Mineral selectMineral(MineralType type);
	Mineral addMineral(MineralType type);
	virtual void initializeMine(); // 광물 확률 조절

	int getWIDTH();
	int getHEIGHT();
	int getPlayerX();
	int getPlayerY();

	void setPlayer(Player *player);

	int setPlayerX(int x);
	int setPlayerY(int y);

	std::vector<std::vector<MineralType>> getGrid();

	// 캐면 광물에 따라 체력 감소
	// 나가기
	// 캔 광물 인벤으로 이동 

};

