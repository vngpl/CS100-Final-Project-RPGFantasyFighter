#ifndef __ASSASSIN_HPP_
#define __ASSASSIN_HPP_

#include "Character.hpp"

class Assassin : public Character {
    public:
        Assassin();
        std::string getType() const override;
};

#endif
