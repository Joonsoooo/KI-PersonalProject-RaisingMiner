#pragma once
#include "CreateMine.h"
#include <iostream>
#include <vector>
#include <random>
#include <conio.h>

class GoldMine : public CreateMine
{
public:
	void initializeMine() override;
	void Mining();
};

