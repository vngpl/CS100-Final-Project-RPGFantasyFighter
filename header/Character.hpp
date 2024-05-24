#ifndef __CHARACTER_HPP__
#define __CHARACTER_HPP__

#include <string>
// #include "ATTACK_TYPES"

enum CharacterType {ASSASSIN, WARRIOR, WIZARD};

class Character {
    private:
        // add maxHealth variable
        CharacterType type;
        std::string name;
        int health;
        int level = 5;
        double experience = 0.0;
        double attackStrength;
    public:
    
        Character(CharacterType,  const std::string&, int, double);
        CharacterType getType() const; 
        const std::string& getName() const;
        int getHealth() const;
        int getLevel() const;
        double getExperience() const;
        double getAttackStrength() const;
        bool isDead() const;
        virtual void attack(Character&) = 0;
};

#endif