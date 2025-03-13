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
    weapon.push_back(Weapon("ö ���", 15, 0, "ö�� ���� ���", 30));
    weapon.push_back(Weapon("�� ���", 20, 0, "������ ���� ���", 60));
    weapon.push_back(Weapon("���̾� ���", 30, 0, "���̾� ���", 90));
    weapon.push_back(Weapon("�帱", 50, 0, "�� �νô� ���� �ְ� ���", 150));
}

void Shop::addWeapon(Weapon w)
{
    weapon.push_back(w);
}

void Shop::addArmour() 
{
    armour.push_back(Armour("�ʱ� ���� ����", 0, 10, "���� �� ���� ����", 15, ArmourType::Helmet));
    armour.push_back(Armour("�ʱ� ���� ��", 0, 20, "���� �� ���� ��", 25, ArmourType::Chestplate));
    armour.push_back(Armour("�ʱ� ���� ����", 0, 10, "���� �� ���� ����", 15, ArmourType::Leggings));
    armour.push_back(Armour("�߱� ���� ����", 0, 15, "������ ������ ���� ����", 30, ArmourType::Helmet));
    armour.push_back(Armour("�߱� ���� ��", 0, 30, "������ ������ ���� ��", 40, ArmourType::Chestplate));
    armour.push_back(Armour("�߱� ���� ����", 0, 15, "������ ������ ���� ����", 30, ArmourType::Leggings));
    armour.push_back(Armour("��� ���� ����", 0, 25, "���� ��� ���� ����", 50, ArmourType::Helmet));
    armour.push_back(Armour("��� ���� ��", 0, 50, "���� ��� ���� ��", 60, ArmourType::Chestplate));
    armour.push_back(Armour("��� ���� ����", 0, 25, "���� ��� ���� ����", 50, ArmourType::Leggings));
}

void Shop::addArmour(Armour a)
{
    armour.push_back(a);
}

void Shop::addMaterial() 
{
    material.push_back(Material("���ķ�", 0, 0, "���� ���Ϸ� ���� ���ķ�", 10));
    material.push_back(Material("�ɴٹ�", 0, 0, "���� ������ ���� �ɴٹ�", 20));
    material.push_back(Material("�Ͱ���", 0, 0, "�ΰ������� ������ ������ ���� �Ͱ���", 40));
    material.push_back(Material("����", 0, 0, "�������� ���� ����", 50));
    material.push_back(Material("���̾Ƹ�� ����", 0, 0, "���� ĵ ���̾Ʒ� ���� ����", 70));
}

// �÷��̾ �Ǹ�
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
        std::cout << i + 1 << ". " << weapon[i].getName() << ", " << "���ݷ� : " << weapon[i].getAttack() << ", " << weapon[i].getDescription() << ", " << weapon[i].getPrice() << "��" << std::endl;
    }
}

void Shop::outputArmour() {
    for (int i = 0; i < armour.size(); i++) {
        std::cout << i + 1 << ". " << armour[i].getName() << ", " << "ü�� : " << armour[i].getHealth() << ", " << armour[i].getDescription() << ", " << armour[i].getPrice() << "��" << std::endl;
    }
}

void Shop::outputMaterial() {
    for (int i = 0; i < material.size(); i++) {
        std::cout << i + 1 << ". " << material[i].getName() << ", " << material[i].getDescription() << ", " << material[i].getPrice() << "��" << std::endl;
    }
}

// �÷��̾ ���� 
int Shop::SellWeapon(int choice) {
    if (choice < 1 || choice > getWeaponSize()) {
        //std::cout << "���� ���� : ���� ����� ���� ���!!" << std::endl;
        return -1;
    }
    int index = choice - 1;
    weapon.erase(weapon.begin() + index);
    std::cout << std::endl << "System : ���Ÿ� �Ϸ��߽��ϴ�. (���� ���� �Ϸ�)" << std::endl;
    return 0;
}

int Shop::SellArmour(int choice) {
    if (choice < 1 || choice > getArmourSize()) {
        //std::cout << "���� ���� : ���� ����� ���� ���!!" << std::endl;
        return -1;
    }
    int index = choice - 1;
    armour.erase(armour.begin() + index);
    std::cout << std::endl << "System : ���Ÿ� �Ϸ��߽��ϴ�. (�� ���� �Ϸ�)" << std::endl;
    return 0;
}

int Shop::SellMaterial(int choice) {
    if (choice < 1 || choice > getMaterialSize()) {
        //std::cout << "���� ���� : ���� ����� ���� ���!!" << std::endl;
        return -1;
    }
    int index = choice - 1;
    material.erase(material.begin() + index);
    std::cout << std::endl << "System : ���Ÿ� �Ϸ��߽��ϴ�. (������ ���� �Ϸ�)" << std::endl;
    return 0;
}


int Shop::selectWeapon(int choice , Weapon& selectedWeapon) {
    if (choice < 1 || choice > getWeaponSize()) {
        //std::cout << "���� ���� : ���� ����� ���� ���!!" << std::endl;
        
        return 0;
    }
    else
    {
        int index = choice - 1;
        selectedWeapon = weapon[index]; // ���õ� ���� ����
        std::cout << "���� ���� : " << weapon[index].getName() << "�� �����Ұǰ�?" << std::endl;
        std::cout << "���� ���� : " << weapon[index].getPrice() << "�� �̶��" << std::endl << std::endl;
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
        //std::cout << "���� ���� : ���� ����� ���� ���!!" << std::endl;
        return 0;
    }
    else
    {
        int index = choice - 1;
        selectedArmour = armour[index]; // ���õ� �� ����
        std::cout << "���� ���� : " << armour[index].getName() << "�� �����Ұǰ�?" << std::endl;
        std::cout << "���� ���� : " << armour[index].getPrice() << "�� �̶��" << std::endl << std::endl;
        return 1;
    }

    /*int index = choice - 1;
    std::cout << "���� ���� : " << armour[index].getName() << "�� �����Ұǰ�?" << std::endl;
    std::cout << "���� ���� : " << armour[index].getPrice() << "�� �̶��" << std::endl;
    return armour[index];*/
}

int Shop::selectMaterial(int choice, Material& selectedMaterial) {
    if (choice < 1 || choice > getMaterialSize()) {
        //std::cout << "���� ���� : ���� ����� ���� ���!!" << std::endl;
        
        return 0;
    }
    else
    {
        int index = choice - 1;
        selectedMaterial = material[index]; // ���õ� �� ����
        std::cout << "���� ���� : " << material[index].getName() << "�� �����Ұǰ�?" << std::endl;
        std::cout << "���� ���� : " << material[index].getPrice() << "�� �̶��" << std::endl << std::endl;
        return 1;
    }


}
