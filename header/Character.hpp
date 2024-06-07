#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include <string>
#include "Inventory.hpp"
// #include "Experience.hpp"

class Character {
    public:
        enum CharacterType {ASSASSIN, WARRIOR, WIZARD};

    private:
        int coins;
        Inventory inventory;
        // Experience experience;
        CharacterType type;
        int health;
        int MAX_HEALTH;
        int monstersSlain;
        int level;
        double experience;
        double attackStrength;

    public:
        Character(CharacterType, int, double);

        const std::string getType() const;
        int getHealth() const;
        int getLevel() const;
        int getMonstersSlain() const;
        int getCoins() const;
        double getExperience() const;
        double getAttackStrength() const;

        void setCoins(int);
        void setHealth(int);
        void setExperience(double);
        void updateMonsterSlainCount();
        void setAttackStrength(double);

        // void useItem(Item*);

        bool isDead() const;
};

#endif