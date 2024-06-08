#ifndef __MONSTER_HPP__
#define __MONSTER_HPP__

#include "Enemy.hpp"

class Monster : public Enemy {
   public:
        Monster();
        std::string getType() const override;
};

#endif