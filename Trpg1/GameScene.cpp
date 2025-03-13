#include "GameScene.h"
#include "Windows.h"
#include <string>
#include <cstdlib>

GameScene::GameScene()
{
    // 생성자 내부에서 추가 초기화 작업이 필요한 경우 여기에 작성
}

GameScene::~GameScene()
{
    //delete player;
}

/*
void GameScene::showShopMenu()
{
    gotoxy(0, 0);
    std::cout << "System : 상점에 입장했습니다." << std::endl << std::endl;
    std::cout << "상점 주인 : 오늘은 뭐가 필요해서 왔어?" << std::endl;

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
            std::cout << "상점 주인 : 더 거래할게 있나?" << std::endl;
        }

        std::cout << "1. 구매" << std::endl << "2. 판매" << std::endl << "0. 나가기" << std::endl;
        shop.addWeapon();
        shop.addArmour();
        shop.addMaterial();

        std::cout << std::endl;
        std::cin >> choice;

        if (choice == 1)
        {
            std::cout << "1. 무기" << std::endl << "2. 방어구" << std::endl << "3. 아이템" << std::endl;

            std::cout << std::endl;
            std::cin >> choice;

            if (choice == 1)
            {
                shop.outputWeapon();
                std::cout << std::endl << "상점 주인 : 자 골라봐!" << std::endl;
                std::cin >> choice;
                Weapon selectedWeapon = shop.selectWeapon(choice); // 무기 선택

                // 상인이 무기 판매
                if (player.BuyWeapon(selectedWeapon) == 0) // 돈 거래
                {
                    std::cout << std::endl << "System : 소지금이 부족합니다. (무기 구매 실패)" << std::endl;

                    Sleep(3000);
                    system("cls");
                }
                else
                {
                    shop.SellWeapon(choice);
                    player.getInventory().AddWeapon(selectedWeapon); // 인벤토리 추가

                    Sleep(3000);
                    system("cls");
                }
            }
            else if (choice == 2)
            {
                shop.outputArmour();
                std::cout << std::endl << "상점 주인 : 자 골라봐!" << std::endl;

                std::cout << std::endl;
                std::cin >> choice;

                Armour selectedArmour = shop.selectArmour(choice); // 방어구 선택

                if (player.BuyArmour(selectedArmour) == 0) // 상인이 방어구 판매
                {
                    std::cout << std::endl << "System : 소지금이 부족합니다. (방어구 구매 실패)" << std::endl;

                    Sleep(3000);
                    system("cls");
                }
                else
                {
                    shop.SellArmour(choice);
                    player.getInventory().AddArmour(selectedArmour); // 인벤토리 추가

                    Sleep(3000);
                    system("cls");
                }
            }
            else if (choice == 3) // 아이템 구매
            {
                shop.outputMaterial();
                std::cout << std::endl << "상점 주인 : 자 골라봐!" << std::endl;

                std::cout << std::endl;
                std::cin >> choice;

                Material selectedMaterial = shop.selectMaterial(choice); // 재료

                if (player.BuyMaterial(selectedMaterial) == 0) // 상인이 아이템 판매
                {
                    std::cout << std::endl << "System : 소지금이 부족합니다. (아이템 구매 실패)" << std::endl;

                    Sleep(3000);
                    system("cls");
                }
                else
                {
                    shop.SellMaterial(choice);
                    player.getInventory().AddMaterial(selectedMaterial); // 인벤토리 추가

                    Sleep(3000);
                    system("cls");
                }
            }
            else // 1, 2 이외의 입력을 했을 시 
            {
                std::cout << "상점 주인 : 어이 무기랑 방어구 중에 골라야지!!" << std::endl;

                Sleep(3000);
                system("cls");
            }
        }
        else if (choice == 2) //플레이어가 상인에게 판매 
        {
            std::cout << "1. 무기" << std::endl << "2. 방어구" << std::endl << "3. 재료" << std::endl;

            std::cout << std::endl;
            std::cin >> choice;

            if (choice == 1) //무기 팔기 
            {
                if (player.getInventory().getWeaponSize() == 0)
                {
                    std::cout << "상점 주인 : 가지고 있는 무기도 없잖아!" << std::endl;
                    std::cout << std::endl << "System : 가지고 있는 무기가 없습니다. (무기 판매 실패)" << std::endl;

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
            else if (choice == 2) // 방어구 팔기
            {
                if (player.getInventory().getArmourSize() == 0)
                {
                    std::cout << "상점 주인 : 가지고 있는 방어구도 없잖아!" << std::endl;
                    std::cout << std::endl << "System : 가지고 있는 방어구가 없습니다. (방어구 판매 실패)" << std::endl;

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
            std::cout << "상점 주인 : 나중에 또 오게" << std::endl;
            std::cout << std::endl << "System : 상점에서 나갔습니다." << std::endl;

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
        std::cout << "1. 무기" << std::endl << "2. 방어구" << std::endl << "3. 아이템" << std::endl << "0. 인벤토리 닫기" << std::endl;

        std::cout << std::endl;
        std::cin >> choice; // 무기 방어구 선택

        if (choice == 1) // 무기 중 장착, 장착 해제 선택
        {
            std::cout << "1. 장착" << std::endl << "2. 장착 해제" << std::endl;

            std::cout << std::endl;
            std::cin >> choice;

            if (choice == 1) // 무기 장착 
            {
                std::cout << std::endl;
                std::cin >> choice;

                Weapon selectedWeapon = player.getInventory().selectWeapon(choice);
                player.MountedWeapon(selectedWeapon);

                std::cout << "System : 무기를 장착했습니다" << std::endl;

                Sleep(3000);
                system("cls");
            }
            else if (choice == 2) // 무기 장착 해제 
            {
                player.UnequipWeapon();

                Sleep(3000);
                system("cls");
            }
        }
        else if (choice == 2) // 방어구 중 장착 장착 해제 선택
        {
            std::cout << "1. 장착" << std::endl << "2. 장착 해제" << std::endl;
            std::cout << std::endl;
            std::cin >> choice;

            if (choice == 1) // 방어구 장착
            {
                std::cout << std::endl;
                std::cin >> choice;

                Armour selectedArmour = player.getInventory().selectArmour(choice);
                player.MountedArmour(choice);

                std::cout << "방어구를 장착했습니다." << std::endl;

                Sleep(3000);
                system("cls");
                continue;
            }
            else if (choice == 2) // 방어구 장착 해제
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
            std::cout << std::endl << "System : 인벤토리를 닫았습니다." << std::endl;

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
    std::cout << "System : 여관에 입장했습니다." << std::endl << std::endl;
    std::cout << "여관 주인 : 오늘은 뭐 하러 왔어?" << std::endl << std::endl;

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
            std::cout << "여관 주인 : 더 원하는 게 있나?" << std::endl;
        }

        std::cout << "1. 잠자기" << std::endl << "2. 구매" << std::endl << "3. 말하기" << std::endl << "4. 선물주기" << std::endl << "0. 나가기" << std::endl << std::endl;

        std::cin >> choice;

        if (choice == 1)
        {
            hotel.hotelSleep(player);
        }
        else if (choice == 2)
        {
            hotel.outputFood();

            std::cout << std::endl << "여관 주인 : 자 골라봐!" << std::endl;
            std::cin >> choice;
            Food selectedFood = hotel.selectFood(choice); // 음식 선택

            // 상인이 음식 판매
            if (player.BuyFood(selectedFood) == 0) // 돈 거래
            {
                std::cout << std::endl << "System : 소지금이 부족합니다. (음식 구매 실패)" << std::endl;

                Sleep(3000);
                system("cls");
            }
            else
            {
                hotel.sellFood(choice); // 돈 거래

                int newHealth = player.getHealth() + selectedFood.getHealth(); // 음식 버프
                player.setHealth(newHealth);

                Sleep(3000);
                system("cls");
            }
        }
        else if (choice == 3) // 말걸기 
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
            std::cout << "System : 여관을 나갔습니다." << std::endl;

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
