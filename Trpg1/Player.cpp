#include "Player.h"
#include <string>

Player::Player()
{
}

Player::Player(int h, int a, int p) : Character(h, a), price(p)
{
	Weapon W("아빠가 주신 곡괭이", 10, 0, "많이 낡았다.", 10);
	Armour H("낡은 광부 모자", 0, 3, "평범한 모자", 10, ArmourType::Helmet);
	Armour A("작업 옷", 0, 5, "작업할 때 입는 상의", 15, ArmourType::Chestplate);
	Armour L("작업 바지", 0, 3, "작업할 때 입는 바지", 10, ArmourType::Leggings);

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
//		std::cout << "플레이어 : 이젠 한계야.." << std::endl << std::endl;
//
//		std::cout << "Systme : 체력이 부족합니다." << std::endl;
//
//	}
//	else
//	{
//		int newHealth = getHealth() - m.getHealth(); // 체력 감소
//		getInventory().AddMineral(m); // 인벤 추가 
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
	std::cout << "터벅 터벅 ...." << std::endl;
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
		std::cout << "상점 주인 : 뭐야! 돈도 없으면서" << std::endl;
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
		std::cout << "상점 주인 : 뭐야! 돈도 없으면서" << std::endl;
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
		std::cout << "상점 주인 : 뭐야! 돈도 없으면서" << std::endl;
		return 0;
	}
	else
	{
		int newPrice = getPrice() - m.getPrice();
		return setPrice(newPrice);
	}
} // 아이템 구매
int Player::BuyFood(Food f)
{
	if (getPrice() < f.getPrice())
	{
		std::cout << std::endl << "여관 주인 : 뭐야! 돈도 없으면서" << std::endl;
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
	std::cout << "※ 인벤토리 ※" << std::endl << std::endl;

	gotoxy(62, 2);
	std::cout << "소지금 : " << Player::getPrice();

	gotoxy(62, 4);
	std::cout << "무기";
	std::vector<Weapon>& weapons = inventory.getWeapon(); // wI에 접근
	for (int i = 0; i < weapons.size(); i++) {
		gotoxy(62, 5 + i);
		if (i == 0)
		{
			std::cout << i + 1 << ". " << weapons[i].getName() << " (장착됨) " << " 공격력 : " << weapons[i].getAttack() << " 가격 : " << weapons[i].getPrice() << std::endl;
		}
		else 
		{
			std::cout << i + 1 << ". " << weapons[i].getName() << " 공격력 : " << weapons[i].getAttack() << " 가격 : " << weapons[i].getPrice() << std::endl;
		}
	}

	gotoxy(62, 6 + weapons.size());
	std::cout << "방어구" << std::endl;
	std::vector<Armour>& armours = inventory.getArmour();
	for (int i = 0; i < armours.size(); i++) 
	{
		gotoxy(62, 7 + i + weapons.size());
		if (i == 0 || i == 1 || i == 2)
		{
			std::cout << i + 1 << ". " << armours[i].getName() << " (장착됨) " << " 방어력 : " << armours[i].getHealth() << " 가격 : " << armours[i].getPrice() << std::endl;
		}
		else
		{
			std::cout << i + 1 << ". " << armours[i].getName() << " 방어력 : " << armours[i].getHealth() << " 가격 : " << armours[i].getPrice() << std::endl;
		}
	}

	gotoxy(62, 8 + armours.size() + weapons.size());
	std::cout << "아이템" << std::endl;
	std::vector<Material>& materials = inventory.getMaterial();

	for (int i = 0; i < materials.size(); i++)
	{
		gotoxy(62, 9 + i + armours.size() + weapons.size());
		std::cout << i + 1 << ". " << materials[i].getName() << " 가격 : " << materials[i].getPrice() << std::endl;
	}


	gotoxy(62, 10 + armours.size() + weapons.size() + materials.size());
	std::cout << "광물" << std::endl;
	std::vector<Mineral>& minerals = inventory.getMineral();

	int l = 10;

	for (int i = 0; i < minerals.size(); i++)
	{
		if (i >= 10)
		{
			gotoxy(90, 11 + i + armours.size() + weapons.size() + materials.size() - l);
			std::cout << i + 1 << ". " << minerals[i].getName() << " 가격 : " << minerals[i].getPrice();
		}
		else
		{
			gotoxy(62, 11 + i + armours.size() + weapons.size() + materials.size());
			std::cout << i + 1 << ". " << minerals[i].getName() << " 가격 : " << minerals[i].getPrice();
		}
	}
}

void Player::showStats()
{
	std::vector<Armour>& armours = inventory.getArmour();
	std::vector<Weapon>& weapons = inventory.getWeapon();

	gotoxy(95, 0);
	std::cout << "※ 스탯 ※";
	gotoxy(97, 2);
	std::cout << "공격력 : " << Player::getAttack();

	gotoxy(97, 3);
	std::cout << "체력 : " << Player::getHealth();
}

void Player::MountedWeapon(Weapon& w)
{
	if (Player::getInventory().getWeaponSize() > 0)
	{
		Weapon& equippedWeapon = Player::getInventory().getWeaponAt(0); // 현재 장착되어 있는 무기에 접근

		int currentAttack = Player::getAttack() - equippedWeapon.getAttack(); //현재 무기를 장착 해제해야 되니 스탯 감소

		Player::getInventory().AddWeapon(equippedWeapon); // 장착 해제: 현재 장착되어 있는 무기를 인벤토리에 마지막에 추가
		Player::getInventory().RemoveWeapon(); // 현재 장착되어 무기 삭제

		Player::getInventory().fronAddWeapon(w); // 새로운 무기 장착
		Player::getInventory().RemoveWeapon(w); // 새로운 무기를 장착했으니 삭제


		Weapon& newEquippedWeapon = Player::getInventory().getWeaponAt(0); // 이제 새로운 장착된 무기를 가져옴
		int weaponAttack = newEquippedWeapon.getAttack(); // 새로 장착된 무기의 공격력

		int newAttack = currentAttack + weaponAttack; 
		Player::setAttack(newAttack); 
	}
}


void Player::UnequipWeapon() // 장착해제하면 기본 주먹이 나오게?
{
	Weapon dA("손", 0, 0, "굳은살이 박힌 손", 0);

	Weapon& equippedWeapon = Player::getInventory().getWeaponAt(0); // 0번 인덱스 접근

	if (equippedWeapon.getName() == "손")
	{
		std::cout << "내 손은 장비가 아니야!" << std::endl;
	}
	else // 손이 아니면 
	{	
		int currentAttack = Player::getAttack() - equippedWeapon.getAttack(); // 장비 해제시 공격력 감소
		Player::getInventory().AddWeapon(equippedWeapon); // 인벤 맨 뒤로 
		Player::getInventory().getWeapon()[0] = dA; // 손 추가를 어떻게 할지 지금 메모리가 꼬임

		Player::setAttack(currentAttack);

		std::cout << "System : 장착 해제했습니다." << std::endl;
	}
}

void Player::MountedArmour(int choice)
{
	Armour a = Player::getInventory().selectArmour(choice);
	int index = -1;

	// 방어구 타입에 따른 인덱스 설정
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

			Player::getInventory().AddArmour(equippedArmour); // 현재 장착되어 있는 방어구를 인벤토리에 추가

			Player::getInventory().getArmour()[index] = a; // 새로운 방어구로 교체


			Player::getInventory().RemoveArmour(a); // 장착했으니 새로운 방어구 삭제

			// 체력 업데이트 (최대 체력일 때)
			int newHealth = currentHealth + a.getHealth(); // 새로운 장비 장착, 체력 상승
			Player::setHealth(newHealth);

			int newMaxHealth = Player::getHealth(); // 새로운 최대치 가져오기

			if (newMaxHealth > Player::maxHealth) // 새로운 최대치가 현재 저장된 최대치 보다 클 경우 
			{
				Player::maxHealth = newMaxHealth; // 업데이트 
			}
		}
	}
}

void Player::UnequipArmour(int choice) // 장비를 벗으면 벡터 맨 뒤에 추가되고, 스탯 감소
{
	if (choice == 1 || choice == 2 || choice == 3)
	{
		Armour a = Player::getInventory().selectArmour(choice);

		int index = -1;

		// 방어구 타입에 따른 인덱스 설정
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

		if (index == 0) // 헬멧일 때
		{
			if (a.getName() == "머리카락")
			{
				std::cout << "플레이어 : 내 머리는 모자가 아니야!" << std::endl;
			}
			else
			{
				Armour dH("머리카락", 0, 0, "기본 헤어", 0, ArmourType::Helmet); // 기본 방어구로 교체
				Player::getInventory().getArmour()[index] = dH; // 기본 헬멧을 0번 인덱스에 삽입

				int armourHealth = equippedArmour.getHealth(); // 장착해제된 장비 만큼 스탯 감소
				int newHealth = Player::getHealth() - armourHealth;
				Player::getInventory().RemoveArmour(a); // 현재 장착된 장비 제거
				Player::getInventory().AddArmour(equippedArmour); // 현재 장착된 장비 인벤에 추가
				Player::setHealth(newHealth);

				std::cout << "장착 해제했습니다." << std::endl;

				int maxHealth;
				maxHealth = Player::getHealth();
				if (Player::getHealth() >= 100 && Player::getHealth() <= maxHealth) // 결점 최대 체력이 제대로 설정 안됨
				{
					maxHealth = Player::getHealth();
					Player::setMaxHealth(maxHealth);
				}
			}
		}
		else if (index == 1) // 옷 일 때
		{
			if (a.getName() == "난닝구") // 난닝구를 벗으려고 하면 
			{
				std::cout << "플레이어 : 난 변태가 아니야!" << std::endl;
			}
			else // 다른 옷을 벗으려고 하면 
			{
				Armour dA("난닝구", 0, 0, "잠옷", 0, ArmourType::Chestplate);
				Player::getInventory().getArmour()[index] = dA;

				int armourHealth = equippedArmour.getHealth(); // 장착해제된 장비 만큼 스탯 감소
				int newHealth = Player::getHealth() - armourHealth;
				Player::getInventory().RemoveArmour(a); // 현재 장착된 장비 제거
				Player::getInventory().AddArmour(equippedArmour); // 현재 장착된 장비 인벤에 추가
				Player::setHealth(newHealth);

				std::cout << "장착 해제했습니다." << std::endl;

				if (Player::getHealth() >= 100 && Player::getHealth() <= maxHealth)
				{
					maxHealth = Player::getHealth();
					Player::setMaxHealth(maxHealth);
				}
			}
		}
		else if (index == 2)
		{
			if (a.getName() == "팬티")
			{
				std::cout << "플레이어 : 난 변태가 아니야!" << std::endl;
			}
			else
			{
				Armour dL("팬티", 0, 0, "속옷", 0, ArmourType::Leggings);
				Player::getInventory().getArmour()[index] = dL;

				int armourHealth = equippedArmour.getHealth(); // 장착해제된 장비 만큼 스탯 감소
				int newHealth = Player::getHealth() - armourHealth;
				Player::getInventory().RemoveArmour(a); // 현재 장착된 장비 제거
				Player::getInventory().AddArmour(equippedArmour); // 현재 장착된 장비 인벤에 추가
				Player::setHealth(newHealth);

				std::cout << "장착 해제했습니다." << std::endl;

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

	std::cout << "System : 게임이 끝났습니다" << std::endl;
	std::cout << "System : 부자 엔딩" << std::endl;
	std::cout << "System : 부자 엔딩 조건) 소지금 1000원을 넘었습니다." << std::endl;
	std::cout << "System : 마을에서 제일가는 부자가 되어, 풍요로운 삶을 누리며 행복한 일상을 보냈습니다." << std::endl;

	system("pause");
}

Inventory& Player::getInventory() {
	return inventory;
}
