#include "../header/Wizard.hpp"

Wizard::Wizard() : Character(125, 100) { }
std::string Wizard::getType() const { return "WIZARD"; }