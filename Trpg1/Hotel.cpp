#include "Hotel.h"

void Hotel::addFood()
{
	food.push_back(Food("������", 0, 20, "�̽��� ��ġ�� �� ���", 10));
	food.push_back(Food("��ġ���", 0, 20, "�̽��� ��ġ�� �� ���", 10));
	food.push_back(Food("�����", 0, 20, "���޸����� �����", 10));
	food.push_back(Food("�����", 0, 50, "ĮĮ�� �����", 30));
	food.push_back(Food("����", 0, 70, "���� ������ ������ ���� ����", 40));
	food.push_back(Food("���� �ʹ�", 0, 70, "��� �� ����", 40));
}

Food Hotel::sellFood(int choice)
{
	if (choice  < 1 || choice > getFoodSize())
	{
		std::cout << "���� ���� : �޴��� �� ������~" << std::endl;
		return Food();
	}

	int index = choice - 1;

	food.erase(food.begin() + index);
	std::cout << std::endl << "���� ���� : ���ְ� �Ծ�~" << std::endl << std::endl;
	std::cout << std::endl << "System : ������ �Ծ����ϴ�. (ü�� ���)" << std::endl;

	return food[index];
}

Food Hotel::selectFood(int choice)
{

	int index = choice - 1;

	std::cout << "���� ���� : " << food[index].getName() << "�� ���� �ž�??" << std::endl;
	std::cout << "���� ���� : " << food[index].getPrice() << "���̾�" << std::endl;
	return food[index];
}

std::vector<Food>& Hotel::getFood()
{
	return food;
}



void Hotel::hotelSleep(Player& player)
{
	// �������� (����, �Ǹ�, ������, �ູ�� �� ��) ?
	srand(time(NULL));
	int random = rand() % 4;

	switch (random)
	{
	case 0:
		std::cout << "System : ��մ� ���� �ٴ� �� �����ϴ�." << std::endl;
		break;
	case 1:
		std::cout << "System : �ູ�� ���� �ٴ� �� �����ϴ�." << std::endl;
		break;
	case 2:
		std::cout << "�÷��̾� : �帣��! ....." << std::endl << std::endl;
		std::cout << "System : ������ ������� �����׿�..." << std::endl;
		break;
	case 3:
		std::cout << "�÷��̾� : ����!!" << std::endl << std::endl;
		std::cout << "System : �Ǹ��� �ٴ� �� �����ϴ�." << std::endl;
		break;
	}

	player.setHealth(player.getMaxHealth());

	Sleep(2000);
	system("cls");
}

int Hotel::getFoodSize()
{
	return food.size();
}

void Hotel::Talk()
{
	srand(time(NULL));
	int random = rand() % 5;

	switch (random)
	{
	case 0:
		std::cout << "�÷��̾� : �ȳ� ���� �Ϸ� ���ϰ� ���¾�? " << std::endl;
		std::cout << "���� ���� �� : ���� �ٻ���.." << std::endl << std::endl;
		break;
	case 1:
		std::cout << "�÷��̾� : ���� ���� � ������ �߰��߳ĸ�! ......" << std::endl;
		std::cout << "���� ���� �� : ��! ���� �ű���!!" << std::endl << std::endl;
		break;
	case 2:
		std::cout << "�÷��̾� : ���õ��� �� �̻ڳ�?" << std::endl;
		std::cout << "���� ���� �� : ���.. ����?!" << std::endl << std::endl;
		break;
	case 3:
		std::cout << "�÷��̾� : ���� ĳ�ٰ� �������� ��Ⱦ�" << std::endl;
		std::cout << "���� ���� �� : ���! ����,, " << std::endl << std::endl;
		break;
	case 4:
		std::cout << "�÷��̾� : ���� �丮�� ���� �Ծ ���־�!" << std::endl;
		std::cout << "���� ���� �� : �� �� ���ְ� �Ծ��༭ ����" << std::endl << std::endl;
		break;
	}

	int friendShipLevel = rand() % 15+1; // ȣ���� ��·��� �ܺο��� ����

	std::cout << "System : ȣ������ " << friendShipLevel << "����߽��ϴ�." << std::endl;
	Hotel::setFriendShip(friendShipLevel); // ȣ���� ����
	std::cout << "System : ���� ȣ���� : " << Hotel::getFriendShip() << std::endl; // ���ŵ� ȣ���� ���

	Sleep(3000);
	system("cls");
}


void Hotel::Gift(int choice, Player& player)
{
	Inventory inventory = player.getInventory();

	std::vector<Material>& currentMaterials = inventory.getMaterial();

	if (choice >= 0 && choice <= currentMaterials.size())
	{
		Material selectedMaterial = currentMaterials[choice-1]; // ������ ���
		int friendShipLevel = rand() % selectedMaterial.getPrice() + 1;
		currentMaterials.erase(currentMaterials.begin() + choice-1);

		std::cout << "���� ���� �� : ���! ���� �̰�??" << std::endl << std::endl;

		std::cout << "System : ������ �־����ϴ�." << std::endl;


		std::cout << "System : ȣ������ " << friendShipLevel << "����߽��ϴ�." << std::endl;
		Hotel::setFriendShip(friendShipLevel); // ȣ���� ����
		std::cout << "System : ���� ȣ���� :  " << Hotel::getFriendShip() << std::endl;

		Sleep(2000);
		system("cls");
	}
	else
	{
		std::cout << "�÷��̾� : ��.. �߸� ������.." << std::endl;
	}
}

void Hotel::outputFood()
{
	for (int i = 0; i < Hotel::getFoodSize(); i++)
	{
		std::cout << i + 1 << ". " << food[i].getName() << ", " << food[i].getDescription() << ", " << food[i].getPrice() << "��" << std::endl;
	}
}

int Hotel::setFriendShip(int num)
{
	return friendShip += num;
}

int Hotel::getFriendShip()
{
	return friendShip;
}

void Hotel::marriageEnding()
{
	system("cls");
	Sleep(2000);
	
	std::cout << "System : ������ �������ϴ�" << std::endl;
	std::cout << "System : ��ȥ ����" << std::endl;
	std::cout << "System : ��ȥ ���� ����) ���� ������ ���� ȣ���� 100 �ѱ��" << std::endl;
	std::cout << "System : ���� ������ ���� ��ȥ�Ͽ� �ູ�ϰ� ��ҽ��ϴ�." << std::endl;

	system("pause");
}

void Hotel::guessFood(Player& player)
{
	std::map<std::string, std::string> food; // 0~15, 16��
	food.insert({ "��ġ�", "��ġ, ���� ���(��ġ, ��, �κ� ��), ����, ����, ���尡��, ��" });
	food.insert({ "�Ұ��", "�Ұ��, ����, ����, ����, ����, ���⸧, ���尡��, ����" });
	food.insert({ "�����", "����, �κ�, ����, ��ȣ��, ����, ����, ���尡��, ��" });
	food.insert({ "������ġ", "�Ļ�, ��, ġ��, ����, �丶��, �������" });
	food.insert({ "�ʹ�", "��, ����, ����, �ұ�, ����" });
	food.insert({ "������", "��, �, ����, ���尡��, ������, ����, ��" });
	food.insert({ "���Ƕ��̽�", "��, ���, ��, ����, ���, ��ø" });
	food.insert({ "����", "�������, �ұ�, ���尡��" });
	food.insert({ "������", "����, �丶��, ����, ����, �巹��" });
	food.insert({ "���", "��, ����" });
	food.insert({ "�����", "���, ��, �ұ�, ����" });
	food.insert({ "���û�", "�ٰ�Ʈ, ����, ����, �Ľ���, �ұ�" });
	food.insert({ "���", "��, ��, �ܹ���, �ñ�ġ, ���, ��" });
	food.insert({ "��¡���", "��¡��, ���尡��, ����, ����, ����, ����, �Ŀ���" });
	food.insert({ "�̿���", "�̿�, �Ұ��, ����, ����, ���⸧, ��" });
	food.insert({ "�������", "����, ������, ���⸧, ����, ���" });

	srand(time(NULL));
	int random = rand() % food.size();

	auto iter = food.begin();
	std::advance(iter, random);

	std::cout << "���� ���� : ��Ḹ ���� ���ĸ��߱� ����!" << std::endl;
	std::cout << "  " << iter->second << std::endl;
	std::cout << "  �� ����Ͽ� ���� ������ ? " << std::endl << std::endl;
	std::cout << "System : ���⸦ ���� ���� ������" << std::endl << std::endl;

	std::string foodName;
	std::cout << "�÷��̾� : ";
	std::cin >> foodName;

	auto it = food.find(foodName); // ������ ������ end ��ȯ

	// �Է��� ���� �̸��� food �ʿ� �ִ��� Ȯ��
	if (it != food.end() && it->second == iter->second)
	{
		std::cout << std::endl << "���� ���� : �����̾�!!!" << std::endl;
		std::cout << "���� ���� : ������� 30�� �ٰ�" << std::endl;

		player.setPrice(player.getPrice() + 30);

		Sleep(2000);
		system("cls");
	}
	else
	{
		std::cout << "���� ���� : Ʋ�Ⱦ�" << std::endl;

		Sleep(2000);
		system("cls");
	}
}


