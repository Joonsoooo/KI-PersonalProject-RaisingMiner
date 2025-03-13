#include "Stage1.h"

Stage1::Stage1() : player(100, 5, 0)
{
	player.setMaxHealth(111);
	shop.addArmour();
	shop.addWeapon();
	shop.addMaterial();
}

void Stage1::selectActMenu()
{
	if (player.getPrice() >= 1000)
	{
		player.richEnding();
	}

	int choice;
	std::cout << "※ 마을 ※" << std::endl;

	std::cout << "1. 상점" << std::endl << "2. 여관" << std::endl << "3. 광산" << std::endl << "4. 인벤토리" << std::endl << std::endl;

	std::cin >> choice;

	std::cout << std::endl;

	if (choice == 1 || choice == 2 || choice == 3)
	{
		player.Move();
	}

	if (choice == 1) // 상점
	{
		std::cout << std::endl << "System : 상점으로 갑니다." << std::endl;
		Sleep(2000);
		system("cls");

		Stage1::showShopMenu();
	}
	else if (choice == 2) // 여관
	{
		std::cout << std::endl << "System : 여관으로 갑니다." << std::endl;
		Sleep(2000);
		system("cls");

		Stage1::showHotelMenu();
	}
	else if (choice == 3) // 광산
	{
		if (player.getHealth() <= 0)
		{
			std::cout << "플레이어 : 너무 힘들어.." << std::endl << std::endl;
			std::cout << "System : 체력이 낮아 광산에 갈 수 없습니다." << std::endl;

			Sleep(2000);
			system("cls");
		}
		else
		{
			std::cout << std::endl << "System : 광산으로 갑니다." << std::endl;
			Sleep(2000);
			system("cls");

			Stage1::showMineMenu();
		}
		
	}
	else if (choice == 4) // 인벤 열기 
	{
		std::cout << "System : 인벤토리를 엽니다." << std::endl;
		Sleep(1500);
		system("cls");

		Stage1::showInventoryMenu();
	}
	
	else if (std::cin.fail() || (choice != 1 && choice != 2 && choice !=3 && choice !=4))
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');

		std::cout << std::endl << "플레이어 : 아 잘못 봤어.." << std::endl << std::endl;
		std::cout << "System : 잘못된 입력입니다." << std::endl;

		Sleep(2000);
		system("cls");

		Stage1::selectActMenu();
	}
}

void Stage1::showShopMenu()
{
	int choice;

	int i = 0;
	while (true)
	{
		player.ShowInventory();

		if (i == 0)
		{
			gotoxy(0, 0);
			std::cout << "System : 상점에 입장했습니다." << std::endl << std::endl;
			//std::cout <<"어서와 << name!! << std::endl;
			std::cout << "상점 주인 : 오늘은 뭐가 필요해서 왔어?" << std::endl;

			std::cout << std::endl;

			gotoxy(0, 4);
		}
		else
		{
			gotoxy(0, 0);
			std::cout << "상점 주인 : 더 거래할게 있나?" << std::endl;
		}

		std::cout << "1. 구매" << std::endl << "2. 판매" << std::endl << "9. 나가기" << std::endl << std::endl;

		std::cin >> choice;

		/*if (std::cin.fail())
		{
			std::cout << "System : 잘못된 입력입니다." << std::endl;
			std::cin.clear();
			std::cin.ignore(1000, '\n');

			Sleep(1500);
			system("cls");

			Stage1::selectActMenu();
		}*/

		if (choice == 1)
		{
			std::cout << "1. 무기" << std::endl << "2. 방어구" << std::endl << "3. 아이템" << std::endl;

			std::cout << std::endl << "상점 주인 : 무엇을 구매할텐가?" << std::endl << std::endl;
			std::cin >> choice;

			if (choice == 1) // 무기 구매
			{
				shop.outputWeapon();
				std::cout << std::endl << "상점 주인 : 자 골라봐!" << std::endl << std::endl;
				std::cin >> choice;

				Weapon selectedWeapon;
				
				if(shop.selectWeapon(choice, selectedWeapon) == 1) // 무기 선택
				{
					if (player.BuyWeapon(selectedWeapon) == -1) // 돈 거래
					{
						std::cout << std::endl << "System : 소지금이 부족합니다. (무기 구매 실패)" << std::endl;
						Sleep(2000);
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

				else if (std::cin.fail() || (choice == 0 && choice > shop.getWeaponSize()))
				{
					std::cout << "상점 주인 : 어이 제대로 보고 골라!" << std::endl << std::endl;
					std::cout << "System : 잘못된 입력입니다." << std::endl;

					std::cin.clear();
					std::cin.ignore();

					Sleep(2000);
					system("cls");

					continue;
				}
			}
			else if (choice == 2)
			{
				shop.outputArmour();
				std::cout << std::endl << "상점 주인 : 자 골라봐!" << std::endl;

				std::cout << std::endl << std::endl;
				std::cin >> choice;

				Armour selectedArmour;

				if (shop.selectArmour(choice, selectedArmour) == 1) // 방어구 선택
				{
					if (player.BuyArmour(selectedArmour) == -1) // 돈 거래
					{
						std::cout << std::endl << "System : 소지금이 부족합니다. (방어구 구매 실패)" << std::endl;
						Sleep(2000);
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
				else if (std::cin.fail() || (choice == 0 && choice > shop.getArmourSize()))
				{
					std::cout << "상점 주인 : 어이 제대로 보고 골라!" << std::endl << std::endl;
					std::cout << "System : 잘못된 입력입니다." << std::endl;

					std::cin.clear();
					std::cin.ignore();

					Sleep(2000);
					system("cls");

					continue;
				}
			}
			else if (choice == 3) // 아이템 구매
			{
				shop.outputMaterial();
				std::cout << std::endl << "상점 주인 : 자 골라봐!" << std::endl;

				std::cout << std::endl << std::endl;
				std::cin >> choice;

				Material selectedMaterial;

				if (shop.selectMaterial(choice, selectedMaterial) == 1) // 무기 선택
				{
					if (player.BuyMaterial(selectedMaterial) == 0) // 돈 거래
					{
						std::cout << std::endl << "System : 소지금이 부족합니다. (아이템 구매 실패)" << std::endl;
						Sleep(2000);
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
				else if (std::cin.fail() || (choice == 0 && choice > shop.getMaterialSize()))
				{
					std::cout << "상점 주인 : 어이 제대로 보고 골라!" << std::endl << std::endl;
					std::cout << "System : 잘못된 입력입니다." << std::endl;

					std::cin.clear();
					std::cin.ignore();

					Sleep(2000);
					system("cls");

					continue;
				}
			}
			else if (std::cin.fail() || (choice != 1 && choice != 2 && choice != 3))
			{
				std::cout << "상점 주인 : 어이! 있는 것 중에 골라야지!!" << std::endl;
				std::cout << std::endl << "System : 잘못된 입력입니다." << std::endl;

				std::cin.clear();
				std::cin.ignore();

				Sleep(2000);
				system("cls");

				continue;
			}
		}
		else if (choice == 2) // 플레이어가 상인에게 판매 
		{
			std::cout << "1. 무기" << std::endl << "2. 방어구" << std::endl << "3. 광물" << std::endl;

			std::cout << std::endl << std::endl << "상점 주인 : 무엇을 팔건가?" << std::endl << std::endl;
			std::cin >> choice;

			if (choice == 1) // 플레이어가 상인에게 무기 팔기 
			{

				if (player.getInventory().getWeaponSize() == 0)
				{
					std::cout << "상점 주인 : 가지고 있는 무기도 없잖아!" << std::endl;
					std::cout << std::endl << "System : 가지고 있는 무기가 없습니다. (무기 판매 실패)" << std::endl << std::endl;

					Sleep(2000);
					system("cls");
				}
				else
				{
					std::cout << std::endl << "상점 주인 : 어떤 무기를 팔텐가?" << std::endl << std::endl;
					std::cin >> choice;

					if (choice == 1)
					{
						std::cout << std::endl << "플레이어 : 이건 내가 쓰고 있는 거야!" << std::endl;

						Sleep(2000);
						system("cls");
					}
					else if (choice > 0 && choice <= player.getInventory().getWeaponSize())
					{
						Weapon selectedWeapon = player.getInventory().sellSelectWeapon(choice);
						player.setPrice(player.getPrice() + selectedWeapon.getPrice() / 2);
						shop.addWeapon(selectedWeapon);

						Sleep(3000);
						system("cls");
					}

					else if (std::cin.fail() || (choice == 0 && choice > player.getInventory().getWeaponSize()))
					{
						std::cout << std::endl << "상점 주인 : 판매할 무기를 제대로 말해줘야지!" << std::endl << std::endl;
						std::cout << "System : 잘못된 입력입니다." << std::endl;

						std::cin.clear();
						std::cin.ignore();

						Sleep(2000);
						system("cls");

						continue;
					}
				}
			}
			else if (choice == 2) // 플레이어가 상인에게 방어구 팔기
			{
				if (player.getInventory().getArmourSize() == 0)
				{
					std::cout << "상점 주인 : 가지고 있는 방어구도 없잖아!" << std::endl;
					std::cout << std::endl << "System : 가지고 있는 방어구가 없습니다. (방어구 판매 실패)" << std::endl;

					Sleep(2000);
					system("cls");
				}

				else
				{
					std::cout << std::endl;;
					std::cout << std::endl << "상점 주인 : 어떤 방어구를 팔텐가?" << std::endl << std::endl;
					std::cin >> choice;

					if (choice == 1 || choice == 2 || choice == 3)
					{
						std::cout << "플레이어 : 이건 내가 입고 있는 거야!" << std::endl;

						Sleep(2000);
						system("cls");
					}
					else if (choice > 0 && choice <= player.getInventory().getArmourSize())
					{
						Armour selectedArmour = player.getInventory().sellSelectArmour(choice);
						player.setPrice(player.getPrice() + selectedArmour.getPrice() / 2);
						shop.addArmour(selectedArmour);

						Sleep(3000);
						system("cls");
					}
					else if (std::cin.fail() || (choice == 0 && choice > player.getInventory().getArmourSize()))
					{
						std::cout << std::endl << "상점 주인 : 판매할 방어구를 제대로 말해줘야지!" << std::endl << std::endl;
						std::cout << "System : 잘못된 입력입니다." << std::endl;

						std::cin.clear();
						std::cin.ignore();

						Sleep(2000);
						system("cls");

						continue;
					}
				}
			}

			else if (choice == 3) // 플레이어가 상인에게 광물 판매
			{
				if (player.getInventory().getMineralSize() == 0)
				{
					std::cout << "상점 주인 : 가지고 있는 광물도 없잖아!" << std::endl;
					std::cout << std::endl << "System : 가지고 있는 광물이 없습니다.. (광물 판매 실패)" << std::endl;

					Sleep(2000);
					system("cls");
				}
				else
				{
					std::cout << std::endl;
					std::cout << "상점 주인 : 좋은 광물 좀 가져왔나?" << std::endl << std::endl;
					std::cin >> choice;

					if (std::cin.fail())
					{
						std::cout << "System : 잘못된 입력입니다." << std::endl;
						std::cin.clear();
						std::cin.ignore();

						Sleep(2000);
						system("cls");

						continue;
					}

					if (choice > 0 && choice <= player.getInventory().getMineralSize())
					{
						Mineral selectedMineral = player.getInventory().sellSelectMineral(choice);
						player.setPrice(player.getPrice() + selectedMineral.getPrice());

						Sleep(3000);
						system("cls");
					}
					else if (std::cin.fail() || (choice == 0 && choice > player.getInventory().getMaterialSize()))
					{
						std::cout << std::endl << "상점 주인 : 판매할 광물을 제대로 말해줘야지!" << std::endl << std::endl;
						std::cout << "System : 잘못된 입력입니다." << std::endl;

						std::cin.clear();
						std::cin.ignore();

						Sleep(2000);
						system("cls");

						continue;
					}
				}
			}
			else if (std::cin.fail() || (choice != 1 && choice != 2 && choice !=3))
			{
				std::cout << "상점 주인 : 뭘 팔겠다는거야?!" << std::endl << std::endl;
				std::cout << "System : 잘못된 입력입니다." << std::endl;

				std::cin.clear();
				std::cin.ignore();

				Sleep(2000);
				system("cls");

				continue;
			}
		}
		else if (choice == 9) // 상점에서 나가기 
		{
			std::cin.clear();
			//std::cin.ignore();

			std::cout << "상점 주인 : 나중에 또 오게" << std::endl << std::endl;

			player.Move();

			std::cout << std::endl << "System : 상점에서 나갔습니다." << std::endl;

			Sleep(2000);
			system("cls");
			break;
		}

		else if (std::cin.fail() || (choice != 1 && choice !=2 && choice !=3 && choice != 9))
		{
			std::cout << std::endl << "System : 잘못된 입력입니다." << std::endl;

			std::cin.clear();
			std::cin.ignore(1000, '\n');

			Sleep(2000);
			system("cls");

			continue;
		}
		i++;
	}
}

void Stage1::showInventoryMenu()
{
	int choice;

	while (true)
	{

		player.ShowInventory();
		player.showStats();

		gotoxy(0, 0);
		std::cout << "1. 무기" << std::endl << "2. 방어구 (최대 체력에서 장착 시 최대 체력이 저장됩니다.)"  << std::endl << "9. 인벤토리 닫기" << std::endl;

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


				if (choice > 0 && choice <= player.getInventory().getWeaponSize())
				{
					Weapon selectedWeapon = player.getInventory().selectWeapon(choice);
					player.MountedWeapon(selectedWeapon);

					std::cout << "System : 무기를 장착했습니다" << std::endl;


					Sleep(2000);
					system("cls");
				}
				else if (std::cin.fail() || (choice > player.getInventory().getWeaponSize()))
				{
					std::cout << std::endl << "System : 잘못된 입력입니다." << std::endl;
					std::cin.clear();
					std::cin.ignore();

					Sleep(2000);
					system("cls");

					Stage1::showInventoryMenu();
				}
		
			}
			else if (choice == 2) // 무기 장착 해제 
			{
				player.UnequipWeapon();

				Sleep(2000);
				system("cls");
			}
			else if (std::cin.fail() || (choice != 1 && choice != 2))
			{
				std::cout << std::endl << "System : 잘못된 입력입니다." << std::endl;
				std::cin.clear();
				std::cin.ignore();

				Sleep(2000);
				system("cls");

				Stage1::showInventoryMenu();
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

				if (choice > 0 && choice <= player.getInventory().getArmourSize())
				{
					Armour selectedArmour = player.getInventory().selectArmour(choice);
					player.MountedArmour(choice);

					std::cout << "System : 방어구를 장착했습니다." << std::endl;

					Sleep(2000);
					system("cls");
					continue;
				}
				else if (std::cin.fail() || (choice > player.getInventory().getArmourSize()))
				{
					std::cout << std::endl << "System : 잘못된 입력입니다." << std::endl;
					std::cin.clear();
					std::cin.ignore();

					Sleep(2000);
					system("cls");

					Stage1::showInventoryMenu();
				}
			}
			else if (choice == 2) // 방어구 장착 해제
			{
				std::cout << std::endl;
				std::cin >> choice;

				if (choice > 0 && choice <= player.getInventory().getArmourSize())
				{
					Armour selectedArmour = player.getInventory().selectArmour(choice);
					player.UnequipArmour(choice);

					Sleep(2000);
					system("cls");
				}
				else if (std::cin.fail() || (choice > player.getInventory().getArmourSize()))
				{
					std::cout << std::endl << "System : 잘못된 입력입니다." << std::endl;
					std::cin.clear();
					std::cin.ignore();

					Sleep(2000);
					system("cls");

					Stage1::showInventoryMenu();
				}
			}
			else if (std::cin.fail() || (choice != 1 && choice != 2))
			{
				std::cout << std::endl << "System : 잘못된 입력입니다." << std::endl;
				std::cin.clear();
				std::cin.ignore();

				Sleep(2000);
				system("cls");

				Stage1::showInventoryMenu();
			}
		}
		else if (choice == 9)
		{
			std::cout << std::endl << "System : 인벤토리를 닫았습니다." << std::endl;

			Sleep(2000);
			system("cls");
			break;
		}
		else if (std::cin.fail() || (choice != 1 && choice != 2 ))
		{
			std::cout << std::endl << "System : 잘못된 입력입니다." << std::endl;
			std::cin.clear();
			std::cin.ignore();

			Sleep(2000);
			system("cls");

			Stage1::showInventoryMenu();
		}
	}
}

void Stage1::showHotelMenu()
{
	if (hotel.getFriendShip() >= 100)
	{
		hotel.marriageEnding();
	}

	int choice;


	int talkCount = 0;
	int guessCount = 0;
	int i = 0;
	while (true)
	{
		hotel.getFood().clear();
		hotel.addFood();
		player.ShowInventory();
		player.showStats();

		if (i == 0)
		{
			gotoxy(0, 0);
			std::cout << "System : 여관에 입장했습니다." << std::endl << std::endl;
			//std::cout <<"어서와 << name!! << std::endl;
			std::cout << "여관 주인 : 오늘은 뭐 하러 왔어?" << std::endl << std::endl;
			gotoxy(0, 4);
		}

		if (i >= 1)
		{
			gotoxy(0, 0);
			std::cout << "여관 주인 : 더 원하는 게 있나?" << std::endl << std::endl;
		}

		std::cout << "1. 잠자기" << std::endl << "2. 구매" << std::endl << "3. 말하기" << std::endl << "4. 선물주기" << std::endl << "5. 음식 맞추기" << std::endl << "9. 나가기" << std::endl << std::endl;

		std::cin >> choice;
		std::cout << std::endl;

		if (choice == 1)
		{
			hotel.hotelSleep(player);
		}
		else if (choice == 2)
		{
			hotel.outputFood();

			std::cout << std::endl << "여관 주인 : 자 골라봐!" << std::endl << std::endl;
			std::cin >> choice;

			if (std::cin.fail() || (choice != 0 && choice > hotel.getFoodSize()))
			{
				std::cin.clear();
				std::cin.ignore(1000, '\n');

				std::cout << "여관 주인 : 메뉴에 없는 건 못 만들어줘" << std::endl << std::endl;
				std::cout << "System : 잘못된 입력입니다." << std::endl;

				Sleep(2000);
				system("cls");
				continue;
			}
			else
			{
				Food selectedFood = hotel.selectFood(choice); // 음식 선택
				// 상인이 음식 판매
				if (player.BuyFood(selectedFood) == 0) // 돈 거래
				{
					std::cout << std::endl << "System : 소지금이 부족합니다. (음식 구매 실패)" << std::endl;

					Sleep(2000);
					system("cls");
				}
				else
				{
					if (choice > 0 && choice <= hotel.getFoodSize())
					{
						hotel.sellFood(choice); // 돈 거래

						int newHealth = player.getHealth() + selectedFood.getHealth(); // 음식 버프
						player.setHealth(newHealth);

						Sleep(3000);
						system("cls");
					}
				}
			}
		}
		else if (choice == 3) // 말걸기 
		{
			if (talkCount == 1)
			{
				std::cout << "여관 주인 딸 : 나 이제 바빠 나중에 또 얘기하자!" << std::endl;

				Sleep(2000);
				system("cls");
			}
			else
			{
				std::cout << std::endl;
				hotel.Talk();

				talkCount++;
			}
		}
		else if (choice == 4) // 선물주기
		{

			std::cin >> choice;

			if (std::cin.fail() || (choice==0 && choice > player.getInventory().getMaterialSize()))
			{
				std::cout << std::endl << "System : 잘못된 입력입니다." << std::endl;
				std::cin.clear();
				std::cin.ignore();

				Sleep(2000);
				system("cls");

				continue;
			}
			else
			{
				hotel.Gift(choice, player);
			}

		}
		else if (choice == 5) // 음식 맞추기
		{
			if (guessCount == 1)
			{
				std::cout << "여관 주인 : 오늘은 이미 했잖아" << std::endl;
			}
			else
			{
				hotel.guessFood(player);
				guessCount++;
			}
		}
		else if (choice == 9) // 나가기
		{
			std::cout << "여관 주인 : 오늘도 좋은 하루 보내" << std::endl << std::endl;

			player.Move();

			std::cout << std::endl;
			std::cout << "System : 여관을 나갔습니다." << std::endl;

			Sleep(2000);
			system("cls");
			break;
		}
		else if (std::cin.fail() || (choice != 1 && choice != 2 && choice !=3 && choice != 4 && choice !=9))
		{
			std::cout << std::endl << "System : 잘못된 입력입니다." << std::endl;
			std::cin.clear();
			std::cin.ignore();

			Sleep(2000);
			system("cls");

			continue;
		}

		i++;
	}


}

void Stage1::showMineMenu()
{
	char input;

	gotoxy(0, 0);
	std::cout << "System : 광산에 입장했습니다." << std::endl << std::endl;

	std::cout << "1. 석탄 광산" << std::endl << "2. 철 광산 (최대 체력 120일 경우 입장 가능)" << std::endl << "3. 금 광산 (최대 체력 140일 경우 입장 가능)" << std::endl << "4. 다이아몬드 광산 (최대 체력 160일 경우 입장 가능)" << std::endl << std::endl;

	int choice;
	std::cin >> choice;

	std::cout << std::endl;
	
	
	if (choice == 1) // 석탄
	{
		player.Move();
		Sleep(2000);
		system("cls");

		coalMine.setPlayer(&player);

		coalMine.resetGrid();
		coalMine.initializeMine();

		gotoxy(0, 0);
		std::cout << "System : 석탄 광산에 입장했습니다." << std::endl;

		coalMine.Mining();
	}
	else if (choice == 2) // 철
	{
		ironMine.setPlayer(&player);

		if (player.getMaxHealth() >= 120)
		{
			player.Move();
			Sleep(2000);
			system("cls");

			ironMine.resetGrid();
			ironMine.initializeMine();

			gotoxy(0, 0);
			std::cout << "System : 철 광산에 입장했습니다." << std::endl;

			ironMine.Mining();
		}
		else
		{
			std::cout << "플레이어 : 난 아직 여길 들어갈 수 없어.." << std::endl << std::endl;
			std::cout << "System : 플레이어의 최대 체력이 아직 모자랍니다." << std::endl;


			Sleep(2000);
			system("cls");
			showMineMenu();
		}

	}
	else if (choice == 3) // 금 광산
	{
		goldMine.setPlayer(&player);

		if (player.getMaxHealth() >= 140)
		{
			player.Move();
			Sleep(2000);
			system("cls");

			goldMine.resetGrid();
			goldMine.initializeMine();

			gotoxy(0, 0);
			std::cout << "System : 금 광산에 입장했습니다." << std::endl;

			goldMine.Mining();
		}
		else
		{
			std::cout << "플레이어 : 난 아직 여길 들어갈 수 없어.." << std::endl << std::endl;
			std::cout << "System : 플레이어의 최대 체력이 아직 모자랍니다." << std::endl;


			Sleep(2000);
			system("cls");
			showMineMenu();
		}
	}
	else if (choice == 4) // 다이아몬드 광산
	{
		diamondMine.setPlayer(&player);

		if (player.getMaxHealth() >= 160)
		{
			player.Move();
			Sleep(2000);
			system("cls");

			diamondMine.resetGrid();
			diamondMine.initializeMine();

			gotoxy(0, 0);
			std::cout << "System : 다이아몬드 광산에 입장했습니다." << std::endl;

			diamondMine.Mining();
		}
		else
		{
			std::cout << "플레이어 : 난 아직 여길 들어갈 수 없어.." << std::endl << std::endl;
			std::cout << "System : 플레이어의 최대 체력이 아직 모자랍니다." << std::endl;


			Sleep(2000);
			system("cls");
			showMineMenu();
		}
	}
	else if (choice == 9)
	{

		std::cout << "System : 광산에서 나갔습니다." << std::endl;

		Sleep(2000);
		system("cls");
		selectActMenu();
	}

	else if (std::cin.fail() || (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 9))
	{
		std::cout << std::endl << "System : 잘못된 입력입니다." << std::endl;
		
		std::cin.clear();
		std::cin.ignore();
		Sleep(2000);
		system("cls");

		Stage1::showMineMenu();
	}
}
