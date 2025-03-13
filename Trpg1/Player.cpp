#include "Player.h"
#include <string>

Player::Player()
{
}

Player::Player(int h, int a, int p) : Character(h, a), price(p)
{
	Weapon W("�ƺ��� �ֽ� ���", 10, 0, "���� ���Ҵ�.", 10);
	Armour H("���� ���� ����", 0, 3, "����� ����", 10, ArmourType::Helmet);
	Armour A("�۾� ��", 0, 5, "�۾��� �� �Դ� ����", 15, ArmourType::Chestplate);
	Armour L("�۾� ����", 0, 3, "�۾��� �� �Դ� ����", 10, ArmourType::Leggings);

	Player::getInventory().AddWeapon(W);
	Player::getInventory().AddArmour(H);
	Player::getInventory().AddArmour(A);
	Player::getInventory().AddArmour(L);

	Player::setAttack(Player::getAttack() + W.getAttack());
	Player::setHealth(Player::getHealth() + H.getHealth());
	Player::setHealth(Player::getHealth() + A.getHealth());
	Player::setHealth(Player::getHealth() + L.getHealth());
}

Player::~Player()
{
}

//void Player::attackMineral(Mineral m)
//{
//	if (getHealth() <= m.getHealth())
//	{
//		std::cout << "�÷��̾� : ���� �Ѱ��.." << std::endl << std::endl;
//
//		std::cout << "Systme : ü���� �����մϴ�." << std::endl;
//
//	}
//	else
//	{
//		int newHealth = getHealth() - m.getHealth(); // ü�� ����
//		getInventory().AddMineral(m); // �κ� �߰� 
//	}
//	
//}

void Player::Attack()
{
}

void Player::Miss()
{
}

void Player::Move()
{
	std::cout << "�͹� �͹� ...." << std::endl;
}

int Player::SkillAttack(int skill)
{
	return 0;
}

int Player::TakeDamage(int attack)
{
	return 0;
}

int Player::getPrice()
{
	return price;
}

int Player::getMaxHealth()
{
	return maxHealth;
}

int Player::setPrice(int p)
{
	price = p;
	return price;
}

void Player::setMaxHealth(int h)
{
	maxHealth = h;
}

int Player::BuyWeapon(Weapon w)
{
	if (getPrice() < w.getPrice())
	{
		std::cout << "���� ���� : ����! ���� �����鼭" << std::endl;
		return -1;
	}
	else
	{
		int newPrice = getPrice() - w.getPrice();
		return setPrice(newPrice);
	}
}
int Player::BuyArmour(Armour a)
{
	if (getPrice() < a.getPrice())
	{
		std::cout << "���� ���� : ����! ���� �����鼭" << std::endl;
		return -1;
	}
	else
	{
		int newPrice = getPrice() - a.getPrice();
		return setPrice(newPrice);
	}
}
int Player::BuyMaterial(Material m)
{
	if (getPrice() < m.getPrice())
	{
		std::cout << "���� ���� : ����! ���� �����鼭" << std::endl;
		return 0;
	}
	else
	{
		int newPrice = getPrice() - m.getPrice();
		return setPrice(newPrice);
	}
} // ������ ����
int Player::BuyFood(Food f)
{
	if (getPrice() < f.getPrice())
	{
		std::cout << std::endl << "���� ���� : ����! ���� �����鼭" << std::endl;
		return 0;
	}
	else
	{
		int newPrice = getPrice() - f.getPrice();
		return setPrice(newPrice);
	}
}
int Player::SellWeapon(Weapon w)
{
	int newPrice = getPrice() + (w.getPrice() / 2);
	return setPrice(newPrice);

}
int Player::SellArmour(Armour a)
{
	int newPrice = getPrice() + (a.getPrice() / 2);
	return setPrice(newPrice);
}


void Player::ShowInventory() {
	gotoxy(60, 0);
	std::cout << "�� �κ��丮 ��" << std::endl << std::endl;

	gotoxy(62, 2);
	std::cout << "������ : " << Player::getPrice();

	gotoxy(62, 4);
	std::cout << "����";
	std::vector<Weapon>& weapons = inventory.getWeapon(); // wI�� ����
	for (int i = 0; i < weapons.size(); i++) {
		gotoxy(62, 5 + i);
		if (i == 0)
		{
			std::cout << i + 1 << ". " << weapons[i].getName() << " (������) " << " ���ݷ� : " << weapons[i].getAttack() << " ���� : " << weapons[i].getPrice() << std::endl;
		}
		else 
		{
			std::cout << i + 1 << ". " << weapons[i].getName() << " ���ݷ� : " << weapons[i].getAttack() << " ���� : " << weapons[i].getPrice() << std::endl;
		}
	}

	gotoxy(62, 6 + weapons.size());
	std::cout << "��" << std::endl;
	std::vector<Armour>& armours = inventory.getArmour();
	for (int i = 0; i < armours.size(); i++) 
	{
		gotoxy(62, 7 + i + weapons.size());
		if (i == 0 || i == 1 || i == 2)
		{
			std::cout << i + 1 << ". " << armours[i].getName() << " (������) " << " ���� : " << armours[i].getHealth() << " ���� : " << armours[i].getPrice() << std::endl;
		}
		else
		{
			std::cout << i + 1 << ". " << armours[i].getName() << " ���� : " << armours[i].getHealth() << " ���� : " << armours[i].getPrice() << std::endl;
		}
	}

	gotoxy(62, 8 + armours.size() + weapons.size());
	std::cout << "������" << std::endl;
	std::vector<Material>& materials = inventory.getMaterial();

	for (int i = 0; i < materials.size(); i++)
	{
		gotoxy(62, 9 + i + armours.size() + weapons.size());
		std::cout << i + 1 << ". " << materials[i].getName() << " ���� : " << materials[i].getPrice() << std::endl;
	}


	gotoxy(62, 10 + armours.size() + weapons.size() + materials.size());
	std::cout << "����" << std::endl;
	std::vector<Mineral>& minerals = inventory.getMineral();

	int l = 10;

	for (int i = 0; i < minerals.size(); i++)
	{
		if (i >= 10)
		{
			gotoxy(90, 11 + i + armours.size() + weapons.size() + materials.size() - l);
			std::cout << i + 1 << ". " << minerals[i].getName() << " ���� : " << minerals[i].getPrice();
		}
		else
		{
			gotoxy(62, 11 + i + armours.size() + weapons.size() + materials.size());
			std::cout << i + 1 << ". " << minerals[i].getName() << " ���� : " << minerals[i].getPrice();
		}
	}
}

void Player::showStats()
{
	std::vector<Armour>& armours = inventory.getArmour();
	std::vector<Weapon>& weapons = inventory.getWeapon();

	gotoxy(95, 0);
	std::cout << "�� ���� ��";
	gotoxy(97, 2);
	std::cout << "���ݷ� : " << Player::getAttack();

	gotoxy(97, 3);
	std::cout << "ü�� : " << Player::getHealth();
}

void Player::MountedWeapon(Weapon& w)
{
	if (Player::getInventory().getWeaponSize() > 0)
	{
		Weapon& equippedWeapon = Player::getInventory().getWeaponAt(0); // ���� �����Ǿ� �ִ� ���⿡ ����

		int currentAttack = Player::getAttack() - equippedWeapon.getAttack(); //���� ���⸦ ���� �����ؾ� �Ǵ� ���� ����

		Player::getInventory().AddWeapon(equippedWeapon); // ���� ����: ���� �����Ǿ� �ִ� ���⸦ �κ��丮�� �������� �߰�
		Player::getInventory().RemoveWeapon(); // ���� �����Ǿ� ���� ����

		Player::getInventory().fronAddWeapon(w); // ���ο� ���� ����
		Player::getInventory().RemoveWeapon(w); // ���ο� ���⸦ ���������� ����


		Weapon& newEquippedWeapon = Player::getInventory().getWeaponAt(0); // ���� ���ο� ������ ���⸦ ������
		int weaponAttack = newEquippedWeapon.getAttack(); // ���� ������ ������ ���ݷ�

		int newAttack = currentAttack + weaponAttack; 
		Player::setAttack(newAttack); 
	}
}


void Player::UnequipWeapon() // ���������ϸ� �⺻ �ָ��� ������?
{
	Weapon dA("��", 0, 0, "�������� ���� ��", 0);

	Weapon& equippedWeapon = Player::getInventory().getWeaponAt(0); // 0�� �ε��� ����

	if (equippedWeapon.getName() == "��")
	{
		std::cout << "�� ���� ��� �ƴϾ�!" << std::endl;
	}
	else // ���� �ƴϸ� 
	{	
		int currentAttack = Player::getAttack() - equippedWeapon.getAttack(); // ��� ������ ���ݷ� ����
		Player::getInventory().AddWeapon(equippedWeapon); // �κ� �� �ڷ� 
		Player::getInventory().getWeapon()[0] = dA; // �� �߰��� ��� ���� ���� �޸𸮰� ����

		Player::setAttack(currentAttack);

		std::cout << "System : ���� �����߽��ϴ�." << std::endl;
	}
}

void Player::MountedArmour(int choice)
{
	Armour a = Player::getInventory().selectArmour(choice);
	int index = -1;

	// �� Ÿ�Կ� ���� �ε��� ����
	switch (a.getType())
	{
	case ArmourType::Helmet:
		index = 0;
		break;
	case ArmourType::Chestplate:
		index = 1;
		break;
	case ArmourType::Leggings:
		index = 2;
		break;
	}

	if (index != -1)
	{
		if (Player::getInventory().getArmourSize() > index)
		{
			Armour& equippedArmour = Player::getInventory().getArmourAt(index);
			int currentHealth = Player::getHealth() - equippedArmour.getHealth();

			Player::getInventory().AddArmour(equippedArmour); // ���� �����Ǿ� �ִ� ���� �κ��丮�� �߰�

			Player::getInventory().getArmour()[index] = a; // ���ο� ���� ��ü


			Player::getInventory().RemoveArmour(a); // ���������� ���ο� �� ����

			// ü�� ������Ʈ (�ִ� ü���� ��)
			int newHealth = currentHealth + a.getHealth(); // ���ο� ��� ����, ü�� ���
			Player::setHealth(newHealth);

			int newMaxHealth = Player::getHealth(); // ���ο� �ִ�ġ ��������

			if (newMaxHealth > Player::maxHealth) // ���ο� �ִ�ġ�� ���� ����� �ִ�ġ ���� Ŭ ��� 
			{
				Player::maxHealth = newMaxHealth; // ������Ʈ 
			}
		}
	}
}

void Player::UnequipArmour(int choice) // ��� ������ ���� �� �ڿ� �߰��ǰ�, ���� ����
{
	if (choice == 1 || choice == 2 || choice == 3)
	{
		Armour a = Player::getInventory().selectArmour(choice);

		int index = -1;

		// �� Ÿ�Կ� ���� �ε��� ����
		switch (a.getType())
		{
		case ArmourType::Helmet:
			index = 0;
			break;
		case ArmourType::Chestplate:
			index = 1;
			break;
		case ArmourType::Leggings:
			index = 2;
			break;
		}

		Armour& equippedArmour = a;

		if (index == 0) // ����� ��
		{
			if (a.getName() == "�Ӹ�ī��")
			{
				std::cout << "�÷��̾� : �� �Ӹ��� ���ڰ� �ƴϾ�!" << std::endl;
			}
			else
			{
				Armour dH("�Ӹ�ī��", 0, 0, "�⺻ ���", 0, ArmourType::Helmet); // �⺻ ���� ��ü
				Player::getInventory().getArmour()[index] = dH; // �⺻ ����� 0�� �ε����� ����

				int armourHealth = equippedArmour.getHealth(); // ���������� ��� ��ŭ ���� ����
				int newHealth = Player::getHealth() - armourHealth;
				Player::getInventory().RemoveArmour(a); // ���� ������ ��� ����
				Player::getInventory().AddArmour(equippedArmour); // ���� ������ ��� �κ��� �߰�
				Player::setHealth(newHealth);

				std::cout << "���� �����߽��ϴ�." << std::endl;

				int maxHealth;
				maxHealth = Player::getHealth();
				if (Player::getHealth() >= 100 && Player::getHealth() <= maxHealth) // ���� �ִ� ü���� ����� ���� �ȵ�
				{
					maxHealth = Player::getHealth();
					Player::setMaxHealth(maxHealth);
				}
			}
		}
		else if (index == 1) // �� �� ��
		{
			if (a.getName() == "���ױ�") // ���ױ��� �������� �ϸ� 
			{
				std::cout << "�÷��̾� : �� ���°� �ƴϾ�!" << std::endl;
			}
			else // �ٸ� ���� �������� �ϸ� 
			{
				Armour dA("���ױ�", 0, 0, "���", 0, ArmourType::Chestplate);
				Player::getInventory().getArmour()[index] = dA;

				int armourHealth = equippedArmour.getHealth(); // ���������� ��� ��ŭ ���� ����
				int newHealth = Player::getHealth() - armourHealth;
				Player::getInventory().RemoveArmour(a); // ���� ������ ��� ����
				Player::getInventory().AddArmour(equippedArmour); // ���� ������ ��� �κ��� �߰�
				Player::setHealth(newHealth);

				std::cout << "���� �����߽��ϴ�." << std::endl;

				if (Player::getHealth() >= 100 && Player::getHealth() <= maxHealth)
				{
					maxHealth = Player::getHealth();
					Player::setMaxHealth(maxHealth);
				}
			}
		}
		else if (index == 2)
		{
			if (a.getName() == "��Ƽ")
			{
				std::cout << "�÷��̾� : �� ���°� �ƴϾ�!" << std::endl;
			}
			else
			{
				Armour dL("��Ƽ", 0, 0, "�ӿ�", 0, ArmourType::Leggings);
				Player::getInventory().getArmour()[index] = dL;

				int armourHealth = equippedArmour.getHealth(); // ���������� ��� ��ŭ ���� ����
				int newHealth = Player::getHealth() - armourHealth;
				Player::getInventory().RemoveArmour(a); // ���� ������ ��� ����
				Player::getInventory().AddArmour(equippedArmour); // ���� ������ ��� �κ��� �߰�
				Player::setHealth(newHealth);

				std::cout << "���� �����߽��ϴ�." << std::endl;

				if (Player::getHealth() >= 100 && Player::getHealth() <= maxHealth)
				{
					maxHealth = Player::getHealth();
					Player::setMaxHealth(maxHealth);
				}
			}
		}
	}
}

void Player::richEnding()
{
	Sleep(2000);
	system("cls");

	std::cout << "System : ������ �������ϴ�" << std::endl;
	std::cout << "System : ���� ����" << std::endl;
	std::cout << "System : ���� ���� ����) ������ 1000���� �Ѿ����ϴ�." << std::endl;
	std::cout << "System : �������� ���ϰ��� ���ڰ� �Ǿ�, ǳ��ο� ���� ������ �ູ�� �ϻ��� ���½��ϴ�." << std::endl;

	system("pause");
}

Inventory& Player::getInventory() {
	return inventory;
}
