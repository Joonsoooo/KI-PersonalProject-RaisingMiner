#include "GameStart.h"

GameStart::GameStart()
{

}

void GameStart::gameOpening()
{
    SetConsoleSize(120, 30);

	// ������ ������ �� �׸��� �ܼ��� �÷��̾� �ϳ�
	// 80 x 25 ���� 80�� ���� 25
	// ���� 30 ~ 50, ���� 8 ~ 16

    // ���� �׸��� (��� ǥ��, �� �� ���̿� ��� ������� ����)
    for (short i = 4; i <= 15; ++i) 
    {    // ������ 4�� ����
        // ������ ��ü �κ��� �� ���� �׸���
        COORD roadPos = { 100 - i * 5, 3 + i };
        for (short j = 0; j < 10; ++j) {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (roadPos.X - j), roadPos.Y });
            std::cout << "���"; // ���� �׸�
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (roadPos.X - j), roadPos.Y + 1 });
            std::cout << "���"; // ���� �׸�
        }

        // ������ �߰� �κ��� 2��� ������ ���� (20���� ����)
        for (short j = 0; j < 10; ++j) 
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (roadPos.X + j), roadPos.Y });
            std::cout << "���"; // ���� �߰� �׸�
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (roadPos.X + j), roadPos.Y + 1 });
            std::cout << "���"; // ���� �߰� �׸�
        }
    }

    // ���� �ۿ� ���� �ɱ� (���� ��, ������ �Ʒ�)
    // ���� �� ����
    COORD treePosLeft[] = { { 50, 3 }, { 30, 8 } };
    for (const auto& pos : treePosLeft) 
    {
        // ������ �ٻ�� �κ�
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
        std::cout << " �� ";
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { pos.X - 1, pos.Y + 1 });
        std::cout << " ����";
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { pos.X - 2, pos.Y + 2 });
        std::cout << " ������";

        // ������ �ٱ� �κ�
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { pos.X, pos.Y + 3 });
        std::cout << " �� ";
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { pos.X, pos.Y + 4 });
        std::cout << " �� ";
    }

    // ������ �Ʒ� ����
    COORD treePosRight[] = { { 50, 18 }, { 75, 15 } };
    for (const auto& pos : treePosRight) 
    {
        // ������ �ٻ�� �κ�
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
        std::cout << " �� ";
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { pos.X - 1, pos.Y + 1 });
        std::cout << " ����";
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { pos.X - 2, pos.Y + 2 });
        std::cout << " ������";

        // ������ �ٱ� �κ�
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { pos.X, pos.Y + 3 });
        std::cout << " �� ";
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { pos.X, pos.Y + 4 });
        std::cout << " �� ";
    }

    // ���� �׸��� (�� �׸� 4���� ���� �κп� ���� ��ġ)
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

    // ��̸� ��� �ִ� ��� �׸��� (���� ���� ��)
    COORD minerPos = { 5, 17 }; // ��̸� ��� �ִ� ����� ��ġ

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), minerPos);
    std::cout << " O"; // �Ӹ�
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { minerPos.X, minerPos.Y + 1 });
    std::cout << "/|\\"; // �Ȱ� ��
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { minerPos.X, minerPos.Y + 2 });
    std::cout << "/ \\"; // �ٸ�

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { minerPos.X + 4, minerPos.Y });
    std::cout << "��^��"; // ��� �Ӹ�
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { minerPos.X + 4, minerPos.Y + 1 });
    std::cout << "/ "; // ��� ������ 

    COORD pos = { 47, 24 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    std::cout << "������ ��.";

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

        std::cout << "System : �߸��� �Է��Դϴ�." << std::endl;
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
        std::cout << "System : ������ �����մϴ�" << std::endl;
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
