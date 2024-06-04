#ifndef __ENEMY_HPP__
#define __ENEMY_HPP__

#include "Character.hpp"

enum EnemyType {MONSTER};

class Enemy {
    private:
        EnemyType type;
        std::string name;
        int health;
        int level;
        double attackStrength;
    public:
        Enemy(EnemyType, const std::string&, int, int, double);
        EnemyType getEnemyType() const;
        const std::string& getName() const;
        int getHealth() const;
        int getLevel() const;
        double getAttackStrength() const;
        virtual void attack(Character&) = 0;
};

#endif