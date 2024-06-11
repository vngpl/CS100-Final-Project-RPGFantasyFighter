#include "../header/Warrior.hpp"

Warrior::Warrior() : Character(125, 100, "WARRIOR") { }

void Warrior::performSpecialAbility() { setHealth(getHealth() + 10); }