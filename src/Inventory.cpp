#include "../header/Inventory.hpp"

void Inventory::addItem(Item* item) {
    if (item->getName() == "Weapon") {
        items.at(0) = std::move(item);
    }
    else if (item->getName() == "Potion") {
        items.at(1) = item;
    }
}

