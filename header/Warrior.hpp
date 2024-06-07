#ifndef __WARRIOR_HPP__
#define __WARRIOR_HPP__

#include "Character.hpp"

class Warrior : public Character {
    private:

    public:
        Warrior(const std::string&, int, double);
        void attack(Character&) override;
        // IMPLEMENT ATTACK FUNCTIONS
};

#endif