#ifndef SHOP_H
#define SHOP_H

#include <cstdlib>
#include <ctime>
#include "Item.hpp"

class Shop {
public:
    Shop();
    Item* generateRandomItem();

private:
    Item* generateRandomWeapon();
    Item* generateRandomPotion();
};

#endif