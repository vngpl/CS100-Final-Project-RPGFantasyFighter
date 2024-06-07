#ifndef SHOP_H
#define SHOP_H

#include <cstdlib>
#include <ctime>
#include "Item.h"

class Shop {
public:
    Shop();
    Item* generateRandomItem();

private:
    Item* generateRandomWeapon();
    Item* generateRandomPotion();
    Item* generateRandomArmor();
};

#endif