#pragma once
#include "Item.h"
#include <string>

// 방어구 타입을 구별하기 위한 열거형
enum class ArmourType {
    Helmet,
    Chestplate,
    Leggings
};

class Armour : public Item {
private:
    ArmourType type; // 방어구 타입

public:
    // 생성자
    Armour(std::string n, int a, int health, std::string aD, int price, ArmourType t);
    Armour();

    // 방어구 타입을 반환하는 함수
    ArmourType getType() const;
};