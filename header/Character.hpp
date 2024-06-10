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
        std::string type;
        std::vector<Item*> inventory;

    public:
        Character(int, double, const std::string&);
        virtual ~Character();

        int getHealth() const;
        int getMaxHealth() const;
        int getLevel() const;
        int getMonstersSlain() const;
        int getCoins() const;
        double getExperience() const;
        double getNextExperience() const; ///NEW
        double getAttackStrength() const;
        virtual const std::string& getType() const;
        const std::vector<Item*>& getInventoryItems() const;

        void setCoins(int);
        void setHealth(int);
        void setExperience(double);
        void setNextExperience(double); ///NEW
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
