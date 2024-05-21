#ifndef __CHARACTER_HPP__
#define __CHARACTER_HPP__

#include <iostream>
#include <string>
// #include "ATTACK_TYPES"

class Character {
    private:
        std::string name;
        double health;
        double experience;
        double
    public:
        Character(const std::string&, int, double, double);
        std::string getName() const;
        double getHealth() const;
        double getExperience() const;
};

#endif