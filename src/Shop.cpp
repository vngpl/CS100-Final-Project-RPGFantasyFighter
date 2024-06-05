#include "Shop.h"

Shop::Shop() {
    std::srand(static_cast<unsigned int>(time(nullptr)));
}

Item* Shop::generateRandomItem() {
    int itemType = std::rand() % 3;

    switch (itemType) {
        case 0:
            return generateRandomWeapon();
        case 1:
            return generateRandomPotion();
        case 2:
            return generateRandomArmor();
        default:
            return nullptr;
    }
}

Item* Shop::generateRandomWeapon() {
    Weapon::Type weaponType = static_cast<Weapon::Type>(std::rand() % 3);
    int damage = std::rand() % 100 + 1; // Random number between 1 and 100
    return new Weapon(weaponType, damage);
}

Item* Shop::generateRandomPotion() {
    Potion::Type potionType = static_cast<Potion::Type>(std::rand() % 2);
    int strength = std::rand() % 50 + 1; // Random number between 1 and 50
    return new Potion(potionType, strength);
}

Item* Shop::generateRandomArmor() {
    Armor::Type armorType = static_cast<Armor::Type>(std::rand() % 2);
    int protection = std::rand() % 75 + 1; // Random number between 1 and 75
    return new Armor(armorType, protection);
}