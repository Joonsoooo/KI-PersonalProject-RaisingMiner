#include "Inventory.h"
#include <string>
#include <iostream>
#include <vector>

void Inventory::fronAddWeapon(Weapon w)
{
    wI.insert(wI.begin(), w);
}

void Inventory::AddWeapon(Weapon w)
{
    wI.push_back(w);
}

void Inventory::RemoveWeapon()
{
    if (!wI.empty()) {
        wI.erase(wI.begin());
    }
}

void Inventory::RemoveWeapon(Weapon w)
{
    for (int i = 1; i < wI.size(); i++)
    {
        if (wI[i].getName() == w.getName())
        {
            wI.erase(wI.begin() + i);
            break;
        }
    }
}

void Inventory::AddArmour(Armour a)
{
    aI.push_back(a);
}

void Inventory::AddMaterial(Material m)
{
    mI.push_back(m);
}

void Inventory::AddMineral(Mineral m)
{
    minI.push_back(m);
}

void Inventory::RemoveArmour()
{
    if (!aI.empty()) {
        aI.erase(aI.begin());
    }
}

void Inventory::RemoveArmour(Armour a)
{
    for (int i = 3; i < aI.size(); i++)
    {
        if (aI[i].getName() == a.getName())
        {
            aI.erase(aI.begin() + i);
            break;
        }
    }
}

void Inventory::ShowInventory()
{
    gotoxy(60, 0);
    std::cout << "�� �κ��丮 ��" << std::endl << std::endl;

    gotoxy(60, 2);
    std::cout << "����";
    for (int i = 0; i < getWeaponSize(); i++)
    {
        gotoxy(60, 3 + i);
        std::cout << i + 1 << ". " << wI[i].getName() << "\t" << wI[i].getPrice() << std::endl;
    }

    gotoxy(60, 3 + getWeaponSize());
    std::cout << "��";
    for (int i = 0; i < getArmourSize(); i++)
    {
        gotoxy(60, 6 + i + getWeaponSize());
        std::cout << i + 1 << ". " << aI[i].getName() << "\t" << aI[i].getPrice() << std::endl;
    }
}

void Inventory::ShowWeapon()
{
    for (int i = 0; i < getWeaponSize(); i++)
    {
        std::cout << i + 1 << ". " << wI[i].getName() << "\t" << wI[i].getPrice() << std::endl;
    }
}

void Inventory::ShowArmour()
{
    for (int i = 0; i < getArmourSize(); i++)
    {
        std::cout << i + 1 << ". " << aI[i].getName() << "\t" << aI[i].getPrice() << std::endl;
    }
}

void Inventory::ShowMaterial()
{
    for (int i = 0; i < getMaterialSize(); i++)
    {
        std::cout << i + 1 << ". " << mI[i].getName() << "\t" << mI[i].getPrice() << std::endl;
    }
}

int Inventory::getWeaponSize()
{
    return wI.size();
}

int Inventory::getArmourSize()
{
    return aI.size();
}

int Inventory::getMaterialSize()
{
    return mI.size();
}

int Inventory::getMineralSize()
{
    return minI.size();
}

Weapon Inventory::selectWeapon(int choice)
{
    int index = choice - 1;
    if (index >= 0 && index < getWeaponSize())
    {
        return wI[index];
    }
    std::cout << "�߸��� �����Դϴ�." << std::endl;
    return Weapon();
}

Armour Inventory::selectArmour(int choice)
{
    int index = choice - 1;

    if (index >= 0 && index < getArmourSize())
    {
        return aI[index];
    }
}

Weapon Inventory::sellSelectWeapon(int choice) // �÷��̾ ���ο��� �Ǹ� 
{
    int index = choice - 1;
    if (index >= 0 && index < getWeaponSize())
    {
        std::cout << "�÷��̾� : " << wI[index].getName() << "�� �Ȱž�" << std::endl;
        std::cout << "�÷��̾� : " << wI[index].getPrice() / 2 << "���̾�" << std::endl;

        Weapon soldWeapon = wI[index];
        wI.erase(wI.begin() + index); // �ش� �ε����� ���� ����
        std::cout << "���� ���� : ���� ������!" << std::endl << std::endl;
        std::cout << "System : ���⸦ �Ⱦҽ��ϴ�. (���� �Ǹ� ����)" << std::endl;

        return soldWeapon;
    }
    else
    {
        std::cout << "�÷��̾� : ��! �߸� ���߾�.." << std::endl;
        return Weapon();
    }
}

Armour Inventory::sellSelectArmour(int choice)
{
    int index = choice - 1;
    if (index >= 0 && index < getArmourSize())
    {
        std::cout << "�÷��̾� : " << aI[index].getName() << "�� �Ȱž�" << std::endl;
        std::cout << "�÷��̾� : " << aI[index].getPrice() / 2 << "���̾�" << std::endl;

        Armour soldArmour = aI[index];
        aI.erase(aI.begin() + index); // �ش� �ε����� �� ����
        std::cout << "���� ���� : ���� ������!" << std::endl << std::endl;
        std::cout << "System : ���� �Ⱦҽ��ϴ�. (�� �Ǹ� ����)" << std::endl;

        return soldArmour;
    }
    else
    {
        std::cout << "�÷��̾� : ��! �߸� ���߾�.." << std::endl;
        return Armour();
    }
}

Mineral Inventory::sellSelectMineral(int choice)
{
    int index = choice - 1;
    if (index >= 0 && index < getMineralSize())
    {
        std::cout << "�÷��̾� : " << minI[index].getName() << "��(��) �Ȱž�" << std::endl;
        std::cout << "�÷��̾� : " << minI[index].getPrice() << "���̾�" << std::endl;

        Mineral soldMineral = minI[index];
        minI.erase(minI.begin() + index); // �ش� �ε����� �� ����
        std::cout << "���� ���� : ���� ������!" << std::endl << std::endl;
        std::cout << "System : ������ �Ⱦҽ��ϴ�. (���� �Ǹ� ����)" << std::endl;

        return soldMineral;
    }
    else
    {
        std::cout << "�÷��̾� : ��! �߸� ���߾�.." << std::endl;
        return Mineral();
    }
}

std::vector<Weapon>& Inventory::getWeapon()
{
    return wI;
}

std::vector<Armour>& Inventory::getArmour()
{
    return aI;
}

std::vector<Material>& Inventory::getMaterial()
{
    return mI;
}

std::vector<Mineral>& Inventory::getMineral()
{
    return minI;
}

Weapon& Inventory::getWeaponAt(int index)
{
    return wI.at(index);
}

Armour& Inventory::getArmourAt(int index)
{
    return aI.at(index);
}
