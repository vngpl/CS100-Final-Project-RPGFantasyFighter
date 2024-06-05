#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include "Item.h"

class Inventory {
public:
    void addItem(Item* item);
    bool removeItem(const string& itemName);

private:
    vector<Item*> items;
};

#endif // INVENTORY_H