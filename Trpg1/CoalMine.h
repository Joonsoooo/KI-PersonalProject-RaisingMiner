#pragma once
#include "CreateMine.h"
#include <iostream>
#include <vector>
#include <random>
#include <conio.h>

class CoalMine : public CreateMine
{
private:


public:
	void initializeMine() override; // 광물로 채우기
	void Mining();
};

