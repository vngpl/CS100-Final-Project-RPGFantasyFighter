#ifndef __ASSASSIN_HPP__
#define __ASSASSIN_HPP__

#include "Character.hpp"

class Assassin : public Character {
    private:

    public:
        Assassin(const std::string&, int, double, double);
        void attack(Character&) override;
        // IMPLEMENT ATTACK FUNCTIONS
};

#endif