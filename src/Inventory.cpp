#include "../header/Inventory.h"
#include "header/Character.hpp"

void Inventory::addItem(Item* item) {
    // if (item->getName() == "Weapon") {
    //     items.at(0) = item;
    // } 
    // else if (item->getName() == "Potion") {
    //     items.at(1) = item; 
    // }
    if (dynamic_cast<Weapon*>(item)) {
        items.at(0) = item;
        std::cerr << (static_cast<Weapon*>(item)->getType() == Weapon::Type::Sword) << '\n';
    }
    if (dynamic_cast<Potion*>(item)) {
        items.at(1) = item;
    }
}

void useItem(Character* character, Item* item){
    if (static_cast<Weapon*>(item)->getType() == Weapon::Type::Sword){
        if (character->getType() == WARRIOR){
            character->attackStrength += static_cast<Weapon*>(item)->getDamage();
            character->attackStrength += 15;
        }
        else{
            character->attackStrength += static_cast<Weapon*>(item)->getDamage();
        }
        delete item; 
    }
    else if (static_cast<Weapon*>(item)->getType() == Weapon::Type::Dagger){
        if (character->getType() == ASSASSIN){
            character->attackStrength += static_cast<Weapon*>(item)->getDamage();
            character->attackStrength += 15;
        }
        else{
            character->attackStrength += static_cast<Weapon*>(item)->getDamage();
        }
        delete item; 
    }
    else if (static_cast<Weapon*>(item)->getType() == Weapon::Type::Wand){
        if (character->getType() == WIZARD){
            character->attackStrength += static_cast<Weapon*>(item)->getDamage();
            character->attackStrength += 15;
        }
        else{
            character->attackStrength += static_cast<Weapon*>(item)->getDamage();
        }
        delete item; 
    }
    else if (static_cast<Potion*>(item)->getType() == Potion::Type::AttackBoost){
        character->attackStrength += static_cast<Potion*>(item)->getStrength();
        delete item; 
    }
    else if (static_cast<Potion*>(item)->getType() == Potion::Type::HealthRecovery){
        character->attackStrength += static_cast<Potion*>(item)->getStrength();
        delete item; 
    }
}
