#include "../header/Wizard.hpp"

Wizard::Wizard() : Character(100, 100, "WIZARD") { }

void Wizard::performSpecialAbility() {
    setAttackStrength(getAttackStrength() + 5);
    setHealth(getHealth() + 5);
}