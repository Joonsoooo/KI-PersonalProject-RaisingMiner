#pragma once
#include "Item.h"
#include <string>

// �� Ÿ���� �����ϱ� ���� ������
enum class ArmourType {
    Helmet,
    Chestplate,
    Leggings
};

class Armour : public Item {
private:
    ArmourType type; // �� Ÿ��

public:
    // ������
    Armour(std::string n, int a, int health, std::string aD, int price, ArmourType t);
    Armour();

    // �� Ÿ���� ��ȯ�ϴ� �Լ�
    ArmourType getType() const;
};