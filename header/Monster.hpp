#ifndef __MONSTER_HPP__
#define __MONSTER_HPP__

#include "Enemy.hpp"

class Monster : public Enemy {
    private:

    public:
        Monster(const std::string&, int, int, double);
        void attack(Character&) override;
};

#endif