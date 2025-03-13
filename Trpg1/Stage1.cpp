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
	std::cout << "�� ���� ��" << std::endl;

	std::cout << "1. ����" << std::endl << "2. ����" << std::endl << "3. ����" << std::endl << "4. �κ��丮" << std::endl << std::endl;

	std::cin >> choice;

	std::cout << std::endl;

	if (choice == 1 || choice == 2 || choice == 3)
	{
		player.Move();
	}

	if (choice == 1) // ����
	{
		std::cout << std::endl << "System : �������� ���ϴ�." << std::endl;
		Sleep(2000);
		system("cls");

		Stage1::showShopMenu();
	}
	else if (choice == 2) // ����
	{
		std::cout << std::endl << "System : �������� ���ϴ�." << std::endl;
		Sleep(2000);
		system("cls");

		Stage1::showHotelMenu();
	}
	else if (choice == 3) // ����
	{
		if (player.getHealth() <= 0)
		{
			std::cout << "�÷��̾� : �ʹ� �����.." << std::endl << std::endl;
			std::cout << "System : ü���� ���� ���꿡 �� �� �����ϴ�." << std::endl;

			Sleep(2000);
			system("cls");
		}
		else
		{
			std::cout << std::endl << "System : �������� ���ϴ�." << std::endl;
			Sleep(2000);
			system("cls");

			Stage1::showMineMenu();
		}
		
	}
	else if (choice == 4) // �κ� ���� 
	{
		std::cout << "System : �κ��丮�� ���ϴ�." << std::endl;
		Sleep(1500);
		system("cls");

		Stage1::showInventoryMenu();
	}
	
	else if (std::cin.fail() || (choice != 1 && choice != 2 && choice !=3 && choice !=4))
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');

		std::cout << std::endl << "�÷��̾� : �� �߸� �þ�.." << std::endl << std::endl;
		std::cout << "System : �߸��� �Է��Դϴ�." << std::endl;

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
			std::cout << "System : ������ �����߽��ϴ�." << std::endl << std::endl;
			//std::cout <<"��� << name!! << std::endl;
			std::cout << "���� ���� : ������ ���� �ʿ��ؼ� �Ծ�?" << std::endl;

			std::cout << std::endl;

			gotoxy(0, 4);
		}
		else
		{
			gotoxy(0, 0);
			std::cout << "���� ���� : �� �ŷ��Ұ� �ֳ�?" << std::endl;
		}

		std::cout << "1. ����" << std::endl << "2. �Ǹ�" << std::endl << "9. ������" << std::endl << std::endl;

		std::cin >> choice;

		/*if (std::cin.fail())
		{
			std::cout << "System : �߸��� �Է��Դϴ�." << std::endl;
			std::cin.clear();
			std::cin.ignore(1000, '\n');

			Sleep(1500);
			system("cls");

			Stage1::selectActMenu();
		}*/

		if (choice == 1)
		{
			std::cout << "1. ����" << std::endl << "2. ��" << std::endl << "3. ������" << std::endl;

			std::cout << std::endl << "���� ���� : ������ �������ٰ�?" << std::endl << std::endl;
			std::cin >> choice;

			if (choice == 1) // ���� ����
			{
				shop.outputWeapon();
				std::cout << std::endl << "���� ���� : �� ����!" << std::endl << std::endl;
				std::cin >> choice;

				Weapon selectedWeapon;
				
				if(shop.selectWeapon(choice, selectedWeapon) == 1) // ���� ����
				{
					if (player.BuyWeapon(selectedWeapon) == -1) // �� �ŷ�
					{
						std::cout << std::endl << "System : �������� �����մϴ�. (���� ���� ����)" << std::endl;
						Sleep(2000);
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

				else if (std::cin.fail() || (choice == 0 && choice > shop.getWeaponSize()))
				{
					std::cout << "���� ���� : ���� ����� ���� ���!" << std::endl << std::endl;
					std::cout << "System : �߸��� �Է��Դϴ�." << std::endl;

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
				std::cout << std::endl << "���� ���� : �� ����!" << std::endl;

				std::cout << std::endl << std::endl;
				std::cin >> choice;

				Armour selectedArmour;

				if (shop.selectArmour(choice, selectedArmour) == 1) // �� ����
				{
					if (player.BuyArmour(selectedArmour) == -1) // �� �ŷ�
					{
						std::cout << std::endl << "System : �������� �����մϴ�. (�� ���� ����)" << std::endl;
						Sleep(2000);
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
				else if (std::cin.fail() || (choice == 0 && choice > shop.getArmourSize()))
				{
					std::cout << "���� ���� : ���� ����� ���� ���!" << std::endl << std::endl;
					std::cout << "System : �߸��� �Է��Դϴ�." << std::endl;

					std::cin.clear();
					std::cin.ignore();

					Sleep(2000);
					system("cls");

					continue;
				}
			}
			else if (choice == 3) // ������ ����
			{
				shop.outputMaterial();
				std::cout << std::endl << "���� ���� : �� ����!" << std::endl;

				std::cout << std::endl << std::endl;
				std::cin >> choice;

				Material selectedMaterial;

				if (shop.selectMaterial(choice, selectedMaterial) == 1) // ���� ����
				{
					if (player.BuyMaterial(selectedMaterial) == 0) // �� �ŷ�
					{
						std::cout << std::endl << "System : �������� �����մϴ�. (������ ���� ����)" << std::endl;
						Sleep(2000);
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
				else if (std::cin.fail() || (choice == 0 && choice > shop.getMaterialSize()))
				{
					std::cout << "���� ���� : ���� ����� ���� ���!" << std::endl << std::endl;
					std::cout << "System : �߸��� �Է��Դϴ�." << std::endl;

					std::cin.clear();
					std::cin.ignore();

					Sleep(2000);
					system("cls");

					continue;
				}
			}
			else if (std::cin.fail() || (choice != 1 && choice != 2 && choice != 3))
			{
				std::cout << "���� ���� : ����! �ִ� �� �߿� ������!!" << std::endl;
				std::cout << std::endl << "System : �߸��� �Է��Դϴ�." << std::endl;

				std::cin.clear();
				std::cin.ignore();

				Sleep(2000);
				system("cls");

				continue;
			}
		}
		else if (choice == 2) // �÷��̾ ���ο��� �Ǹ� 
		{
			std::cout << "1. ����" << std::endl << "2. ��" << std::endl << "3. ����" << std::endl;

			std::cout << std::endl << std::endl << "���� ���� : ������ �Ȱǰ�?" << std::endl << std::endl;
			std::cin >> choice;

			if (choice == 1) // �÷��̾ ���ο��� ���� �ȱ� 
			{

				if (player.getInventory().getWeaponSize() == 0)
				{
					std::cout << "���� ���� : ������ �ִ� ���⵵ ���ݾ�!" << std::endl;
					std::cout << std::endl << "System : ������ �ִ� ���Ⱑ �����ϴ�. (���� �Ǹ� ����)" << std::endl << std::endl;

					Sleep(2000);
					system("cls");
				}
				else
				{
					std::cout << std::endl << "���� ���� : � ���⸦ ���ٰ�?" << std::endl << std::endl;
					std::cin >> choice;

					if (choice == 1)
					{
						std::cout << std::endl << "�÷��̾� : �̰� ���� ���� �ִ� �ž�!" << std::endl;

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
						std::cout << std::endl << "���� ���� : �Ǹ��� ���⸦ ����� ���������!" << std::endl << std::endl;
						std::cout << "System : �߸��� �Է��Դϴ�." << std::endl;

						std::cin.clear();
						std::cin.ignore();

						Sleep(2000);
						system("cls");

						continue;
					}
				}
			}
			else if (choice == 2) // �÷��̾ ���ο��� �� �ȱ�
			{
				if (player.getInventory().getArmourSize() == 0)
				{
					std::cout << "���� ���� : ������ �ִ� ���� ���ݾ�!" << std::endl;
					std::cout << std::endl << "System : ������ �ִ� ���� �����ϴ�. (�� �Ǹ� ����)" << std::endl;

					Sleep(2000);
					system("cls");
				}

				else
				{
					std::cout << std::endl;;
					std::cout << std::endl << "���� ���� : � ���� ���ٰ�?" << std::endl << std::endl;
					std::cin >> choice;

					if (choice == 1 || choice == 2 || choice == 3)
					{
						std::cout << "�÷��̾� : �̰� ���� �԰� �ִ� �ž�!" << std::endl;

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
						std::cout << std::endl << "���� ���� : �Ǹ��� ���� ����� ���������!" << std::endl << std::endl;
						std::cout << "System : �߸��� �Է��Դϴ�." << std::endl;

						std::cin.clear();
						std::cin.ignore();

						Sleep(2000);
						system("cls");

						continue;
					}
				}
			}

			else if (choice == 3) // �÷��̾ ���ο��� ���� �Ǹ�
			{
				if (player.getInventory().getMineralSize() == 0)
				{
					std::cout << "���� ���� : ������ �ִ� ������ ���ݾ�!" << std::endl;
					std::cout << std::endl << "System : ������ �ִ� ������ �����ϴ�.. (���� �Ǹ� ����)" << std::endl;

					Sleep(2000);
					system("cls");
				}
				else
				{
					std::cout << std::endl;
					std::cout << "���� ���� : ���� ���� �� �����Գ�?" << std::endl << std::endl;
					std::cin >> choice;

					if (std::cin.fail())
					{
						std::cout << "System : �߸��� �Է��Դϴ�." << std::endl;
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
						std::cout << std::endl << "���� ���� : �Ǹ��� ������ ����� ���������!" << std::endl << std::endl;
						std::cout << "System : �߸��� �Է��Դϴ�." << std::endl;

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
				std::cout << "���� ���� : �� �Ȱڴٴ°ž�?!" << std::endl << std::endl;
				std::cout << "System : �߸��� �Է��Դϴ�." << std::endl;

				std::cin.clear();
				std::cin.ignore();

				Sleep(2000);
				system("cls");

				continue;
			}
		}
		else if (choice == 9) // �������� ������ 
		{
			std::cin.clear();
			//std::cin.ignore();

			std::cout << "���� ���� : ���߿� �� ����" << std::endl << std::endl;

			player.Move();

			std::cout << std::endl << "System : �������� �������ϴ�." << std::endl;

			Sleep(2000);
			system("cls");
			break;
		}

		else if (std::cin.fail() || (choice != 1 && choice !=2 && choice !=3 && choice != 9))
		{
			std::cout << std::endl << "System : �߸��� �Է��Դϴ�." << std::endl;

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
		std::cout << "1. ����" << std::endl << "2. �� (�ִ� ü�¿��� ���� �� �ִ� ü���� ����˴ϴ�.)"  << std::endl << "9. �κ��丮 �ݱ�" << std::endl;

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


				if (choice > 0 && choice <= player.getInventory().getWeaponSize())
				{
					Weapon selectedWeapon = player.getInventory().selectWeapon(choice);
					player.MountedWeapon(selectedWeapon);

					std::cout << "System : ���⸦ �����߽��ϴ�" << std::endl;


					Sleep(2000);
					system("cls");
				}
				else if (std::cin.fail() || (choice > player.getInventory().getWeaponSize()))
				{
					std::cout << std::endl << "System : �߸��� �Է��Դϴ�." << std::endl;
					std::cin.clear();
					std::cin.ignore();

					Sleep(2000);
					system("cls");

					Stage1::showInventoryMenu();
				}
		
			}
			else if (choice == 2) // ���� ���� ���� 
			{
				player.UnequipWeapon();

				Sleep(2000);
				system("cls");
			}
			else if (std::cin.fail() || (choice != 1 && choice != 2))
			{
				std::cout << std::endl << "System : �߸��� �Է��Դϴ�." << std::endl;
				std::cin.clear();
				std::cin.ignore();

				Sleep(2000);
				system("cls");

				Stage1::showInventoryMenu();
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

				if (choice > 0 && choice <= player.getInventory().getArmourSize())
				{
					Armour selectedArmour = player.getInventory().selectArmour(choice);
					player.MountedArmour(choice);

					std::cout << "System : ���� �����߽��ϴ�." << std::endl;

					Sleep(2000);
					system("cls");
					continue;
				}
				else if (std::cin.fail() || (choice > player.getInventory().getArmourSize()))
				{
					std::cout << std::endl << "System : �߸��� �Է��Դϴ�." << std::endl;
					std::cin.clear();
					std::cin.ignore();

					Sleep(2000);
					system("cls");

					Stage1::showInventoryMenu();
				}
			}
			else if (choice == 2) // �� ���� ����
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
					std::cout << std::endl << "System : �߸��� �Է��Դϴ�." << std::endl;
					std::cin.clear();
					std::cin.ignore();

					Sleep(2000);
					system("cls");

					Stage1::showInventoryMenu();
				}
			}
			else if (std::cin.fail() || (choice != 1 && choice != 2))
			{
				std::cout << std::endl << "System : �߸��� �Է��Դϴ�." << std::endl;
				std::cin.clear();
				std::cin.ignore();

				Sleep(2000);
				system("cls");

				Stage1::showInventoryMenu();
			}
		}
		else if (choice == 9)
		{
			std::cout << std::endl << "System : �κ��丮�� �ݾҽ��ϴ�." << std::endl;

			Sleep(2000);
			system("cls");
			break;
		}
		else if (std::cin.fail() || (choice != 1 && choice != 2 ))
		{
			std::cout << std::endl << "System : �߸��� �Է��Դϴ�." << std::endl;
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
			std::cout << "System : ������ �����߽��ϴ�." << std::endl << std::endl;
			//std::cout <<"��� << name!! << std::endl;
			std::cout << "���� ���� : ������ �� �Ϸ� �Ծ�?" << std::endl << std::endl;
			gotoxy(0, 4);
		}

		if (i >= 1)
		{
			gotoxy(0, 0);
			std::cout << "���� ���� : �� ���ϴ� �� �ֳ�?" << std::endl << std::endl;
		}

		std::cout << "1. ���ڱ�" << std::endl << "2. ����" << std::endl << "3. ���ϱ�" << std::endl << "4. �����ֱ�" << std::endl << "5. ���� ���߱�" << std::endl << "9. ������" << std::endl << std::endl;

		std::cin >> choice;
		std::cout << std::endl;

		if (choice == 1)
		{
			hotel.hotelSleep(player);
		}
		else if (choice == 2)
		{
			hotel.outputFood();

			std::cout << std::endl << "���� ���� : �� ����!" << std::endl << std::endl;
			std::cin >> choice;

			if (std::cin.fail() || (choice != 0 && choice > hotel.getFoodSize()))
			{
				std::cin.clear();
				std::cin.ignore(1000, '\n');

				std::cout << "���� ���� : �޴��� ���� �� �� �������" << std::endl << std::endl;
				std::cout << "System : �߸��� �Է��Դϴ�." << std::endl;

				Sleep(2000);
				system("cls");
				continue;
			}
			else
			{
				Food selectedFood = hotel.selectFood(choice); // ���� ����
				// ������ ���� �Ǹ�
				if (player.BuyFood(selectedFood) == 0) // �� �ŷ�
				{
					std::cout << std::endl << "System : �������� �����մϴ�. (���� ���� ����)" << std::endl;

					Sleep(2000);
					system("cls");
				}
				else
				{
					if (choice > 0 && choice <= hotel.getFoodSize())
					{
						hotel.sellFood(choice); // �� �ŷ�

						int newHealth = player.getHealth() + selectedFood.getHealth(); // ���� ����
						player.setHealth(newHealth);

						Sleep(3000);
						system("cls");
					}
				}
			}
		}
		else if (choice == 3) // ���ɱ� 
		{
			if (talkCount == 1)
			{
				std::cout << "���� ���� �� : �� ���� �ٺ� ���߿� �� �������!" << std::endl;

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
		else if (choice == 4) // �����ֱ�
		{

			std::cin >> choice;

			if (std::cin.fail() || (choice==0 && choice > player.getInventory().getMaterialSize()))
			{
				std::cout << std::endl << "System : �߸��� �Է��Դϴ�." << std::endl;
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
		else if (choice == 5) // ���� ���߱�
		{
			if (guessCount == 1)
			{
				std::cout << "���� ���� : ������ �̹� ���ݾ�" << std::endl;
			}
			else
			{
				hotel.guessFood(player);
				guessCount++;
			}
		}
		else if (choice == 9) // ������
		{
			std::cout << "���� ���� : ���õ� ���� �Ϸ� ����" << std::endl << std::endl;

			player.Move();

			std::cout << std::endl;
			std::cout << "System : ������ �������ϴ�." << std::endl;

			Sleep(2000);
			system("cls");
			break;
		}
		else if (std::cin.fail() || (choice != 1 && choice != 2 && choice !=3 && choice != 4 && choice !=9))
		{
			std::cout << std::endl << "System : �߸��� �Է��Դϴ�." << std::endl;
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
	std::cout << "System : ���꿡 �����߽��ϴ�." << std::endl << std::endl;

	std::cout << "1. ��ź ����" << std::endl << "2. ö ���� (�ִ� ü�� 120�� ��� ���� ����)" << std::endl << "3. �� ���� (�ִ� ü�� 140�� ��� ���� ����)" << std::endl << "4. ���̾Ƹ�� ���� (�ִ� ü�� 160�� ��� ���� ����)" << std::endl << std::endl;

	int choice;
	std::cin >> choice;

	std::cout << std::endl;
	
	
	if (choice == 1) // ��ź
	{
		player.Move();
		Sleep(2000);
		system("cls");

		coalMine.setPlayer(&player);

		coalMine.resetGrid();
		coalMine.initializeMine();

		gotoxy(0, 0);
		std::cout << "System : ��ź ���꿡 �����߽��ϴ�." << std::endl;

		coalMine.Mining();
	}
	else if (choice == 2) // ö
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
			std::cout << "System : ö ���꿡 �����߽��ϴ�." << std::endl;

			ironMine.Mining();
		}
		else
		{
			std::cout << "�÷��̾� : �� ���� ���� �� �� ����.." << std::endl << std::endl;
			std::cout << "System : �÷��̾��� �ִ� ü���� ���� ���ڶ��ϴ�." << std::endl;


			Sleep(2000);
			system("cls");
			showMineMenu();
		}

	}
	else if (choice == 3) // �� ����
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
			std::cout << "System : �� ���꿡 �����߽��ϴ�." << std::endl;

			goldMine.Mining();
		}
		else
		{
			std::cout << "�÷��̾� : �� ���� ���� �� �� ����.." << std::endl << std::endl;
			std::cout << "System : �÷��̾��� �ִ� ü���� ���� ���ڶ��ϴ�." << std::endl;


			Sleep(2000);
			system("cls");
			showMineMenu();
		}
	}
	else if (choice == 4) // ���̾Ƹ�� ����
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
			std::cout << "System : ���̾Ƹ�� ���꿡 �����߽��ϴ�." << std::endl;

			diamondMine.Mining();
		}
		else
		{
			std::cout << "�÷��̾� : �� ���� ���� �� �� ����.." << std::endl << std::endl;
			std::cout << "System : �÷��̾��� �ִ� ü���� ���� ���ڶ��ϴ�." << std::endl;


			Sleep(2000);
			system("cls");
			showMineMenu();
		}
	}
	else if (choice == 9)
	{

		std::cout << "System : ���꿡�� �������ϴ�." << std::endl;

		Sleep(2000);
		system("cls");
		selectActMenu();
	}

	else if (std::cin.fail() || (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 9))
	{
		std::cout << std::endl << "System : �߸��� �Է��Դϴ�." << std::endl;
		
		std::cin.clear();
		std::cin.ignore();
		Sleep(2000);
		system("cls");

		Stage1::showMineMenu();
	}
}
