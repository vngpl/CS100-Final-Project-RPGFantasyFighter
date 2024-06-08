#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include "Item.hpp"

#include <string>
#include <vector>

class Character {
    private:
        int MAX_HEALTH;
        int health;
        int level;
        int coins;
        int monstersSlain;
        double experience;
        double attackStrength;
        std::vector<Item*> inventory;
        // Coins coins;
        // Experience experience;

    public:
        Character(int, double);
        virtual ~Character() = default;

        virtual std::string getType() const = 0;

        int getHealth() const;
        int getMaxHealth() const;
        int getLevel() const;
        int getMonstersSlain() const;
        int getCoins() const;
        double getExperience() const;
        double getAttackStrength() const;
        const std::vector<Item*>& getInventoryItems() const;

        void setCoins(int);
        void setHealth(int);
        void setExperience(double);
        void updateMonsterSlainCount();
        void setAttackStrength(double);

        bool inventoryIsEmpty() const;
        bool hasWeapon() const;
        bool hasPotion() const;
        bool isDead() const;

        void addItem(Item*);
        void useItem(int);
};

#endif
