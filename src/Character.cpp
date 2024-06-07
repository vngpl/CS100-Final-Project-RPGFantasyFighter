#include "../header/Character.hpp"

Character::Character(CharacterType type, int health, double attackStrength)
    : type(type), health(health), attackStrength(attackStrength), MAX_HEALTH(health), level(5), experience(0.0), monstersSlain(0), coins(0) { }

const std::string Character::getType() const {
    switch (type) {
        case ASSASSIN:
            return "ASSASSIN";
        case WARRIOR:
            return "WARRIOR" ;
        case WIZARD:
            return "WIZARD";
        default:
            return "UNSPECIFIED CHARACTER TYPE";
    }
}

int Character::getHealth() const { return static_cast<int>(health); }
int Character::getLevel() const { return level; }
int Character::getMonstersSlain() const { return monstersSlain; }
int Character::getCoins() const { return coins; }
double Character::getExperience() const { return experience; }
double Character::getAttackStrength() const { return attackStrength; }

void Character::setHealth(int newHealth) { health = newHealth; }
void Character::updateMonsterSlainCount() { monstersSlain++; }
void Character::setCoins(int newCoins) { coins = newCoins; }
void Character::setExperience(double newExperience) { experience = newExperience; }
void Character::setAttackStrength(double newAttackStrength) { attackStrength = newAttackStrength; }

// void Character::useItem(Item* consumable) { inventory.useItem(consumable); }

bool Character::isDead() const { return getHealth() <= 0; }





