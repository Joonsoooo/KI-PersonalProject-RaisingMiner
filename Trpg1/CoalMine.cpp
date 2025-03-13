#include "CoalMine.h"

void CoalMine::initializeMine()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> distribution(0.0f, 1.0f);

    for (int y = 0; y < HEIGHT; ++y) // ���� = �� 
    {
        for (int x = 0; x < WIDTH; ++x) // �ʺ� = ��
        {
            float randVal = distribution(gen);  // 0~1���� ����
            if (randVal < 0.40f)
            {
                grid[y][x] = MineralType::ROCK; // �Ϲ� �� 40%
            }
            else if (randVal < 0.70f)
            {
                grid[y][x] = MineralType::COAL; // ��ź 30%
            }
            else if (randVal < 0.85f)
            {
                grid[y][x] = MineralType::IRON; // ö 15%
            }
            else if (randVal < 0.95f)
            {
                grid[y][x] = MineralType::GOLD; // �� 10%
            }
            else {
                grid[y][x] = MineralType::DIAMOND; // ���̾Ƹ�� 5%
            }
        }
    }

    playerX = 0; // ���� ��ġ X
    playerY = 0; // ���� ��ġ Y
    grid[playerY][playerX] = MineralType::NONE; // �÷��̾� ���� ��ġ�� �� �������� ����
}

void CoalMine::Mining()
{
    char input;
    while (true)
    {
        this->player->ShowInventory();
        this->player->showStats();

        gotoxy(0, 0);
        std::cout << "w : ��, a : ��, s : �Ʒ�, d : ����, q : ������";

        gotoxy(0, 3);
        printMine(); // ���� ���� ���

        input = _getch(); // ����Ű �Է� �ޱ�

        Mineral currentMineral = selectMineral(grid[playerY][playerX]); // ���� ���� ��ȯ

        if (input == 'q')
        {
            gotoxy(0, 25);
            player->Move();
            std::cout << std::endl << "System : ���꿡�� �������ϴ�." << std::endl;

            Sleep(2000);
            system("cls");
            break;
        }
        else if (player->getHealth() + player->getAttack() - currentMineral.getHealth() <= currentMineral.getHealth())
        {
            system("cls"); // ȭ�� �����

            gotoxy(0, 27);
            std::cout << "System : ü���� �����մϴ�." << std::endl;
        }
        else if (player->getInventory().getMineralSize() >= 20)
        {
            gotoxy(0, 26);
            std::cout << "�÷��̾� : �� �̻� ���濡 ������ ����" << std::endl << std::endl;
            std::cout << "System : ������ �� á���ϴ�." << std::endl;
        }
        else
        {
            system("cls"); // ȭ�� �����

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
