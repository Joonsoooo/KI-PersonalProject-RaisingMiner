#include "CoalMine.h"

void CoalMine::initializeMine()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> distribution(0.0f, 1.0f);

    for (int y = 0; y < HEIGHT; ++y) // 높이 = 행 
    {
        for (int x = 0; x < WIDTH; ++x) // 너비 = 열
        {
            float randVal = distribution(gen);  // 0~1까지 난수
            if (randVal < 0.40f)
            {
                grid[y][x] = MineralType::ROCK; // 일반 돌 40%
            }
            else if (randVal < 0.70f)
            {
                grid[y][x] = MineralType::COAL; // 석탄 30%
            }
            else if (randVal < 0.85f)
            {
                grid[y][x] = MineralType::IRON; // 철 15%
            }
            else if (randVal < 0.95f)
            {
                grid[y][x] = MineralType::GOLD; // 금 10%
            }
            else {
                grid[y][x] = MineralType::DIAMOND; // 다이아몬드 5%
            }
        }
    }

    playerX = 0; // 시작 위치 X
    playerY = 0; // 시작 위치 Y
    grid[playerY][playerX] = MineralType::NONE; // 플레이어 시작 위치를 빈 공간으로 설정
}

void CoalMine::Mining()
{
    char input;
    while (true)
    {
        this->player->ShowInventory();
        this->player->showStats();

        gotoxy(0, 0);
        std::cout << "w : 위, a : 왼, s : 아래, d : 오른, q : 나가기";

        gotoxy(0, 3);
        printMine(); // 광산 상태 출력

        input = _getch(); // 방향키 입력 받기

        Mineral currentMineral = selectMineral(grid[playerY][playerX]); // 현재 광물 반환

        if (input == 'q')
        {
            gotoxy(0, 25);
            player->Move();
            std::cout << std::endl << "System : 광산에서 나갔습니다." << std::endl;

            Sleep(2000);
            system("cls");
            break;
        }
        else if (player->getHealth() + player->getAttack() - currentMineral.getHealth() <= currentMineral.getHealth())
        {
            system("cls"); // 화면 지우기

            gotoxy(0, 27);
            std::cout << "System : 체력이 부족합니다." << std::endl;
        }
        else if (player->getInventory().getMineralSize() >= 20)
        {
            gotoxy(0, 26);
            std::cout << "플레이어 : 더 이상 가방에 공간이 없어" << std::endl << std::endl;
            std::cout << "System : 가방이 꽉 찼습니다." << std::endl;
        }
        else
        {
            system("cls"); // 화면 지우기

            if (input == 'w')
            {
                CreateMine::Move(0, -1);
            }
            else if (input == 's')
            {
                CreateMine::Move(0, 1);
            }
            else if (input == 'a')
            {
                CreateMine::Move(-1, 0);
            }
            else if (input == 'd')
            {
                CreateMine::Move(1, 0);
            }
   
        }

    }
}
