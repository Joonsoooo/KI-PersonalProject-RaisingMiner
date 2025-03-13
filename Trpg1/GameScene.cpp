#include "GameScene.h"
#include "Windows.h"
#include <string>
#include <cstdlib>

GameScene::GameScene()
{
    // ������ ���ο��� �߰� �ʱ�ȭ �۾��� �ʿ��� ��� ���⿡ �ۼ�
}

GameScene::~GameScene()
{
    //delete player;
}

/*
void GameScene::showShopMenu()
{
    gotoxy(0, 0);
    std::cout << "System : ������ �����߽��ϴ�." << std::endl << std::endl;
    std::cout << "���� ���� : ������ ���� �ʿ��ؼ� �Ծ�?" << std::endl;

    std::cout << std::endl;
    int choice;

    int i = 0;
    while (true)
    {
        player.ShowInventory();

        if (i == 0)
        {
            gotoxy(0, 4);
        }

        if (i >= 1)
        {
            gotoxy(0, 0);
            std::cout << "���� ���� : �� �ŷ��Ұ� �ֳ�?" << std::endl;
        }

        std::cout << "1. ����" << std::endl << "2. �Ǹ�" << std::endl << "0. ������" << std::endl;
        shop.addWeapon();
        shop.addArmour();
        shop.addMaterial();

        std::cout << std::endl;
        std::cin >> choice;

        if (choice == 1)
        {
            std::cout << "1. ����" << std::endl << "2. ��" << std::endl << "3. ������" << std::endl;

            std::cout << std::endl;
            std::cin >> choice;

            if (choice == 1)
            {
                shop.outputWeapon();
                std::cout << std::endl << "���� ���� : �� ����!" << std::endl;
                std::cin >> choice;
                Weapon selectedWeapon = shop.selectWeapon(choice); // ���� ����

                // ������ ���� �Ǹ�
                if (player.BuyWeapon(selectedWeapon) == 0) // �� �ŷ�
                {
                    std::cout << std::endl << "System : �������� �����մϴ�. (���� ���� ����)" << std::endl;

                    Sleep(3000);
                    system("cls");
                }
                else
                {
                    shop.SellWeapon(choice);
                    player.getInventory().AddWeapon(selectedWeapon); // �κ��丮 �߰�

                    Sleep(3000);
                    system("cls");
                }
            }
            else if (choice == 2)
            {
                shop.outputArmour();
                std::cout << std::endl << "���� ���� : �� ����!" << std::endl;

                std::cout << std::endl;
                std::cin >> choice;

                Armour selectedArmour = shop.selectArmour(choice); // �� ����

                if (player.BuyArmour(selectedArmour) == 0) // ������ �� �Ǹ�
                {
                    std::cout << std::endl << "System : �������� �����մϴ�. (�� ���� ����)" << std::endl;

                    Sleep(3000);
                    system("cls");
                }
                else
                {
                    shop.SellArmour(choice);
                    player.getInventory().AddArmour(selectedArmour); // �κ��丮 �߰�

                    Sleep(3000);
                    system("cls");
                }
            }
            else if (choice == 3) // ������ ����
            {
                shop.outputMaterial();
                std::cout << std::endl << "���� ���� : �� ����!" << std::endl;

                std::cout << std::endl;
                std::cin >> choice;

                Material selectedMaterial = shop.selectMaterial(choice); // ���

                if (player.BuyMaterial(selectedMaterial) == 0) // ������ ������ �Ǹ�
                {
                    std::cout << std::endl << "System : �������� �����մϴ�. (������ ���� ����)" << std::endl;

                    Sleep(3000);
                    system("cls");
                }
                else
                {
                    shop.SellMaterial(choice);
                    player.getInventory().AddMaterial(selectedMaterial); // �κ��丮 �߰�

                    Sleep(3000);
                    system("cls");
                }
            }
            else // 1, 2 �̿��� �Է��� ���� �� 
            {
                std::cout << "���� ���� : ���� ����� �� �߿� ������!!" << std::endl;

                Sleep(3000);
                system("cls");
            }
        }
        else if (choice == 2) //�÷��̾ ���ο��� �Ǹ� 
        {
            std::cout << "1. ����" << std::endl << "2. ��" << std::endl << "3. ���" << std::endl;

            std::cout << std::endl;
            std::cin >> choice;

            if (choice == 1) //���� �ȱ� 
            {
                if (player.getInventory().getWeaponSize() == 0)
                {
                    std::cout << "���� ���� : ������ �ִ� ���⵵ ���ݾ�!" << std::endl;
                    std::cout << std::endl << "System : ������ �ִ� ���Ⱑ �����ϴ�. (���� �Ǹ� ����)" << std::endl;

                    Sleep(3000);
                    system("cls");
                }
                else
                {
                    player.getInventory().ShowWeapon();

                    std::cout << std::endl;
                    std::cin >> choice;

                    Weapon selectedWeapon = player.getInventory().sellSelectWeapon(choice);

                    Sleep(3000);
                    system("cls");
                }
            }
            else if (choice == 2) // �� �ȱ�
            {
                if (player.getInventory().getArmourSize() == 0)
                {
                    std::cout << "���� ���� : ������ �ִ� ���� ���ݾ�!" << std::endl;
                    std::cout << std::endl << "System : ������ �ִ� ���� �����ϴ�. (�� �Ǹ� ����)" << std::endl;

                    Sleep(3000);
                    system("cls");
                }
                else
                {
                    player.getInventory().ShowArmour();

                    std::cout << std::endl;
                    std::cin >> choice;

                    Armour selectedArmour = player.getInventory().sellSelectArmour(choice);

                    Sleep(3000);
                    system("cls");
                }
            }
            else if (choice == 3)
            {
                // Handle material selling if applicable
            }
        }
        else if (choice == 0)
        {
            std::cout << "���� ���� : ���߿� �� ����" << std::endl;
            std::cout << std::endl << "System : �������� �������ϴ�." << std::endl;

            Sleep(5000);
            system("cls");
            break;
        }

        i++;
    }
}

void GameScene::inventoryMenu()
{
    int choice;

    while (true)
    {
        player.ShowInventory();
        player.showStats();

        gotoxy(0, 0);
        std::cout << "1. ����" << std::endl << "2. ��" << std::endl << "3. ������" << std::endl << "0. �κ��丮 �ݱ�" << std::endl;

        std::cout << std::endl;
        std::cin >> choice; // ���� �� ����

        if (choice == 1) // ���� �� ����, ���� ���� ����
        {
            std::cout << "1. ����" << std::endl << "2. ���� ����" << std::endl;

            std::cout << std::endl;
            std::cin >> choice;

            if (choice == 1) // ���� ���� 
            {
                std::cout << std::endl;
                std::cin >> choice;

                Weapon selectedWeapon = player.getInventory().selectWeapon(choice);
                player.MountedWeapon(selectedWeapon);

                std::cout << "System : ���⸦ �����߽��ϴ�" << std::endl;

                Sleep(3000);
                system("cls");
            }
            else if (choice == 2) // ���� ���� ���� 
            {
                player.UnequipWeapon();

                Sleep(3000);
                system("cls");
            }
        }
        else if (choice == 2) // �� �� ���� ���� ���� ����
        {
            std::cout << "1. ����" << std::endl << "2. ���� ����" << std::endl;
            std::cout << std::endl;
            std::cin >> choice;

            if (choice == 1) // �� ����
            {
                std::cout << std::endl;
                std::cin >> choice;

                Armour selectedArmour = player.getInventory().selectArmour(choice);
                player.MountedArmour(choice);

                std::cout << "���� �����߽��ϴ�." << std::endl;

                Sleep(3000);
                system("cls");
                continue;
            }
            else if (choice == 2) // �� ���� ����
            {
                std::cout << std::endl;
                std::cin >> choice;

                Armour selectedArmour = player.getInventory().selectArmour(choice);
                player.UnequipArmour(choice);

                Sleep(3000);
                system("cls");
            }
        }
        else if (choice == 3)
        {
            // Handle item menu if applicable
        }
        else if (choice == 0)
        {
            std::cout << std::endl << "System : �κ��丮�� �ݾҽ��ϴ�." << std::endl;

            Sleep(3000);
            system("cls");
            break;
        }
    }
}

void GameScene::showHotelMenu()
{
    if (hotel.getFriendShip() >= 100)
    {
        hotel.marriageEnding();
    }

    int choice;

    hotel.addFood();

    gotoxy(0, 0);
    std::cout << "System : ������ �����߽��ϴ�." << std::endl << std::endl;
    std::cout << "���� ���� : ������ �� �Ϸ� �Ծ�?" << std::endl << std::endl;

    int i = 0;
    while (true)
    {
        player.ShowInventory();
        player.showStats();

        if (i == 0)
        {
            gotoxy(0, 3);
        }

        if (i >= 1)
        {
            gotoxy(0, 0);
            std::cout << "���� ���� : �� ���ϴ� �� �ֳ�?" << std::endl;
        }

        std::cout << "1. ���ڱ�" << std::endl << "2. ����" << std::endl << "3. ���ϱ�" << std::endl << "4. �����ֱ�" << std::endl << "0. ������" << std::endl << std::endl;

        std::cin >> choice;

        if (choice == 1)
        {
            hotel.hotelSleep(player);
        }
        else if (choice == 2)
        {
            hotel.outputFood();

            std::cout << std::endl << "���� ���� : �� ����!" << std::endl;
            std::cin >> choice;
            Food selectedFood = hotel.selectFood(choice); // ���� ����

            // ������ ���� �Ǹ�
            if (player.BuyFood(selectedFood) == 0) // �� �ŷ�
            {
                std::cout << std::endl << "System : �������� �����մϴ�. (���� ���� ����)" << std::endl;

                Sleep(3000);
                system("cls");
            }
            else
            {
                hotel.sellFood(choice); // �� �ŷ�

                int newHealth = player.getHealth() + selectedFood.getHealth(); // ���� ����
                player.setHealth(newHealth);

                Sleep(3000);
                system("cls");
            }
        }
        else if (choice == 3) // ���ɱ� 
        {
            std::cout << std::endl;
            hotel.Talk();
        }
        else if (choice == 4)
        {
            std::cin >> choice;

            hotel.Gift(choice, player);
        }
        else if (choice == 0)
        {
            std::cout << "System : ������ �������ϴ�." << std::endl;

            break;
        }

        i++;
    }
}

*/

GameStart GameScene::getGameStart()
{
    return gameStart;
}

Stage1 GameScene::getStage1()
{
    return stage1;
}
