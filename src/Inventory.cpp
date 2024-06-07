#include "../header/Inventory.hpp"

void Inventory::addItem(Item* item) {
    if (dynamic_cast<Weapon*>(item)) {
        items.at(0) = item;
        //std::cerr << (static_cast<Weapon*>(item)->getType() == Weapon::Type::Sword) << '\n';
    }
    if (dynamic_cast<Potion*>(item)) {
        items.at(1) = item;
    }
}

void Inventory::useItem(int idx){
    delete items.at(idx);
    items.at(idx) = nullptr;
}

Item* Inventory::getItem(int idx){
    return items.at(idx);
}

bool Inventory::IsEmpty() {
    return (items.at(0) == nullptr && items.at(1) == nullptr);
}

bool Inventory::OnlyWeapon() {
    return (items.at(0) != nullptr && items.at(1) == nullptr);
}


bool Inventory::OnlyPotion() {
    return (items.at(0) == nullptr && items.at(1) != nullptr);
}
