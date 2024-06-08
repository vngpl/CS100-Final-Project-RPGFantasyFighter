#include "../header/Monster.hpp"

Monster::Monster() : Enemy(300, 50) { }
std::string Monster::getType() const { return "MONSTER"; }