#include "GameStart.h"

GameStart::GameStart()
{

}

void GameStart::gameOpening()
{
    SetConsoleSize(120, 30);

	// 마을길 나무와 흙 그리고 단순한 플레이어 하나
	// 80 x 25 가로 80에 세로 25
	// 가로 30 ~ 50, 세로 8 ~ 16

    // 도로 그리기 (■로 표현, 두 점 사이에 계단 모양으로 연결)
    for (short i = 4; i <= 15; ++i) 
    {    // 시작을 4로 변경
        // 도로의 전체 부분을 한 번에 그리기
        COORD roadPos = { 100 - i * 5, 3 + i };
        for (short j = 0; j < 10; ++j) {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (roadPos.X - j), roadPos.Y });
            std::cout << "■■"; // 도로 네모
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (roadPos.X - j), roadPos.Y + 1 });
            std::cout << "■■"; // 도로 네모
        }

        // 도로의 중간 부분을 2배로 넓히기 위해 (20개로 증가)
        for (short j = 0; j < 10; ++j) 
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (roadPos.X + j), roadPos.Y });
            std::cout << "■■"; // 도로 중간 네모
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (roadPos.X + j), roadPos.Y + 1 });
            std::cout << "■■"; // 도로 중간 네모
        }
    }

    // 도로 밖에 나무 심기 (왼쪽 위, 오른쪽 아래)
    // 왼쪽 위 나무
    COORD treePosLeft[] = { { 50, 3 }, { 30, 8 } };
    for (const auto& pos : treePosLeft) 
    {
        // 나무의 잎사귀 부분
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
        std::cout << " ▲ ";
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { pos.X - 1, pos.Y + 1 });
        std::cout << " ▲▲▲";
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { pos.X - 2, pos.Y + 2 });
        std::cout << " ▲▲▲▲▲";

        // 나무의 줄기 부분
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { pos.X, pos.Y + 3 });
        std::cout << " ■ ";
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { pos.X, pos.Y + 4 });
        std::cout << " ■ ";
    }

    // 오른쪽 아래 나무
    COORD treePosRight[] = { { 50, 18 }, { 75, 15 } };
    for (const auto& pos : treePosRight) 
    {
        // 나무의 잎사귀 부분
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
        std::cout << " ▲ ";
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { pos.X - 1, pos.Y + 1 });
        std::cout << " ▲▲▲";
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { pos.X - 2, pos.Y + 2 });
        std::cout << " ▲▲▲▲▲";

        // 나무의 줄기 부분
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { pos.X, pos.Y + 3 });
        std::cout << " ■ ";
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { pos.X, pos.Y + 4 });
        std::cout << " ■ ";
    }

    // 바위 그리기 (■ 네모 4줄을 없앤 부분에 바위 배치)
    COORD rockPos = { 75, 1 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), rockPos);
    std::cout << "  @@@@@@@";
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { rockPos.X - 1, rockPos.Y + 1 });
    std::cout << "  @@     @@";
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { rockPos.X - 1, rockPos.Y + 2 });
    std::cout << " @@      @@@";
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { rockPos.X - 1, rockPos.Y + 3 });
    std::cout << "@@@       @@@  ";
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { rockPos.X - 1, rockPos.Y + 4 });
    std::cout << "@@         @@@@";
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { rockPos.X - 2, rockPos.Y + 5 });
    std::cout << "@@@@@@@@@@@@@@@@";

    // 곡괭이를 들고 있는 사람 그리기 (도로 왼쪽 끝)
    COORD minerPos = { 5, 17 }; // 곡괭이를 들고 있는 사람의 위치

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), minerPos);
    std::cout << " O"; // 머리
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { minerPos.X, minerPos.Y + 1 });
    std::cout << "/|\\"; // 팔과 몸
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { minerPos.X, minerPos.Y + 2 });
    std::cout << "/ \\"; // 다리

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { minerPos.X + 4, minerPos.Y });
    std::cout << "Γ^ㄱ"; // 곡괭이 머리
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { minerPos.X + 4, minerPos.Y + 1 });
    std::cout << "/ "; // 곡괭이 손잡이 

    COORD pos = { 47, 24 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    std::cout << "광부의 꿈.";

    pos = { 45, 26 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    std::cout << "1. GameStart";
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { pos.X, pos.Y + 1 });
    std::cout << "2. Leave the game"  << std::endl;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { pos.X+5, pos.Y + 2 });
    int choice;
    std::cin >> choice;

    GameStart::SelectGameMenu(choice);

    if (std::cin.fail())
    {
        Sleep(1500);
        system("cls");

        std::cout << "System : 잘못된 입력입니다." << std::endl;
        std::cin.clear();
        std::cin.ignore();

        Sleep(1500);
        system("cls");

        GameStart::gameOpening();
    }
}

void GameStart::SelectGameMenu(int choice)
{
    if (choice == 1)
    {
        system("cls");
        Sleep(1500);
        std::cout << "System : 게임을 시작합니다" << std::endl;
        Sleep(1500);
        system("cls");
    }
    else if (choice == 2)
    {
        system("exit");
    }
}

int GameStart::GameStartSize()
{
    return gameStart.size();
}
