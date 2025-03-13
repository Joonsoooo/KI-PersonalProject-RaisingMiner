#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "gotoxy.h"
#include "setConsoleSize.h"

class GameStart
{
private:
	std::vector<std::string> gameStart = { "GameStart", "Leave the game" };

public:
	GameStart();

	void ShowGameMenu();
	void SelectGameMenu(int choice);
	int GameStartSize();
	void StartGame();
	void gameOpening();
};



