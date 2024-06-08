#ifndef __MONSTER_HPP__
#define __MONSTER_HPP__

#include "../header/Enemy.hpp"

class Monster : public Enemy {
    private:

    public:
        Monster();
        std::string getType() const override;
};

#endif