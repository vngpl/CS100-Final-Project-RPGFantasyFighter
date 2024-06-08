#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>

class Item {
    private:
        int strength;
        int cost;

    public:
        Item(int, int);
        virtual ~Item() = default;
        int getStrength() const;
        int getCost() const;
        void setStrength(int);
        void setCost(int);
        virtual std::string getType() const = 0;
        Item* generateRandomItem();

};

class Sword : public Item {
    public:
        Sword();
        std::string getType() const override;
};

class Dagger : public Item {
    public:
        Dagger();
        std::string getType() const override;
};

class Wand : public Item {
    public:
        Wand();
        std::string getType() const override;
};

class HealthPotion : public Item {
    public:
        HealthPotion();
        std::string getType() const override;
};

class AttackPotion : public Item {
    public:
        AttackPotion();
        std::string getType() const override;
};

#endif