#include "../header/Assassin.hpp"

Assassin::Assassin() : Character(90, 120, "ASSASSIN") { }

void Assassin::performSpecialAbility() { setAttackStrength(getAttackStrength() + 10); }