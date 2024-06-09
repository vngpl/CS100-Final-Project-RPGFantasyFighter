#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>

class Item {
    private:
        int strength;
        int cost;
        std::string type;

    public:
        Item(int, int);
        virtual ~Item() = default;
        int getStrength() const;
        int getCost() const;
        void setStrength(int);
        void setCost(int);
        virtual const std::string& getType() const;
        Item* generateRandomItem();

};

class Sword : public Item {
    public:
        Sword();
};

class Dagger : public Item {
    public:
        Dagger();
};

class Wand : public Item {
    public:
        Wand();
};

class HealthPotion : public Item {
    public:
        HealthPotion();
};

class AttackPotion : public Item {
    public:
        AttackPotion();
};

#endif