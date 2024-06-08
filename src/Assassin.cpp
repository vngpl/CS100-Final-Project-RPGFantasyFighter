#include "../header/Assassin.cpp"

Assassin::Assassin() : Character(90, 120) { }
std::string Assassin::getType() const override { return "ASSASSIN"; }