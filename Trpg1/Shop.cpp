#include "Shop.h"
#include <iostream>
#include <vector>
#include <string>

Shop::Shop() 
{
}

Shop::~Shop() 
{
}

void Shop::addWeapon() 
{
    weapon.push_back(Weapon("철 곡괭이", 15, 0, "철로 만든 곡괭이", 30));
    weapon.push_back(Weapon("금 곡괭이", 20, 0, "금으로 만든 곡괭이", 60));
    weapon.push_back(Weapon("다이아 곡괭이", 30, 0, "다이아 곡괭이", 90));
    weapon.push_back(Weapon("드릴", 50, 0, "다 부시는 세계 최강 곡괭이", 150));
}

void Shop::addWeapon(Weapon w)
{
    weapon.push_back(w);
}

void Shop::addArmour() 
{
    armour.push_back(Armour("초급 광부 모자", 0, 10, "가장 싼 광부 모자", 15, ArmourType::Helmet));
    armour.push_back(Armour("초급 광부 옷", 0, 20, "가장 싼 광부 옷", 25, ArmourType::Chestplate));
    armour.push_back(Armour("초급 광부 바지", 0, 10, "가장 싼 광부 바지", 15, ArmourType::Leggings));
    armour.push_back(Armour("중급 광부 모자", 0, 15, "적당한 가격의 광부 모자", 30, ArmourType::Helmet));
    armour.push_back(Armour("중급 광부 옷", 0, 30, "적당한 가격의 광부 옷", 40, ArmourType::Chestplate));
    armour.push_back(Armour("중급 광부 바지", 0, 15, "적당한 가격의 광부 바지", 30, ArmourType::Leggings));
    armour.push_back(Armour("고급 광부 모자", 0, 25, "가장 비싼 광부 모자", 50, ArmourType::Helmet));
    armour.push_back(Armour("고급 광부 옷", 0, 50, "가장 비싼 광부 옷", 60, ArmourType::Chestplate));
    armour.push_back(Armour("고급 광부 바지", 0, 25, "가장 비싼 광부 바지", 50, ArmourType::Leggings));
}

void Shop::addArmour(Armour a)
{
    armour.push_back(a);
}

void Shop::addMaterial() 
{
    material.push_back(Material("탕후루", 0, 0, "계절 과일로 만든 탕후루", 10));
    material.push_back(Material("꽃다발", 0, 0, "계절 꽃으로 만든 꽃다발", 20));
    material.push_back(Material("귀걸이", 0, 0, "인공적으로 가공된 광물로 만든 귀걸이", 40));
    material.push_back(Material("반지", 0, 0, "원석으로 만든 반지", 50));
    material.push_back(Material("다이아몬드 반지", 0, 0, "내가 캔 다이아로 만든 반지", 70));
}

// 플레이어가 판매
void Shop::buyWeapon(Weapon w, Player p) {
    int newPrice = p.getPrice() - w.getPrice();
    p.setPrice(newPrice);
}

void Shop::buyArmour(Armour a, Player p) {
    int newPrice = p.getPrice() - a.getPrice();
    p.setPrice(newPrice);
}

void Shop::buyMaterial(Material m, Player p) {
    int newPrice = p.getPrice() - m.getPrice();
    p.setPrice(newPrice);
}

void Shop::outputWeapon() {
    for (int i = 0; i < weapon.size(); i++) {
        std::cout << i + 1 << ". " << weapon[i].getName() << ", " << "공격력 : " << weapon[i].getAttack() << ", " << weapon[i].getDescription() << ", " << weapon[i].getPrice() << "원" << std::endl;
    }
}

void Shop::outputArmour() {
    for (int i = 0; i < armour.size(); i++) {
        std::cout << i + 1 << ". " << armour[i].getName() << ", " << "체력 : " << armour[i].getHealth() << ", " << armour[i].getDescription() << ", " << armour[i].getPrice() << "원" << std::endl;
    }
}

void Shop::outputMaterial() {
    for (int i = 0; i < material.size(); i++) {
        std::cout << i + 1 << ". " << material[i].getName() << ", " << material[i].getDescription() << ", " << material[i].getPrice() << "원" << std::endl;
    }
}

// 플레이어가 구매 
int Shop::SellWeapon(int choice) {
    if (choice < 1 || choice > getWeaponSize()) {
        //std::cout << "상점 주인 : 어이 제대로 보고 골라!!" << std::endl;
        return -1;
    }
    int index = choice - 1;
    weapon.erase(weapon.begin() + index);
    std::cout << std::endl << "System : 구매를 완료했습니다. (무기 구매 완료)" << std::endl;
    return 0;
}

int Shop::SellArmour(int choice) {
    if (choice < 1 || choice > getArmourSize()) {
        //std::cout << "상점 주인 : 어이 제대로 보고 골라!!" << std::endl;
        return -1;
    }
    int index = choice - 1;
    armour.erase(armour.begin() + index);
    std::cout << std::endl << "System : 구매를 완료했습니다. (방어구 구매 완료)" << std::endl;
    return 0;
}

int Shop::SellMaterial(int choice) {
    if (choice < 1 || choice > getMaterialSize()) {
        //std::cout << "상점 주인 : 어이 제대로 보고 골라!!" << std::endl;
        return -1;
    }
    int index = choice - 1;
    material.erase(material.begin() + index);
    std::cout << std::endl << "System : 구매를 완료했습니다. (아이템 구매 완료)" << std::endl;
    return 0;
}


int Shop::selectWeapon(int choice , Weapon& selectedWeapon) {
    if (choice < 1 || choice > getWeaponSize()) {
        //std::cout << "상점 주인 : 어이 제대로 보고 골라!!" << std::endl;
        
        return 0;
    }
    else
    {
        int index = choice - 1;
        selectedWeapon = weapon[index]; // 선택된 무기 저장
        std::cout << "상점 주인 : " << weapon[index].getName() << "를 구매할건가?" << std::endl;
        std::cout << "상점 주인 : " << weapon[index].getPrice() << "원 이라네" << std::endl << std::endl;
        return 1;
    }
}

int Shop::getWeaponSize() {
    return weapon.size();
}

int Shop::getArmourSize() {
    return armour.size();
}

int Shop::getMaterialSize()
{
    return material.size();
}

int Shop::selectArmour(int choice, Armour& selectedArmour) {
    if (choice < 1 || choice > getArmourSize()) {
        //std::cout << "상점 주인 : 어이 제대로 보고 골라!!" << std::endl;
        return 0;
    }
    else
    {
        int index = choice - 1;
        selectedArmour = armour[index]; // 선택된 방어구 저장
        std::cout << "상점 주인 : " << armour[index].getName() << "를 구매할건가?" << std::endl;
        std::cout << "상점 주인 : " << armour[index].getPrice() << "원 이라네" << std::endl << std::endl;
        return 1;
    }

    /*int index = choice - 1;
    std::cout << "상점 주인 : " << armour[index].getName() << "를 구매할건가?" << std::endl;
    std::cout << "상점 주인 : " << armour[index].getPrice() << "원 이라네" << std::endl;
    return armour[index];*/
}

int Shop::selectMaterial(int choice, Material& selectedMaterial) {
    if (choice < 1 || choice > getMaterialSize()) {
        //std::cout << "상점 주인 : 어이 제대로 보고 골라!!" << std::endl;
        
        return 0;
    }
    else
    {
        int index = choice - 1;
        selectedMaterial = material[index]; // 선택된 방어구 저장
        std::cout << "상점 주인 : " << material[index].getName() << "를 구매할건가?" << std::endl;
        std::cout << "상점 주인 : " << material[index].getPrice() << "원 이라네" << std::endl << std::endl;
        return 1;
    }


}
