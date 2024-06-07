#ifndef __CHARACTER_HPP__
#define __CHARACTER_HPP__

#include <string>
#include "Inventory.hpp"

class Character {
    private:
        enum CharacterType {ASSASSIN, WARRIOR, WIZARD};
        Inventory inventory;
        CharacterType type;
        std::string name;
        int health;
        int maxHealth;
        int level = 5;
        double experience = 0.0;
        double attackStrength;

    public:
        Character(CharacterType,  const std::string&, int, double);

        CharacterType& getType() const;
        const std::string& getName() const;
        int getHealth() const;
        int getLevel() const;
        double getExperience() const;
        double getAttackStrength() const;

        void setHealth(int);
        void setExperience(double);

        void useItem(Item*);

        bool isDead() const;
        // virtual void attack(Character&) = 0;
};

#endif