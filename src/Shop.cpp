#include "../header/Shop.h"

Shop::Shop() {
    std::srand(static_cast<unsigned int>(time(nullptr)));
}

Item* Shop::generateRandomItem() {
    int itemType = std::rand() % 2;

    switch (itemType) {
        case 0:
            return generateRandomWeapon();
        case 1:
            return generateRandomPotion();
        default:
            return nullptr;
    }
}

Item* Shop::generateRandomWeapon() {
    Weapon::Type weaponType = static_cast<Weapon::Type>(std::rand() % 3);
    int damage = std::rand() % 50 + 25; // Random number between 25 and 50
    int coinCost = std::rand() % 5 + 1;
    return new Weapon(weaponType, damage, coinCost);
}

Item* Shop::generateRandomPotion() {
    Potion::Type potionType = static_cast<Potion::Type>(std::rand() % 2);
    int strength = std::rand() % 50 + 25; // Random number between 25 and 50
    int coinCost = std::rand() % 5 + 1;
    return new Potion(potionType, strength, coinCost);
}