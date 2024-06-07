#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include "Item.h"

class Inventory {
public:
    void addItem(Item* item);
    void useItem(Character* character, Item* item);
      
    Inventory() : items(2, nullptr) {}

private:
    std::vector<Item*> items;
};

#endif 