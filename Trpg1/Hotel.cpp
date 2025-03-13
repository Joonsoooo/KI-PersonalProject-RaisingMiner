#include "Hotel.h"

void Hotel::addFood()
{
	food.push_back(Food("볶음밥", 0, 20, "싱싱한 참치가 들어간 김밥", 10));
	food.push_back(Food("참치김밥", 0, 20, "싱싱한 참치가 들어간 김밥", 10));
	food.push_back(Food("비빔면", 0, 20, "새콤매콤한 비빔면", 10));
	food.push_back(Food("된장찌개", 0, 50, "칼칼한 된장찌개", 30));
	food.push_back(Food("삼겹살", 0, 70, "오늘 도축한 돼지로 구운 삼겹살", 40));
	food.push_back(Food("연어 초밥", 0, 70, "방금 뜬 연어", 40));
}

Food Hotel::sellFood(int choice)
{
	if (choice  < 1 || choice > getFoodSize())
	{
		std::cout << "여관 주인 : 메뉴를 잘 봐야지~" << std::endl;
		return Food();
	}

	int index = choice - 1;

	food.erase(food.begin() + index);
	std::cout << std::endl << "여관 주인 : 맛있게 먹어~" << std::endl << std::endl;
	std::cout << std::endl << "System : 음식을 먹었습니다. (체력 상승)" << std::endl;

	return food[index];
}

Food Hotel::selectFood(int choice)
{

	int index = choice - 1;

	std::cout << "여관 주인 : " << food[index].getName() << "를 먹을 거야??" << std::endl;
	std::cout << "여관 주인 : " << food[index].getPrice() << "원이야" << std::endl;
	return food[index];
}

std::vector<Food>& Hotel::getFood()
{
	return food;
}



void Hotel::hotelSleep(Player& player)
{
	// 랜덤으로 (꿀잠, 악몽, 돼지꿈, 행복한 꿈 등) ?
	srand(time(NULL));
	int random = rand() % 4;

	switch (random)
	{
	case 0:
		std::cout << "System : 재밌는 꿈을 꾸는 것 같습니다." << std::endl;
		break;
	case 1:
		std::cout << "System : 행복한 꿈을 꾸는 것 같습니다." << std::endl;
		break;
	case 2:
		std::cout << "플레이어 : 드르렁! ....." << std::endl << std::endl;
		std::cout << "System : 오늘은 잠버릇이 안좋네요..." << std::endl;
		break;
	case 3:
		std::cout << "플레이어 : 으윽!!" << std::endl << std::endl;
		std::cout << "System : 악몽을 꾸는 것 같습니다." << std::endl;
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
		std::cout << "플레이어 : 안녕 오늘 하루 뭐하고 지냈어? " << std::endl;
		std::cout << "여관 주인 딸 : 오늘 바빴어.." << std::endl << std::endl;
		break;
	case 1:
		std::cout << "플레이어 : 내가 오늘 어떤 광물을 발견했냐면! ......" << std::endl;
		std::cout << "여관 주인 딸 : 와! 정말 신기해!!" << std::endl << std::endl;
		break;
	case 2:
		std::cout << "플레이어 : 오늘따라 더 이쁘네?" << std::endl;
		std::cout << "여관 주인 딸 : 어머.. 정말?!" << std::endl << std::endl;
		break;
	case 3:
		std::cout << "플레이어 : 광물 캐다가 생각나서 들렸어" << std::endl;
		std::cout << "여관 주인 딸 : 어머! 뭐야,, " << std::endl << std::endl;
		break;
	case 4:
		std::cout << "플레이어 : 여관 요리는 언제 먹어도 맛있어!" << std::endl;
		std::cout << "여관 주인 딸 : 매 번 맛있게 먹어줘서 고마워" << std::endl << std::endl;
		break;
	}

	int friendShipLevel = rand() % 15+1; // 호감도 상승량을 외부에서 정의

	std::cout << "System : 호감도가 " << friendShipLevel << "상승했습니다." << std::endl;
	Hotel::setFriendShip(friendShipLevel); // 호감도 갱신
	std::cout << "System : 현재 호감도 : " << Hotel::getFriendShip() << std::endl; // 갱신된 호감도 출력

	Sleep(3000);
	system("cls");
}


void Hotel::Gift(int choice, Player& player)
{
	Inventory inventory = player.getInventory();

	std::vector<Material>& currentMaterials = inventory.getMaterial();

	if (choice >= 0 && choice <= currentMaterials.size())
	{
		Material selectedMaterial = currentMaterials[choice-1]; // 선택한 재료
		int friendShipLevel = rand() % selectedMaterial.getPrice() + 1;
		currentMaterials.erase(currentMaterials.begin() + choice-1);

		std::cout << "여관 주인 딸 : 어머! 뭐야 이게??" << std::endl << std::endl;

		std::cout << "System : 선물을 주었습니다." << std::endl;


		std::cout << "System : 호감도가 " << friendShipLevel << "상승했습니다." << std::endl;
		Hotel::setFriendShip(friendShipLevel); // 호감도 갱신
		std::cout << "System : 현재 호감도 :  " << Hotel::getFriendShip() << std::endl;

		Sleep(2000);
		system("cls");
	}
	else
	{
		std::cout << "플레이어 : 아.. 잘못 눌렀어.." << std::endl;
	}
}

void Hotel::outputFood()
{
	for (int i = 0; i < Hotel::getFoodSize(); i++)
	{
		std::cout << i + 1 << ". " << food[i].getName() << ", " << food[i].getDescription() << ", " << food[i].getPrice() << "원" << std::endl;
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
	
	std::cout << "System : 게임이 끝났습니다" << std::endl;
	std::cout << "System : 결혼 엔딩" << std::endl;
	std::cout << "System : 결혼 엔딩 조건) 여관 주인의 딸과 호감도 100 넘기기" << std::endl;
	std::cout << "System : 여관 주인의 딸과 결혼하여 행복하게 살았습니다." << std::endl;

	system("pause");
}

void Hotel::guessFood(Player& player)
{
	std::map<std::string, std::string> food; // 0~15, 16개
	food.insert({ "김치찌개", "김치, 돼지 고기(참치, 햄, 두부 등), 대파, 마늘, 고춧가루, 물" });
	food.insert({ "불고기", "소고기, 간장, 설탕, 마늘, 양파, 참기름, 후춧가루, 대파" });
	food.insert({ "된장찌개", "된장, 두부, 감자, 애호박, 양파, 대파, 고춧가루, 물" });
	food.insert({ "샌드위치", "식빵, 햄, 치즈, 상추, 토마토, 마요네즈" });
	food.insert({ "초밥", "밥, 식초, 설탕, 소금, 생선" });
	food.insert({ "떡볶이", "떡, 어묵, 대파, 고춧가루, 고추장, 설탕, 물" });
	food.insert({ "오므라이스", "밥, 계란, 햄, 양파, 당근, 케첩" });
	food.insert({ "삼겹살", "돼지고기, 소금, 후춧가루" });
	food.insert({ "샐러드", "상추, 토마토, 오이, 양파, 드레싱" });
	food.insert({ "라면", "면, 스프" });
	food.insert({ "계란찜", "계란, 물, 소금, 대파" });
	food.insert({ "마늘빵", "바게트, 버터, 마늘, 파슬리, 소금" });
	food.insert({ "김밥", "김, 밥, 단무지, 시금치, 계란, 햄" });
	food.insert({ "오징어볶음", "오징어, 고춧가루, 간장, 마늘, 양파, 대파, 식용유" });
	food.insert({ "미역국", "미역, 소고기, 마늘, 간장, 참기름, 물" });
	food.insert({ "비빔국수", "국수, 고추장, 참기름, 오이, 계란" });

	srand(time(NULL));
	int random = rand() % food.size();

	auto iter = food.begin();
	std::advance(iter, random);

	std::cout << "여관 주인 : 재료만 보고 음식맞추기 게임!" << std::endl;
	std::cout << "  " << iter->second << std::endl;
	std::cout << "  를 사용하여 만든 음식은 ? " << std::endl << std::endl;
	std::cout << "System : 띄어쓰기를 하지 말고 쓰세요" << std::endl << std::endl;

	std::string foodName;
	std::cout << "플레이어 : ";
	std::cin >> foodName;

	auto it = food.find(foodName); // 음식이 없으면 end 반환

	// 입력한 음식 이름이 food 맵에 있는지 확인
	if (it != food.end() && it->second == iter->second)
	{
		std::cout << std::endl << "여관 주인 : 정답이야!!!" << std::endl;
		std::cout << "여관 주인 : 상금으로 30원 줄게" << std::endl;

		player.setPrice(player.getPrice() + 30);

		Sleep(2000);
		system("cls");
	}
	else
	{
		std::cout << "여관 주인 : 틀렸어" << std::endl;

		Sleep(2000);
		system("cls");
	}
}


