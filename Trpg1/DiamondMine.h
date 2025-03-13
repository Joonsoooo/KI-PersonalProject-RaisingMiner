#pragma once
#include "CreateMine.h"
#include <iostream>
#include <vector>
#include <random>
#include <conio.h>

class DiamondMine : public CreateMine
{
public:
	void initializeMine() override;
	void Mining();
};

