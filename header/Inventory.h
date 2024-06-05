#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include "Item.h"

class Inventory {
public:
    void addItem(Item* item);

    Inventory() : items(2) {}

private:
    std::vector<Item*> items;
};

#endif // INVENTORY_H