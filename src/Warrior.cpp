#include "../header/Warrior.hpp"

Warrior::Warrior() : Character(125, 100) { }
std::string Warrior::getType() const override { return "WARRIOR"; }