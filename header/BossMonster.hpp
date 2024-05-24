#ifndef __BOSS_MONSTER__HPP
#define __BOSS_MONSTER__HPP

#include "Monster.hpp"

class BossMonster : public Monster {
    private:

    public:
        BossMonster(const std::string&, int, int, double);
        void performSpecialAbility(Character&);
};

#endif