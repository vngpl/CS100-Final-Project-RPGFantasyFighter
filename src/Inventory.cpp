#include "../header/Inventory.hpp"

Inventory::Inventory() {
    inventoryItems[0] = nullptr;
    inventoryItems[1] = nullptr;
}

void Inventory::addItem(Item* item) {
    if (item->getType() == "SWORD" || item->getType() == "DAGGER" || item->getType() == "WAND") {
        inventoryItems[0] = item;
    }
    else  {
        inventoryItems[1] = item;
    }
}

void Inventory::useItem(int idx){
    delete inventoryItems[idx];
    inventoryItems[idx] = nullptr;
}

Item* Inventory::getItem(int idx){
    return inventoryItems[idx];
}

bool Inventory::IsEmpty() const {
    return (inventoryItems[0] == nullptr && inventoryItems[1] == nullptr);
}

bool Inventory::OnlyWeapon() const {
    return (inventoryItems[0] != nullptr && inventoryItems[1] == nullptr);
}


bool Inventory::OnlyPotion() const {
    return (inventoryItems[0] == nullptr && inventoryItems[1] != nullptr);
}
