#include "CreateMine.h"

void CreateMine::resetGrid()
{
	grid.resize(HEIGHT, std::vector<MineralType>(WIDTH, MineralType::NONE)); // 행과 열 크기 조정, 행들을 없음으로 채움
}

void CreateMine::Dig()
{       

    // 플레이어 객체를 포함했을 때
    // 현재 위치에서 파기
    if (playerX >= 0 && playerX < WIDTH && playerY >= 0 && playerY < HEIGHT)
    {
        // 해당 위치에 광물이 있는 경우
        if (grid[playerY][playerX] != MineralType::NONE)
        {

            Mineral currentMineral = selectMineral(grid[playerY][playerX]); // 현재 광물 반환

           gotoxy(0, 25);
           std::cout << "System : " << getMineralName(grid[playerY][playerX]) << "을 획득했습니다." << std::endl; // 광물 얻음
           grid[playerY][playerX] = MineralType::NONE; // 판 곳 없음으로 바꾸기
           int newHealth = player->getHealth() + player->getAttack() - currentMineral.getHealth(); // 체력 감소

           if (newHealth > player->getMaxHealth())
           {
               newHealth = player->getMaxHealth();
           }

           player->getInventory().AddMineral(currentMineral); // 인벤 추가 
           player->setHealth(newHealth);

           if (player->getHealth() <= 0)
           {
               player->setHealth(1);
           }
        }
    }
    /*else
    {
        std::cout << "여길 캐면 광산이 무너질거야!" << std::endl;
    }*/
}

void CreateMine::Move(int dx, int dy)
{
    int newX = playerX + dx;
    int newY = playerY + dy;

    // 새로운 위치가 광산 범위 내인지 확인
    if (newX >= 0 && newX < WIDTH && newY >= 0 && newY < HEIGHT) 
    {
        // 플레이어 이동
        playerX = newX;
        playerY = newY;

        gotoxy(0, 17);
        Dig(); // 이동한 방향으로 파기 (현재 위치에서 파기)
    }
    else 
    {
        gotoxy(0, 24);
        std::cout << "여길 캐면 광산이 무너질거야!" << std::endl;
    }
}


void CreateMine::printMine()
{
    for (int y = 0; y < HEIGHT; ++y) // 높이 = 행
    {
        for (int x = 0; x < WIDTH; ++x) // 너비 = 열
        {
            if (y == playerY && x == playerX)
            {
                std::cout << "p"; // 플레이어 위치
            }
            else if (grid[y][x] == MineralType::NONE)
            {
                std::cout << " "; // 빈 공간
            }
            else
            {
                std::cout << "■"; // 광물이 있는 곳
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

std::string CreateMine::getMineralName(MineralType mineral)
{
    switch (mineral) {
    case MineralType::COAL: return "석탄";
    case MineralType::IRON: return "철";
    case MineralType::GOLD: return "금";
    case MineralType::DIAMOND: return "다이아몬드";
    case MineralType::ROCK: return "돌";
    default: return "None";
    }
}

Mineral CreateMine::selectMineral(MineralType type)
{
    switch (type)
    {
    case MineralType::COAL:
        return Mineral("석탄", 0, 40, "석탄", 10, MineralType::COAL);
    case MineralType::IRON:
        return Mineral("철", 0, 60, "철", 20, MineralType::IRON);
    case MineralType::GOLD:
        return Mineral("금", 0, 80, "금", 40, MineralType::GOLD);
    case MineralType::DIAMOND:
        return Mineral("다이아몬드", 0, 100, "다이아몬드", 100, MineralType::DIAMOND);
    case MineralType::ROCK:
    default:
        return Mineral("돌", 0, 25, "평범한 돌", 5, MineralType::ROCK);
    }
}

Mineral CreateMine::addMineral(MineralType type)
{
    switch (type)
    {
    case MineralType::COAL:
        return Mineral("석탄", 0, 40, "석탄", 10, MineralType::COAL);
    case MineralType::IRON:
        return Mineral("철", 0, 60, "철", 20, MineralType::IRON);
    case MineralType::GOLD:
        return Mineral("금", 0, 80, "금", 40, MineralType::GOLD);
    case MineralType::DIAMOND:
        return Mineral("다이아몬드", 0, 100, "다이아몬드", 100, MineralType::DIAMOND);
    case MineralType::ROCK:
    default:
        return Mineral("돌", 0, 25, "평범한 돌", 5, MineralType::ROCK);
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

