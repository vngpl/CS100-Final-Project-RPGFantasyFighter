#include "../header/Wizard.hpp"

Wizard::Wizard() : Character(100, 100) { }
std::string Wizard::getType() const { return "WIZARD"; }