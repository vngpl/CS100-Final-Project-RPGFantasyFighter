#ifndef __CHARACTER_HPP__
#define __CHARACTER_HPP__

#include <string>
// #include "ATTACK_TYPES"

enum CharacterType {ASSASSIN, WARRIOR, WIZARD};

class Character {
    private:
        CharacterType type;
        std::string name;
        int health;
        double experience;
        double attackStrength;
    public:
        Character(CharacterType,  const std::string&, int, double, double);
        CharacterType getType() const; 
        const std::string& getName() const;
        int getHealth() const;
        double getExperience() const;
        double getAttackStrength() const;
        bool isAlive() const;
        virtual void attack(Character&) = 0;
};

#endif