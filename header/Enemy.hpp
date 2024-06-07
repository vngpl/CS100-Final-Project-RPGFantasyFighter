#ifndef __ENEMY_HPP__
#define __ENEMY_HPP__

#include "Character.hpp"

enum EnemyType {MONSTER};

class Enemy {
    private:
        EnemyType type;
        int health;
        int level;
        double attackStrength;

    public:
        Enemy(EnemyType, int, double);
        const std::string& getEnemyType() const;
        int getHealth() const;
        int getLevel() const;
        double getAttackStrength() const;

        void setHealth(int);
        // void setLevel();
        void setAttackStrength();
};

#endif