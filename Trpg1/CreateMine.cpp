#include "CreateMine.h"

void CreateMine::resetGrid()
{
	grid.resize(HEIGHT, std::vector<MineralType>(WIDTH, MineralType::NONE)); // ��� �� ũ�� ����, ����� �������� ä��
}

void CreateMine::Dig()
{       

    // �÷��̾� ��ü�� �������� ��
    // ���� ��ġ���� �ı�
    if (playerX >= 0 && playerX < WIDTH && playerY >= 0 && playerY < HEIGHT)
    {
        // �ش� ��ġ�� ������ �ִ� ���
        if (grid[playerY][playerX] != MineralType::NONE)
        {

            Mineral currentMineral = selectMineral(grid[playerY][playerX]); // ���� ���� ��ȯ

           gotoxy(0, 25);
           std::cout << "System : " << getMineralName(grid[playerY][playerX]) << "�� ȹ���߽��ϴ�." << std::endl; // ���� ����
           grid[playerY][playerX] = MineralType::NONE; // �� �� �������� �ٲٱ�
           int newHealth = player->getHealth() + player->getAttack() - currentMineral.getHealth(); // ü�� ����

           if (newHealth > player->getMaxHealth())
           {
               newHealth = player->getMaxHealth();
           }

           player->getInventory().AddMineral(currentMineral); // �κ� �߰� 
           player->setHealth(newHealth);

           if (player->getHealth() <= 0)
           {
               player->setHealth(1);
           }
        }
    }
    /*else
    {
        std::cout << "���� ĳ�� ������ �������ž�!" << std::endl;
    }*/
}

void CreateMine::Move(int dx, int dy)
{
    int newX = playerX + dx;
    int newY = playerY + dy;

    // ���ο� ��ġ�� ���� ���� ������ Ȯ��
    if (newX >= 0 && newX < WIDTH && newY >= 0 && newY < HEIGHT) 
    {
        // �÷��̾� �̵�
        playerX = newX;
        playerY = newY;

        gotoxy(0, 17);
        Dig(); // �̵��� �������� �ı� (���� ��ġ���� �ı�)
    }
    else 
    {
        gotoxy(0, 24);
        std::cout << "���� ĳ�� ������ �������ž�!" << std::endl;
    }
}


void CreateMine::printMine()
{
    for (int y = 0; y < HEIGHT; ++y) // ���� = ��
    {
        for (int x = 0; x < WIDTH; ++x) // �ʺ� = ��
        {
            if (y == playerY && x == playerX)
            {
                std::cout << "p"; // �÷��̾� ��ġ
            }
            else if (grid[y][x] == MineralType::NONE)
            {
                std::cout << " "; // �� ����
            }
            else
            {
                std::cout << "��"; // ������ �ִ� ��
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

std::string CreateMine::getMineralName(MineralType mineral)
{
    switch (mineral) {
    case MineralType::COAL: return "��ź";
    case MineralType::IRON: return "ö";
    case MineralType::GOLD: return "��";
    case MineralType::DIAMOND: return "���̾Ƹ��";
    case MineralType::ROCK: return "��";
    default: return "None";
    }
}

Mineral CreateMine::selectMineral(MineralType type)
{
    switch (type)
    {
    case MineralType::COAL:
        return Mineral("��ź", 0, 40, "��ź", 10, MineralType::COAL);
    case MineralType::IRON:
        return Mineral("ö", 0, 60, "ö", 20, MineralType::IRON);
    case MineralType::GOLD:
        return Mineral("��", 0, 80, "��", 40, MineralType::GOLD);
    case MineralType::DIAMOND:
        return Mineral("���̾Ƹ��", 0, 100, "���̾Ƹ��", 100, MineralType::DIAMOND);
    case MineralType::ROCK:
    default:
        return Mineral("��", 0, 25, "����� ��", 5, MineralType::ROCK);
    }
}

Mineral CreateMine::addMineral(MineralType type)
{
    switch (type)
    {
    case MineralType::COAL:
        return Mineral("��ź", 0, 40, "��ź", 10, MineralType::COAL);
    case MineralType::IRON:
        return Mineral("ö", 0, 60, "ö", 20, MineralType::IRON);
    case MineralType::GOLD:
        return Mineral("��", 0, 80, "��", 40, MineralType::GOLD);
    case MineralType::DIAMOND:
        return Mineral("���̾Ƹ��", 0, 100, "���̾Ƹ��", 100, MineralType::DIAMOND);
    case MineralType::ROCK:
    default:
        return Mineral("��", 0, 25, "����� ��", 5, MineralType::ROCK);
    }
}

void CreateMine::initializeMine()
{
}

int CreateMine::getWIDTH()
{
	return WIDTH;
}

int CreateMine::getHEIGHT()
{
	return HEIGHT;
}

void CreateMine::setPlayer(Player *player) {
    this->player = player;
}

int CreateMine::getPlayerX()
{
    return playerX;
}

int CreateMine::getPlayerY()
{
    return playerY;
}

int CreateMine::setPlayerX(int x)
{
    playerX = x;
    return playerX;
}

int CreateMine::setPlayerY(int y)
{
    playerY = y;
    return playerY;
}

std::vector<std::vector<MineralType>> CreateMine::getGrid()
{
    return grid;
}

