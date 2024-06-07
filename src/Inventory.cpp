#include "../header/Inventory.hpp"

void Inventory::addItem(Item* item) {
    // if (item->getName() == "Weapon") {
    //     items.at(0) = item;
    // } 
    // else if (item->getName() == "Potion") {
    //     items.at(1) = item; 
    // }
    if (dynamic_cast<Weapon*>(item)) {
        items.at(0) = item;
        //std::cerr << (static_cast<Weapon*>(item)->getType() == Weapon::Type::Sword) << '\n';
    }
    if (dynamic_cast<Potion*>(item)) {
        items.at(1) = item;
    }
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

Item* Inventory::getItem(int idx){
    return items.at(idx);
}

void Inventory::useItem(int idx){
    delete items.at(idx);
    items.at(idx) = nullptr;
}

