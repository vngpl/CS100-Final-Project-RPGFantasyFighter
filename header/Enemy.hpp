#ifndef __ENEMY_HPP__
#define __ENEMY_HPP__

#include "Character.hpp"

class Enemy {
    private:
        int health;
        int level;
        double attackStrength;

    public:
        Enemy(int, double);
        virtual ~Enemy() = default;

        virtual std::string getType() const = 0;

        int getHealth() const;
        int getLevel() const;
        double getAttackStrength() const;

        void setHealth(int);
        void setLevel(int);
        void setAttackStrength(double);
};

#endif