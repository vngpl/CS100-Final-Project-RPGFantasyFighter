#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include <string>
#include "Inventory.hpp"
// #include "Experience.hpp"

class Character {
    private:
        int MAX_HEALTH;
        int health;
        int level;
        int coins;
        int monstersSlain;
        double experience;
        double attackStrength;
        Inventory inventory;
        // Experience experience;

    public:
        Character(int, double);
        virtual ~Character() = default;

        virtual std::string getType() const = 0;

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

        bool inventoryIsEmpty();
        bool inventoryOnlyWeapon();
        bool inventoryOnlyPotion();
        // void useItem(Item*);

        bool isDead() const;
        void useItem(int itemIndex);
};

#endif
