#include "Inventory.h"

void Inventory::addItem(Item* item) {
    items.push_back(item);
}

bool Inventory::removeItem(const string& itemName) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if ((*it)->getName() == itemName) {
            items.erase(it);
            return true;
        }
    }
    return false;
}