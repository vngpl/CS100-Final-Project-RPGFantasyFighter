#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <cassert>
#include "Item.hpp"

class Inventory
{
public:
    void addItem(Item *item);
    void useItem(int idx);

    Item* getItem(int); 

    bool IsEmpty();
    bool OnlyWeapon();
    bool OnlyPotion();

    Inventory() : items(2, nullptr) {}

private:
    std::vector<Item *> items;
};

#endif
