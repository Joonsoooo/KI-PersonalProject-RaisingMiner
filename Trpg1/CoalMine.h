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
	void initializeMine() override; // ������ ä���
	void Mining();
};

