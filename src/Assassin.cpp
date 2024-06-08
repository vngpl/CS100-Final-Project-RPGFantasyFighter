#include "../header/Assassin.hpp"

Assassin::Assassin() : Character(90, 120) { }
std::string Assassin::getType() const { return "ASSASSIN"; }